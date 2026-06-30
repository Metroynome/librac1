#ifdef RAC1_NTSCJ
#define Level (0x0015ee84)
#define gameMode (0x0015f6a8)
#define MAINMENU_DETECT_ADDR (0x0021c880)
#define MAINMENU_DETECT_WORD0 (0x0260302d)
#define MAINMENU_DETECT_WORD1 (0x2407ffff)
#define MAINMENU_DETECT_WORD2 (0x0280402d)
#define MAINMENU_DETECT_WORD3 (0x0c07e07e)
#elif RAC1_PAL
// NTSCU and PAL game globals are the same.
#define gameMode (0x0015f5c4)
#define Level (0x0015ed84)
#define MAINMENU_DETECT_ADDR (0x0021c100)
#define MAINMENU_DETECT_WORD0 (0x10540006)
#define MAINMENU_DETECT_WORD1 (0x24040001)
#define MAINMENU_DETECT_WORD2 (0x8e060014)
#define MAINMENU_DETECT_WORD3 (0x0c08b55e)
#else
#define gameMode (0x0015f5c4)
#define Level (0x0015ed84)
#define MAINMENU_DETECT_ADDR (0x0021c200)
#define MAINMENU_DETECT_WORD0 (0xfe620268)
#define MAINMENU_DETECT_WORD1 (0x02a0302d)
#define MAINMENU_DETECT_WORD2 (0x3c08003f)
#define MAINMENU_DETECT_WORD3 (0x8e690240)
#endif

#define CHECK_MAINMENU_ADDRESS(exit_label, miss_label) \
	lw $v0, MAINMENU_DETECT_ADDR; \
	li $v1, MAINMENU_DETECT_WORD0; \
	bne $v0, $v1, miss_label; \
	nop; \
	lw $v0, MAINMENU_DETECT_ADDR + 4; \
	li $v1, MAINMENU_DETECT_WORD1; \
	bne $v0, $v1, miss_label; \
	nop; \
	lw $v0, MAINMENU_DETECT_ADDR + 8; \
	li $v1, MAINMENU_DETECT_WORD2; \
	bne $v0, $v1, miss_label; \
	nop; \
	lw $v0, MAINMENU_DETECT_ADDR + 12; \
	li $v1, MAINMENU_DETECT_WORD3; \
	bne $v0, $v1, miss_label; \
	nop; \
	lw $v0, 0x0($a0); \
	b exit_label; \
	nop; \
miss_label:

// fixed address function
#define FUNCTION(name, address) \
	.set	push;		        \
	.set	noreorder;	        \
	.section	.text.##name,"ax",@progbits; \
	.align 2;		            \
	.globl	name;		        \
	.type	name,@function;	    \
	.ent	name,0;		        \
name:	j address;              \
	nop;			            \
	.end	name;		        \
	.size	name,.-name;	    \
	.set	pop;

// variable address function
#define VARIABLE_FUNCTION(name, variable_address_struct) \
	.set	push;		        				\
	.set	noreorder;	        		\
	.section	.text.##name,"ax",@progbits; \
	.align 2;		            			\
	.globl	name;		        			\
	.type	name,@function;	    		\
	.ent	name,0;		        			\
	.extern variable_address_struct; \
name:														\
		addiu $sp, $sp, -0x40;			\
		sq $ra, 0x00($sp);					\
		sq $a0, 0x10($sp);					\
		sq $a1, 0x20($sp);					\
		sq $s0, 0x30($sp);					\
		la $a0, variable_address_struct; \
		la $a1, ##name##_return;				\
		j __LocalGetAddress;        \
		nop;			            			\
##name##_return:										\
		beq $zero, $v0, ##name##_exit;	\
		nop;												\
		lq $a1, 0x20($sp);					\
		jalr $v0;										\
		lq $a0, 0x10($sp);					\
##name##_exit:											\
		lq $ra, 0x00($sp);					\
		lq $s0, 0x30($sp);					\
		jr $ra;											\
		addiu $sp, $sp, 0x40;				\
	.end	name;		        				\
	.size	name,.-name;	   			 	\
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##__LocalGetAddress,"ax",@progbits;
	.align 2;
	.globl	__LocalGetAddress;
	.type	__LocalGetAddress,@function;
	.ent	__LocalGetAddress,0;
__LocalGetAddress:
	// MainMenu is level -1 and can leave Level with a stale normal level value.
	CHECK_MAINMENU_ADDRESS(__LocalGetAddress_exit, __LocalGetAddress_not_mainmenu)

	// if GAME_MODE_NORMAL (walking, no puzzle, not paused)
	lw $v0, gameMode;
	bne $v0, $zero, __LocalGetAddress_exit;
	li $v0, 0;

	// if in menus then return lobby address
	// lw $v0, GAME_MAP_ID;
	// li $v1, 39;
	// beq $v0, $v1, __LocalGetAddress_exit;
	// lw $v0, 0($a0)

	// otherwise level loaded
	// return address by level
	lw $v0, Level;
	
	// return 0 if level is not between 0 and 18
	sltiu $v1, $v0, 19
	beqzl $v1, __LocalGetAddress_exit;
	move $v0, $zero;
	
	// load offset into VariableAddress struct by level id
	sll $v0, $v0, 2; // multiply level id [0,18] by 4
	addiu $v0, $v0, 4; // skip MainMenu entry

	// load address from struct
	addu $a0, $v0;
	lw $v0, 0($a0);

	// return to calling function
