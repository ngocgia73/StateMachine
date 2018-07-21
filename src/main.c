#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "unistd.h"

#include "statemachine.h"
#include "handle.h"

pthread_t command_thread;
pthread_mutex_t cmd_mutex = PTHREAD_MUTEX_INITIALIZER; 
void *command_thread_result;
int condition = 1;	
MD_STATE nextState = LED1_OFF_LED2_OFF;
MD_EVENT new_event = MAX_MD_EVENT;
MD_EVENT pre_event = MAX_MD_EVENT;

static State_Element gstate_Table[MAX_MD_STATE][MAX_MD_EVENT] = 
{
	{
		{COMMAND1, turnoff2led},
		// add here
	},
	{
		{COMMAND2, NULL},
		{COMMAND2, turnon2led},
		// add here
	},
	{
		{COMMAND3, NULL},
		{COMMAND3, NULL},
		{COMMAND3, led1onled2off},
		// add here
	},
	{
		{COMMAND4, NULL},
		{COMMAND4, NULL},
		{COMMAND4, NULL},
		{COMMAND4,led1offled2on}
		// add here
	}
};

static MD_EVENT get_event()
{
	return new_event;
}

static void set_event(MD_EVENT event)
{
	pthread_mutex_lock(&cmd_mutex);
	new_event = event;
	pthread_mutex_unlock(&cmd_mutex);
}

/*
 *  handle switch state machine
 *
 */
void* command_handle(void *argv)
{
	int i;
	// do something
	for(i =0; i< MAX_MD_EVENT; i++)
	{
		set_event(i);
		sleep(1);
	}
	condition = 0 ;
	return EXIT_SUCCESS;
}

int main(int argc , char **argv)
{
	int ret = 0;
	MD_ACTION function;

	if (pthread_create(&command_thread, NULL, command_handle, NULL) != 0)
	{
		fprintf(stderr, "can not start command thread\n");
		ret = -1;
	}
	while(condition)
	{
		pthread_mutex_lock(&cmd_mutex);
		new_event = get_event();
		pthread_mutex_unlock(&cmd_mutex);
		if(pre_event != new_event)
		{
			// need re-update all value to  handle state machine
			fprintf(stdout,"===nextstate = %d, new_event = %d===\n",nextState,new_event);
		}
		if(new_event < MAX_MD_EVENT)
		{
			function = gstate_Table[nextState][new_event].function;
			if(function != NULL)
				function();
		}
		pre_event = new_event;
	}
	fprintf(stdout,"waiting for command thread finish\n");
	ret = pthread_join(command_thread, &command_thread_result);
	if(ret != 0)
	{
		fprintf(stderr, "wait error\n");
		ret = -2;
	}
	return ret;
}
