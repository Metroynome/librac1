#include "rac1.h"
#include "player.h"

// 
extern void padUpdate(void);
extern void playerPadUpdate(void);

/*
 * NAME :		gcPreUpdate
 * DESCRIPTION :
 * 			Must be called at the beginning of each tick.
 * NOTES :
 * ARGS : 
 * RETURN :
 * AUTHOR :
 */
void racPreUpdate(void)
{
		
}

/*
 * NAME :		gcPostUpdate
 * DESCRIPTION :
 * 			Must be called at the end of each tick.
 * NOTES :
 * ARGS : 
 * RETURN :
 * AUTHOR :
 */
void racPostUpdate(void)
{
	padUpdate();
	playerPadUpdate();
}
