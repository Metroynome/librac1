#ifndef _LIBRAC1_GRAPHICS_H_
#define _LIBRAC1_GRAPHICS_H_

#include <tamtypes.h>

#define SCREEN_WIDTH			(512)
#ifdef RAC1_PAL
#define SCREEN_HEIGHT			(416)
#elif RAC1_NTSCJ
#define SCREEN_HEIGHT			(416)
#else
#define SCREEN_HEIGHT			(416)
#endif

int FontSet(int font);
int FontPrint(int x, int y, u32 color, const char *string, int length);
int FontPrintLarge(int x, int y, u32 color, const char *string, int length);
int FontPrintSmall(int x, int y, u32 color, const char *string, int length);
int FontPrintCenter(int x, int y, u32 color, const char *string, int length);
int FontPrintCenterSmall(int x, int y, u32 color, const char *string, int length);
int FontPrintCenterLarge(int x, int y, u32 color, const char *string, int length);
int FontPrintWindow(void *window, u32 color, const char *string, int length, u32 font, void *fontTable);

#endif // _LIBRAC1_GRAPHICS_H_
