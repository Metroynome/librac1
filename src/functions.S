#ifdef RAC1_NTSCJ
#define gameMode (0x0015f6c4)
#define Level (0x0015ee84)
#else
// NTSCU and PAL are the same
#define gameMode (0x0015f5c4)
#define Level (0x0015ed84)
#endif

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
	sll $v0, $v0, 2; // multiply level id [0,9] by 4
	// offset by 4 to skip lobby address
	// addiu $v0, $v1, 4;

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
	sll $v0, $v0, 2; // multiply level id [0,9] by 4
	// offset by 4 to skip lobby address
	// addiu $v0, $v1, 4;

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
	// return address by level
	lw $v0, Level;
	
	// return 0 if level is not between 0 and 18
	sltiu $v1, $v0, 19
	beqzl $v1, GetAddressImmediate_exit;
	move $v0, $zero;
	
	// load offset into VariableAddress struct by level id
	sll $v0, $v0, 2; // multiply level id [0,9] by 4
	// offset by 4 to skip lobby address
	// addiu $v0, $v1, 4;

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
VARIABLE_FUNCTION(acosf, vaFastAngleCosF)
VARIABLE_FUNCTION(asinf, vaFastAngleSinF)