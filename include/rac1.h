#ifndef _LIBGC_GC_H_
#define _LIBGC_GC_H_

/*
 * NAME :		gcPreUpdate
 * DESCRIPTION :
 * 			Must be called at the beginning of each tick.
 * NOTES :
 * ARGS : 
 * RETURN :
 * AUTHOR :
 */
void gcPreUpdate(void);

/*
 * NAME :		gcPostUpdate
 * DESCRIPTION :
 * 			Must be called at the end of each tick.
 * NOTES :
 * ARGS : 
 * RETURN :
 * AUTHOR :
 */
void gcPostUpdate(void);

#endif // _LIBGC_GC_H_