__LocalGetAddress_exit:
	jr $a1;
	nop;
	.end	__LocalGetAddress;
	.size	__LocalGetAddress,.-__LocalGetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##GetAddress,"ax",@progbits;
	.align 2;
	.globl	GetAddress;
	.type	GetAddress,@function;
	.ent	GetAddress,0;
GetAddress:
	// MainMenu is level -1 and can leave Level with a stale normal level value.
	CHECK_MAINMENU_ADDRESS(GetAddress_exit, GetAddress_not_mainmenu)

	// if GAME_MODE_NORMAL (walking, no puzzle, not paused)
	lw $v0, gameMode;
	bne $v0, $zero, GetAddress_exit;
	li $v0, 0;

	// if in menus then return lobby address
	// lw $v0, GAME_MAP_ID;
	// li $v1, 39;
	// beq $v0, $v1, GetAddress_exit;
	// lw $v0, 0($a0)

	// otherwise level loaded
	// return address by level
	lw $v0, Level;
	
	// return 0 if level is not between 0 and 18
	sltiu $v1, $v0, 19
	beqzl $v1, GetAddress_exit;
	move $v0, $zero;
	
	// load offset into VariableAddress struct by level id
	sll $v0, $v0, 2; // multiply level id [0,18] by 4
	addiu $v0, $v0, 4; // skip MainMenu entry

	// load address from struct
	addu $a0, $v0;
	lw $v0, 0($a0);

	// return to calling function
GetAddress_exit:
	jr $ra;
	nop;
	.end	GetAddress;
	.size	GetAddress,.-GetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##GetAddress,"ax",@progbits;
	.align 2;
	.globl	GetAddressImmediate;
	.type	GetAddressImmediate,@function;
	.ent	GetAddressImmediate,0;
GetAddressImmediate:
	// MainMenu is level -1 and can leave Level with a stale normal level value.
	CHECK_MAINMENU_ADDRESS(GetAddressImmediate_exit, GetAddressImmediate_not_mainmenu)

	// return address by level
	lw $v0, Level;
	
	// return 0 if level is not between 0 and 18
	sltiu $v1, $v0, 19
	beqzl $v1, GetAddressImmediate_exit;
	move $v0, $zero;
	
	// load offset into VariableAddress struct by level id
	sll $v0, $v0, 2; // multiply level id [0,18] by 4
	addiu $v0, $v0, 4; // skip MainMenu entry

	// load address from struct
	addu $a0, $v0;
	lw $v0, 0($a0);

	// return to calling function
GetAddressImmediate_exit:
	jr $ra;
	nop;
	.end	GetAddressImmediate;
	.size	GetAddressImmediate,.-GetAddressImmediate;
	.set	pop;


#--------------------------------------------------------
#------------------- STANDARD LIBRARY -------------------
#--------------------------------------------------------
#ifdef RAC1_NTSCJ
FUNCTION(printf, 0x0011c1f8)
FUNCTION(memcmp, 0x001151b4)
FUNCTION(memset, 0x001153fc)
FUNCTION(memcpy, 0x001153d4)
FUNCTION(strncpy, 0x00116808)
#else
FUNCTION(printf, 0x0011c1f8)
FUNCTION(memcmp, 0x001151b4)
FUNCTION(memset, 0x001153fc)
FUNCTION(memcpy, 0x001153d4)
FUNCTION(strncpy, 0x00116808)
#endif

#--------------------------------------------------------
#------------------- MATH ----------- -------------------
#--------------------------------------------------------
VARIABLE_FUNCTION(FontSet, vaFontSet)

VARIABLE_FUNCTION(acosf, vaFastAngleCosF)
VARIABLE_FUNCTION(asinf, vaFastAngleSinF)
VARIABLE_FUNCTION(atan2f, vaATAN2F)

#--------------------------------------------------------
#------------------- MATH3D --------- -------------------
#--------------------------------------------------------
# Rewritten matrix_to_euler exists
#VARIABLE_FUNCTION(matrix_to_euler, vaMatirx_To_Euler)
VARIABLE_FUNCTION(euler_to_matrix, vaEuler_To_Matrix)

// variable address font print function: preserves a0-a3 and t0 length arg.
#define FONT_PRINT_VARIABLE_FUNCTION(name, variable_address_struct) \
	.set	push; \
	.set	noreorder; \
	.section	.text.##name,"ax",@progbits; \
	.align 2; \
	.globl	name; \
	.type	name,@function; \
	.ent	name,0; \
	.extern variable_address_struct; \
