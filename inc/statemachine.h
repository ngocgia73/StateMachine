#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

typedef enum 
{
	LED1_OFF_LED2_OFF,
	LED1_ON_LED2_ON,
	LED1_ON_LED2_OFF,
	LED1_OFF_LED2_ON,
	MAX_MD_STATE,
} MD_STATE;

typedef enum 
{
	COMMAND1,
	COMMAND2,
	COMMAND3,
	COMMAND4,
	MAX_MD_EVENT,
} MD_EVENT;

typedef void (* MD_ACTION) (void);

typedef struct
{
	MD_STATE nextState;
	MD_ACTION function;
} State_Element;

#endif 
