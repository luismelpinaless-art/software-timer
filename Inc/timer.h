#ifndef AR_OS_TIMER_H
#define AR_OS_TIMER_H
#include "stdbool.h"
#include "stdint.h"


typedef enum{
EVT_TIMER_IDLE,
EVT_TIMER_DONE
}TIMER_EVT;

typedef struct{
uint32_t counter;
uint32_t limit;
bool active;
bool mode;
volatile bool period_reached;
TIMER_EVT event;
}TIMER;

void timer_init(TIMER *tm, uint32_t limit, bool mod);
void timer_set(TIMER *tm);
void timer_reset(TIMER *tm);
void timer_update(TIMER *tm);

#endif
