# Embedded Software Timer
Software timer library in C for embedded systems.

## Status 
- v1.0.0 - One_shot
- v1.1.0 - AR_timer
- v1.2.0 - AR_OS_timer
- 1.2.1  - Timer
  
## Design decisions
- 'period_reached' is a volatile variable because it is manipulated by an external interrupt (HAL Callback).
- Once the one-shot timer reaches its limit, the counter resets.
- The AR_timer generates "EVT_TIMER_DONE" every time the timer expires.
- The AR_OS_timer implements NULL pointer verification and "period-reached" is cleared on every timer_update() call regardless of the mode.

## Roadmap
- [x] One_shot timer
- [x] Auto Reload timer
- [x] AR/OS modes (Auto Reload mode, one_shot mode)
- [ ] Time stamps timer + function pointer
- [ ] Time manager + callbacks