name: \
		addiu $sp, $sp, -0x60; \
		sq $ra, 0x00($sp); \
		sq $a0, 0x10($sp); \
		sq $a1, 0x20($sp); \
		sq $a2, 0x30($sp); \
		sq $a3, 0x40($sp); \
		sq $t0, 0x50($sp); \
		la $a0, variable_address_struct; \
		la $a1, ##name##_return; \
		j __LocalGetAddress; \
		nop; \
##name##_return: \
		beq $zero, $v0, ##name##_exit; \
		nop; \
		lq $a3, 0x40($sp); \
		lq $a2, 0x30($sp); \
		lq $a1, 0x20($sp); \
		lq $a0, 0x10($sp); \
		lq $t0, 0x50($sp); \
		jalr $v0; \
		nop; \
##name##_exit: \
		lq $ra, 0x00($sp); \
		jr $ra; \
		addiu $sp, $sp, 0x60; \
	.end	name; \
	.size	name,.-name; \
	.set	pop;
#--------------------------------------------------------
#------------------- GRAPHICS ---------------------------
#--------------------------------------------------------
	.set	push;
	.set	noreorder;
	.section	.text.FontPrint,"ax",@progbits;
	.align 2;
	.globl	FontPrint;
	.type	FontPrint,@function;
	.ent	FontPrint,0;
	.extern vaFontPrint;
FontPrint:
		addiu $sp, $sp, -0x60;
		sq $ra, 0x00($sp);
		sq $a0, 0x10($sp);
		sq $a1, 0x20($sp);
		sq $a2, 0x30($sp);
		sq $a3, 0x40($sp);
		sq $t0, 0x50($sp);
		la $a0, vaFontPrint;
		la $a1, FontPrint_return;
		j __LocalGetAddress;
		nop;
FontPrint_return:
		beq $zero, $v0, FontPrint_exit;
		nop;
		lq $a3, 0x40($sp);
		lq $a2, 0x30($sp);
		lq $a1, 0x20($sp);
		lq $a0, 0x10($sp);
		lq $t0, 0x50($sp);
		jalr $v0;
		nop;
FontPrint_exit:
		lq $ra, 0x00($sp);
		jr $ra;
		addiu $sp, $sp, 0x60;
	.end	FontPrint;
	.size	FontPrint,.-FontPrint;
	.set	pop;

	.set	push;
	.set	noreorder;
	.section	.text.FontPrintWindow,"ax",@progbits;
	.align 2;
	.globl	FontPrintWindow;
	.type	FontPrintWindow,@function;
	.ent	FontPrintWindow,0;
	.extern vaFontPrintWindow;
FontPrintWindow:
		addiu $sp, $sp, -0x70;
		sq $ra, 0x00($sp);
		sq $a0, 0x10($sp);
		sq $a1, 0x20($sp);
		sq $a2, 0x30($sp);
		sq $a3, 0x40($sp);
		sq $t0, 0x50($sp);
		sq $t1, 0x60($sp);
		la $a0, vaFontPrintWindow;
		la $a1, FontPrintWindow_return;
		j __LocalGetAddress;
		nop;
FontPrintWindow_return:
		beq $zero, $v0, FontPrintWindow_exit;
		nop;
		lq $a3, 0x40($sp);
		lq $a2, 0x30($sp);
		lq $a1, 0x20($sp);
		lq $a0, 0x10($sp);
		lq $t0, 0x50($sp);
		lq $t1, 0x60($sp);
		jalr $v0;
		nop;
FontPrintWindow_exit:
		lq $ra, 0x00($sp);
		jr $ra;
		addiu $sp, $sp, 0x70;
	.end	FontPrintWindow;
	.size	FontPrintWindow,.-FontPrintWindow;
	.set	pop;
FONT_PRINT_VARIABLE_FUNCTION(FontPrintLarge, vaFontPrintLarge)
FONT_PRINT_VARIABLE_FUNCTION(FontPrintSmall, vaFontPrintSmall)
FONT_PRINT_VARIABLE_FUNCTION(FontPrintCenter, vaFontPrintCenter)
FONT_PRINT_VARIABLE_FUNCTION(FontPrintCenterSmall, vaFontPrintCenterSmall)
FONT_PRINT_VARIABLE_FUNCTION(FontPrintCenterLarge, vaFontPrintCenterLarge)
#--------------------------------------------------------
#------------------- CAMERA --------- -------------------
#--------------------------------------------------------
VARIABLE_FUNCTION(cameraSetFollowDistance, vaCam_SetFollowDistance)
VARIABLE_FUNCTION(cameraSetFollowAngleOrOffset, vaCam_SetFollowAngleOrOffset)
VARIABLE_FUNCTION(cameraSetElevation, vaCam_SetElevation)
VARIABLE_FUNCTION(cameraSetFollowMode, vaCam_SetFollowMode)
VARIABLE_FUNCTION(cameraSetFollowSmoothing, vaCam_SetFollowSmoothing)
VARIABLE_FUNCTION(cameraEnableBlendMode, vaCam_EnableBlendMode)