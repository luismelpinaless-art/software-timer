# Embedded Software Timer

Software timer library in C for embedded systems.

## Purpose

Most embedded firmware needs to wait, repeat or time things without stopping the rest of the program. This library turns a single hardware tick into any number of independent software timers, so the main loop can react to time passing instead of blocking on it.

## Design principles

- **Instantiable as many times as needed.** All state lives inside a struct and every function receives a pointer to it, so there is no global state. Create as many timers as you need, each one fully independent.
- **Plain C, hardware-agnostic.** The library never touches registers directly. The only hardware dependency is a tick coming from a HAL callback, so the timer logic is identical on any microcontroller.

## Status
- v1.0.0 - One_shot
- v1.1.0 - AR_timer
- v1.2.0 - AR_OS_timer
- v1.2.1 - Timer

## Design decisions
- `period_reached` is a volatile variable because it is manipulated by an external interrupt (HAL callback). The interrupt only raises the flag; `timer_update()` runs in the main loop and consumes it, so the rest of the timer state is modified from a single context.
- `period_reached` is cleared on every `timer_update()` call, regardless of the mode and even if the timer is inactive, so a re-armed timer never starts with a stale tick.
- The AR_timer generates `EVT_TIMER_DONE` every time the timer expires and keeps running on its own.
- Once the one-shot timer reaches its limit, the counter resets and `EVT_TIMER_DONE` stays latched until the timer is cleared with `timer_reset()`, so other modules can observe it.
- `timer_reset()` leaves the timer clean (counter and event cleared), so a reset followed by `timer_set()` always restarts from zero.
- Timers start active by default.
- The AR_OS_timer implements NULL pointer verification in every function.

## Roadmap
- [x] One_shot timer
- [x] Auto Reload timer
- [x] AR/OS modes (Auto Reload mode, one_shot mode)
- [ ] Time stamps timer + function pointer
- [ ] Time manager + callbacks
