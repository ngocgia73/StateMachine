#include "stdio.h"
#include "handle.h"

#include "statemachine.h"

extern MD_STATE nextState;
void turnoff2led(void)
{
	fprintf(stdout,"===led1 => off: led2 => off ===\n");
	nextState = LED1_ON_LED2_ON;
}

void turnon2led(void)
{

	fprintf(stdout,"===led1 => on: led2 => on ===\n");
	nextState = LED1_ON_LED2_OFF;
}

void led1onled2off(void)
{

	fprintf(stdout,"===led1 => on: led2 => off ===\n");
	nextState = LED1_OFF_LED2_ON;
}

void led1offled2on(void)
{

	fprintf(stdout,"===led1 => off: led2 => on ===\n");
	nextState = LED1_OFF_LED2_OFF;
}


