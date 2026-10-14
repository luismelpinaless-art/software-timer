#include <timer.h>

void timer_init(TIMER *tm, uint32_t limit, bool mod){
if(tm == NULL){
	return;
}

tm->counter = 0;
tm->limit = limit;
tm->active = false;
tm->mode = mod;
tm->period_reached = false;
tm->event = EVT_TIMER_IDLE;
}

void timer_set(TIMER *tm){
if(tm == NULL){
	return;
}

if(tm->active == false){
	tm->active = true;
	}
}

void timer_reset(TIMER *tm){
if(tm == NULL){
	return;
}
if(tm->active == true){
	tm->active = false;
	tm->counter = 0;
	tm->event = EVT_TIMER_IDLE;
	tm->period_reached = false;
	}
}

void timer_update(TIMER *tm){
if(tm == NULL){
	return;
}

if(tm->period_reached == true){
	tm->period_reached = false;
}

if(tm->active == false){
	return;
}

if(tm->mode == true){
	if(tm->event == EVT_TIMER_DONE){
		tm->event = EVT_TIMER_IDLE;
	}
}

if(tm->mode == false){
	tm->event = EVT_TIMER_DONE;
	tm->counter = 0;
}

if(tm->counter < tm->limit){
	tm->counter++;
}

if(tm->counter >= tm->limit){
	tm->counter = 0;
	tm->event = EVT_TIMER_DONE;
	}
}
