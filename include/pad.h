/***************************************************
 * FILENAME :		pad.h
 * DESCRIPTION :
 * 		Contains pad specific offsets and structures for UYA.
 * NOTES :
 * AUTHOR :			
 */

/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

#ifndef _LIBRAC1_PAD_H
#define _LIBRAC1_PAD_H

#include <tamtypes.h>
#include "types.h"

#ifdef RAC1_PAL_V200
#define P1_PAD                              ((PAD*)0x0013ca40)
#elif RAC1_PAL
#define P1_PAD                              ((PAD*)0x0013c940)
#elif RAC1_NTSCJ
#define P1_PAD                              ((PAD*)0x0013ca40)
#else
#define P1_PAD                              ((PAD*)0x0013c940)
#endif

#define REVERSE_U16(bytes) (bytes >> 8) | (bytes << 8) 

#define PAD_PORT_MAX        1

#define PAD_LEFT            0x0080
#define PAD_DOWN            0x0040
#define PAD_RIGHT           0x0020
#define PAD_UP              0x0010
#define PAD_START           0x0008
#define PAD_R3              0x0004
#define PAD_L3              0x0002
#define PAD_SELECT          0x0001
#define PAD_SQUARE          0x8000
#define PAD_CROSS           0x4000
#define PAD_CIRCLE          0x2000
#define PAD_TRIANGLE        0x1000
#define PAD_R1              0x0800
#define PAD_L1              0x0400
#define PAD_R2              0x0200
#define PAD_L2              0x0100

typedef struct PAD { // RC1 - 0x39C bytes
    union {
    /* 0x000 */ u128 pad_buf[16];
            struct {
                unsigned char ok;
                unsigned char mode;
                unsigned short btns;
                unsigned char rjoy_h;
                unsigned char rjoy_v;
                unsigned char ljoy_h;
                unsigned char ljoy_v;
                unsigned char right_p;
                unsigned char left_p;
                unsigned char up_p;
                unsigned char down_p;
                unsigned char triangle_p;
                unsigned char circle_p;
                unsigned char cross_p;
                unsigned char square_p;
                unsigned char l1_p;
                unsigned char r1_p;
                unsigned char l2_p;
                unsigned char r2_p;
            };
    };
    /* 0x100 */ float analog[16];
    /* 0x140 */ float hudAnalog[16];
    /* 0x180 */ unsigned char profile[4];
    /* 0x184 */ unsigned char vib_profile[4];
    /* 0x188 */ unsigned char act_direct[4];
    /* 0x18c */ short int invalidTimer;
    /* 0x18e */ short int ringIndex;
    /* 0x190 */ int ringValidSize;
    /* 0x194 */ int socket;
    /* 0x198 */ int phase;
    /* 0x19c */ int state;
    /* 0x1a0 */ int bits;
    /* 0x1a4 */ int bitsOn;
    /* 0x1a8 */ int bitsOff;
    /* 0x1ac */ int bitsPrev;
    /* 0x1b0 */ int digitalBits;
    /* 0x1b4 */ int digitalBitsOn;
    /* 0x1b8 */ int digitalBitsOff;
    /* 0x1bc */ int digitalBitsPrev;
    /* 0x1c0 */ int hudBits;
    /* 0x1c4 */ int hudBitsOn;
    /* 0x1c8 */ int hudBitsOff;
    /* 0x1cc */ int hudDivert;
    /* 0x1d0 */ int handsOff;
    /* 0x1d4 */ int handsOffStick;
    /* 0x1d8 */ int useAnalog;
    /* 0x1dc */ int term_id;
    /* 0x1e0 */ int bitsOnRing[30];
    /* 0x258 */ float analogAngRing[30];
    /* 0x2d0 */ float analogMagRing[30];
    /* 0x348 */ int unmaskedBits;
    /* 0x34c */ u8 port;
    /* 0x34d */ u8 repeatDelay;
    /* 0x34e */ u8 repeatSpeed;
    /* 0x34f */ u8 repeatCounter;
    /* 0x350 */ u8 multi_tap_connected;
    /* 0x351 */ u8 disconnected;
    /* 0x352 */ u8 act_align[6];
    /* 0x358 */ u8 slot;
    /* 0x359 */ char initialized;
    /* 0x35a */ u8 _pad[2];
    /* 0x35c */ int rterm_id;
    /* 0x360 */ int id;
    /* 0x364 */ int exid;
    /* 0x368 */ int lagFrames;
    /* 0x36c */ void *RawPadInputCallback;
    /* 0x370 */ void *pCallbackData;
    /* 0x374 */ u8 rdata[32];
    /* 0x394 */ int ipad[10];
} PAD;

typedef struct padButtonStatus {
    unsigned char ok;
    unsigned char mode;
    unsigned short btns;
    // joysticks
    unsigned char rjoy_h;
    unsigned char rjoy_v;
    unsigned char ljoy_h;
    unsigned char ljoy_v;
    // pressure mode
    unsigned char right_p;
    unsigned char left_p;
    unsigned char up_p;
    unsigned char down_p;
    unsigned char triangle_p;
    unsigned char circle_p;
    unsigned char cross_p;
    unsigned char square_p;
    unsigned char l1_p;
    unsigned char r1_p;
    unsigned char l2_p;
    unsigned char r2_p;
} PadButtonStatus;

typedef struct PadHistory {
    u16 btns;
    u8 rjoy_h;
    u8 rjoy_v;
    u8 ljoy_h;
    u8 ljoy_v;
    short id;
} PadHistory;

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
__LIBRAC1_GETTER__ int padGetButton(int port, u16 buttonMask);

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
__LIBRAC1_GETTER__ int padGetButtonDown(int port, u16 buttonMask);

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
__LIBRAC1_GETTER__ int padGetButtonUp(int port, u16 buttonMask);

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
__LIBRAC1_SETTER__ void padResetInput(int port);

#endif // _LIBRAC1_PAD_H
