#include "interop.h"
#include "string.h"
#include "pad.h"

// Default value for pad history
const PadHistory DefaultPadHistory = {
    0xFFFF,
    0x7F,
    0x7F,
    0x7F,
    0x7F,
    -1
};

// Local pad history
PadHistory LocalPadHistory[PAD_PORT_MAX * 2] = {
  {0xFFFF,0x7F,0x7F,0x7F,0x7F,0},
  {0xFFFF,0x7F,0x7F,0x7F,0x7F,1},
  {0xFFFF,0x7F,0x7F,0x7F,0x7F,0},
  {0xFFFF,0x7F,0x7F,0x7F,0x7F,1},
};
    

/*
 * NAME :		padUpdate
 * DESCRIPTION :
 * 			Processes pad state, registering when a button is pressed and released.
 * NOTES :
 *          This must be called every tick in order for pad functionality to work.
 * ARGS : 
 * RETURN :
 * AUTHOR :			
 */
void padUpdate(void)
{
    // Update local pad
    memcpy(LocalPadHistory+1, LocalPadHistory+0, 6);
    memcpy(LocalPadHistory, &P1_PAD->btns, 6);
}

/*
 * NAME :		padGetButton
 * DESCRIPTION :
 * 			Returns 1 when the user is pressing the given button combination.
 *          Returns negative on failure.
 * NOTES :
 * ARGS : 
 *          port:                       Which controller port to read.
 *          buttonMask:                 Buttons to check.
 * RETURN :
 * AUTHOR :			
 */
int padGetButton(int port, u16 buttonMask)
{
    switch (port)
    {
        case 0: return (P1_PAD->btns & buttonMask) == 0;
        default: return -1;
    }
}

/*
 * NAME :		padGetButtonDown
 * DESCRIPTION :
 * 			Returns 1 during the frame that the user starts pressing the given button combination.
 *          Returns negative on failure.
 * NOTES :
 * ARGS : 
 *          port:                       Which controller port to read.
 *          buttonMask:                 Buttons to check.
 * RETURN :
 * AUTHOR :			
 */
int padGetButtonDown(int port, u16 buttonMask)
{
    if (port < 0 || port >= PAD_PORT_MAX)
        return -1;

    return (LocalPadHistory[port + 0].btns & buttonMask) == 0 &&
            (LocalPadHistory[port + 1].btns & buttonMask) != 0;
}

/*
 * NAME :		padGetButtonUp
 * DESCRIPTION :
 * 			Returns 1 during the frame that the user releases the given button combination.
 *          Returns negative on failure.
 * NOTES :
 * ARGS : 
 *          port:                       Which controller port to read.
 *          buttonMask:                 Buttons to check.
 * RETURN :
 * AUTHOR :			
 */
int padGetButtonUp(int port, u16 buttonMask)
{
    if (port < 0 || port >= PAD_PORT_MAX)
        return -1;

    return (LocalPadHistory[port + 0].btns & buttonMask) != 0 &&
        (LocalPadHistory[port + 1].btns & buttonMask) == 0;
}

/*
 * NAME :		padResetInput
 * DESCRIPTION :
 * 			Resets the given ports inputs.
 * NOTES :
 * ARGS : 
 *          port:                       Which controller port to reset.
 * RETURN :
 * AUTHOR :			
 */
void padResetInput(int port)
{
    if (port < 0 || port >= PAD_PORT_MAX)
        return;

    PAD * pad = P1_PAD;

    u64 defaultValue = 0x7F7F7F7FFFFF7900;
    *(u64*)((u32)pad + 0x00) = defaultValue;
    *(u64*)((u32)pad + 0x80) = defaultValue;
}
