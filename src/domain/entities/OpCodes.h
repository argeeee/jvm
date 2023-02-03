#pragma once

enum OpCodes {
	Op_aaload						= 0x32, //	0011 0010		arrayref, index → value	load onto the stack a reference from an array
	Op_aastore					= 0x53, //	0101 0011		arrayref, index, value →	store a reference in an array
	Op_aconst_null			= 0x01, //	0000 0001		→ null	push a null reference onto the stack
	Op_aload						= 0x19, //	0001 1001	1: index	→ objectref	load a reference onto the stack from a local variable #index
	Op_aload_0					= 0x2a, //	0010 1010		→ objectref	load a reference onto the stack from local variable 0
	Op_aload_1					= 0x2b, //	0010 1011		→ objectref	load a reference onto the stack from local variable 1
	Op_aload_2					= 0x2c, //	0010 1100		→ objectref	load a reference onto the stack from local variable 2
	Op_aload_3					= 0x2d, //	0010 1101		→ objectref	load a reference onto the stack from local variable 3
	Op_anewarray				= 0xbd, //	1011 1101	2: indexbyte1, indexbyte2	count → arrayref	create a new array of references of length count and component type identified by the class reference index (indexbyte1 << 8 | indexbyte2) in the constant pool
	Op_areturn					= 0xb0, //	1011 0000		objectref → [empty]	return a reference from a method
	Op_arraylength			= 0xbe, //	1011 1110		arrayref → length	get the length of an array
	Op_astore						= 0x3a, //	0011 1010	1: index	objectref →	store a reference into a local variable #index
	Op_astore_0					= 0x4b, //	0100 1011		objectref →	store a reference into local variable 0
	Op_astore_1					= 0x4c, //	0100 1100		objectref →	store a reference into local variable 1
	Op_astore_2					= 0x4d, //	0100 1101		objectref →	store a reference into local variable 2
	Op_astore_3					= 0x4e, //	0100 1110		objectref →	store a reference into local variable 3
	Op_athrow						= 0xbf, //	1011 1111		objectref → [empty], objectref	throws an error or exception (notice that the rest of the stack is cleared, leaving only a reference to the Throwable)
	Op_baload						= 0x33, //	0011 0011		arrayref, index → value	load a byte or Boolean value from an array
	Op_bastore					= 0x54, //	0101 0100		arrayref, index, value →	store a byte or Boolean value into an array
	Op_bipush						= 0x10, //	0001 0000	1: byte	→ value	push a byte onto the stack as an integer value
	Op_breakpoint				= 0xca, //	1100 1010			reserved for breakpoints in Java debuggers; should not appear in any class file
	Op_caload						= 0x34, //	0011 0100		arrayref, index → value	load a char from an array
	Op_castore					= 0x55, //	0101 0101		arrayref, index, value →	store a char into an array
	Op_checkcast				= 0xc0, //	1100 0000	2: indexbyte1, indexbyte2	objectref → objectref	checks whether an objectref is of a certain type, the class reference of which is in the constant pool at index (indexbyte1 << 8 | indexbyte2)
	Op_d2f							= 0x90, //	1001 0000		value → result	convert a double to a float
	Op_d2i							= 0x8e, //	1000 1110		value → result	convert a double to an int
	Op_d2l							= 0x8f, //	1000 1111		value → result	convert a double to a long
	Op_dadd							= 0x63, //	0110 0011		value1, value2 → result	add two doubles
	Op_daload						= 0x31, //	0011 0001		arrayref, index → value	load a double from an array
	Op_dastore					= 0x52, //	0101 0010		arrayref, index, value →	store a double into an array
	Op_dcmpg						= 0x98, //	1001 1000		value1, value2 → result	compare two doubles, 1 on NaN
	Op_dcmpl						= 0x97, //	1001 0111		value1, value2 → result	compare two doubles, -1 on NaN
	Op_dconst_0					= 0x0e, //	0000 1110		→ 0.0	push the constant 0.0 (a double) onto the stack
	Op_dconst_1					= 0x0f, //	0000 1111		→ 1.0	push the constant 1.0 (a double) onto the stack
	Op_ddiv							= 0x6f, //	0110 1111		value1, value2 → result	divide two doubles
	Op_dload						= 0x18, //	0001 1000	1: index	→ value	load a double value from a local variable #index
	Op_dload_0					= 0x26, //	0010 0110		→ value	load a double from local variable 0
	Op_dload_1					= 0x27, //	0010 0111		→ value	load a double from local variable 1
	Op_dload_2					= 0x28, //	0010 1000		→ value	load a double from local variable 2
	Op_dload_3					= 0x29, //	0010 1001		→ value	load a double from local variable 3
	Op_dmul							= 0x6b, //	0110 1011		value1, value2 → result	multiply two doubles
	Op_dneg							= 0x77, //	0111 0111		value → result	negate a double
	Op_drem							= 0x73, //	0111 0011		value1, value2 → result	get the remainder from a division between two doubles
	Op_dreturn					= 0xaf, //	1010 1111		value → [empty]	return a double from a method
	Op_dstore						= 0x39, //	0011 1001	1: index	value →	store a double value into a local variable #index
	Op_dstore_0					= 0x47, //	0100 0111		value →	store a double into local variable 0
	Op_dstore_1					= 0x48, //	0100 1000		value →	store a double into local variable 1
	Op_dstore_2					= 0x49, //	0100 1001		value →	store a double into local variable 2
	Op_dstore_3					= 0x4a, //	0100 1010		value →	store a double into local variable 3
	Op_dsub							= 0x67, //	0110 0111		value1, value2 → result	subtract a double from another
	Op_dup							= 0x59, //	0101 1001		value → value, value	duplicate the value on top of the stack
	Op_dup_x1						= 0x5a, //	0101 1010		value2, value1 → value1, value2, value1	insert a copy of the top value into the stack two values from the top. value1 and value2 must not be of the type double or long.
	Op_dup_x2						= 0x5b, //	0101 1011		value3, value2, value1 → value1, value3, value2, value1	insert a copy of the top value into the stack two (if value2 is double or long it takes up the entry of value3, too) or three values (if value2 is neither double nor long) from the top
	Op_dup2							= 0x5c, //	0101 1100		{value2, value1} → {value2, value1}, {value2, value1}	duplicate top two stack words (two values, if value1 is not double nor long; a single value, if value1 is double or long)
	Op_dup2_x1					= 0x5d, //	0101 1101		value3, {value2, value1} → {value2, value1}, value3, {value2, value1}	duplicate two words and insert beneath third word (see explanation above)
	Op_dup2_x2					= 0x5e, //	0101 1110		{value4, value3}, {value2, value1} → {value2, value1}, {value4, value3}, {value2, value1}	duplicate two words and insert beneath fourth word
	Op_f2d							= 0x8d, //	1000 1101		value → result	convert a float to a double
	Op_f2i							= 0x8b, //	1000 1011		value → result	convert a float to an int
	Op_f2l							= 0x8c, //	1000 1100		value → result	convert a float to a long
	Op_fadd							= 0x62, //	0110 0010		value1, value2 → result	add two floats
	Op_faload						= 0x30, //	0011 0000		arrayref, index → value	load a float from an array
	Op_fastore					= 0x51, //	0101 0001		arrayref, index, value →	store a float in an array
	Op_fcmpg						= 0x96, //	1001 0110		value1, value2 → result	compare two floats, 1 on NaN
	Op_fcmpl						= 0x95, //	1001 0101		value1, value2 → result	compare two floats, -1 on NaN
	Op_fconst_0					= 0x0b, //	0000 1011		→ 0.0f	push 0.0f on the stack
	Op_fconst_1					= 0x0c, //	0000 1100		→ 1.0f	push 1.0f on the stack
	Op_fconst_2					= 0x0d, //	0000 1101		→ 2.0f	push 2.0f on the stack
	Op_fdiv							= 0x6e, //	0110 1110		value1, value2 → result	divide two floats
	Op_fload						= 0x17, //	0001 0111	1: index	→ value	load a float value from a local variable #index
	Op_fload_0					= 0x22, //	0010 0010		→ value	load a float value from local variable 0
	Op_fload_1					= 0x23, //	0010 0011		→ value	load a float value from local variable 1
	Op_fload_2					= 0x24, //	0010 0100		→ value	load a float value from local variable 2
	Op_fload_3					= 0x25, //	0010 0101		→ value	load a float value from local variable 3
	Op_fmul							= 0x6a, //	0110 1010		value1, value2 → result	multiply two floats
	Op_fneg							= 0x76, //	0111 0110		value → result	negate a float
	Op_frem							= 0x72, //	0111 0010		value1, value2 → result	get the remainder from a division between two floats
	Op_freturn					= 0xae, //	1010 1110		value → [empty]	return a float
	Op_fstore						= 0x38, //	0011 1000	1: index	value →	store a float value into a local variable #index
	Op_fstore_0					= 0x43, //	0100 0011		value →	store a float value into local variable 0
	Op_fstore_1					= 0x44, //	0100 0100		value →	store a float value into local variable 1
	Op_fstore_2					= 0x45, //	0100 0101		value →	store a float value into local variable 2
	Op_fstore_3					= 0x46, //	0100 0110		value →	store a float value into local variable 3
	Op_fsub							= 0x66, //	0110 0110		value1, value2 → result	subtract two floats
	Op_getfield					= 0xb4, //	1011 0100	2: indexbyte1, indexbyte2	objectref → value	get a field value of an object objectref, where the field is identified by field reference in the constant pool index (indexbyte1 << 8 | indexbyte2)
	Op_getstatic				= 0xb2, //	1011 0010	2: indexbyte1, indexbyte2	→ value	get a static field value of a class, where the field is identified by field reference in the constant pool index (indexbyte1 << 8 | indexbyte2)
	Op_goto							= 0xa7, //	1010 0111	2: branchbyte1, branchbyte2	[no change]	goes to another instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_goto_w						= 0xc8, //	1100 1000	4: branchbyte1, branchbyte2, branchbyte3, branchbyte4	[no change]	goes to another instruction at branchoffset (signed int constructed from unsigned bytes branchbyte1 << 24 | branchbyte2 << 16 | branchbyte3 << 8 | branchbyte4)
	Op_i2b							= 0x91, //	1001 0001		value → result	convert an int into a byte
	Op_i2c							= 0x92, //	1001 0010		value → result	convert an int into a character
	Op_i2d							= 0x87, //	1000 0111		value → result	convert an int into a double
	Op_i2f							= 0x86, //	1000 0110		value → result	convert an int into a float
	Op_i2l							= 0x85, //	1000 0101		value → result	convert an int into a long
	Op_i2s							= 0x93, //	1001 0011		value → result	convert an int into a short
	Op_iadd							= 0x60, //	0110 0000		value1, value2 → result	add two ints
	Op_iaload						= 0x2e, //	0010 1110		arrayref, index → value	load an int from an array
	Op_iand							= 0x7e, //	0111 1110		value1, value2 → result	perform a bitwise AND on two integers
	Op_iastore					= 0x4f, //	0100 1111		arrayref, index, value →	store an int into an array
	Op_iconst_m1				= 0x02, //	0000 0010		→ -1	load the int value −1 onto the stack
	Op_iconst_0					= 0x03, //	0000 0011		→ 0	load the int value 0 onto the stack
	Op_iconst_1					= 0x04, //	0000 0100		→ 1	load the int value 1 onto the stack
	Op_iconst_2					= 0x05, //	0000 0101		→ 2	load the int value 2 onto the stack
	Op_iconst_3					= 0x06, //	0000 0110		→ 3	load the int value 3 onto the stack
	Op_iconst_4					= 0x07, //	0000 0111		→ 4	load the int value 4 onto the stack
	Op_iconst_5					= 0x08, //	0000 1000		→ 5	load the int value 5 onto the stack
	Op_idiv							= 0x6c, //	0110 1100		value1, value2 → result	divide two integers
	Op_if_acmpeq				= 0xa5, //	1010 0101	2: branchbyte1, branchbyte2	value1, value2 →	if references are equal, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_acmpne				= 0xa6, //	1010 0110	2: branchbyte1, branchbyte2	value1, value2 →	if references are not equal, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_icmpeq				= 0x9f, //	1001 1111	2: branchbyte1, branchbyte2	value1, value2 →	if ints are equal, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_icmpge				= 0xa2, //	1010 0010	2: branchbyte1, branchbyte2	value1, value2 →	if value1 is greater than or equal to value2, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_icmpgt				= 0xa3, //	1010 0011	2: branchbyte1, branchbyte2	value1, value2 →	if value1 is greater than value2, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_icmple				= 0xa4, //	1010 0100	2: branchbyte1, branchbyte2	value1, value2 →	if value1 is less than or equal to value2, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_icmplt				= 0xa1, //	1010 0001	2: branchbyte1, branchbyte2	value1, value2 →	if value1 is less than value2, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_if_icmpne				= 0xa0, //	1010 0000	2: branchbyte1, branchbyte2	value1, value2 →	if ints are not equal, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifeq							= 0x99, //	1001 1001	2: branchbyte1, branchbyte2	value →	if value is 0, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifge							= 0x9c, //	1001 1100	2: branchbyte1, branchbyte2	value →	if value is greater than or equal to 0, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifgt							= 0x9d, //	1001 1101	2: branchbyte1, branchbyte2	value →	if value is greater than 0, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifle							= 0x9e, //	1001 1110	2: branchbyte1, branchbyte2	value →	if value is less than or equal to 0, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_iflt							= 0x9b, //	1001 1011	2: branchbyte1, branchbyte2	value →	if value is less than 0, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifne							= 0x9a, //	1001 1010	2: branchbyte1, branchbyte2	value →	if value is not 0, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifnonnull				= 0xc7, //	1100 0111	2: branchbyte1, branchbyte2	value →	if value is not null, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_ifnull						= 0xc6, //	1100 0110	2: branchbyte1, branchbyte2	value →	if value is null, branch to instruction at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2)
	Op_iinc							= 0x84, //	1000 0100	2: index, const	[No change]	increment local variable #index by signed byte const
	Op_iload						= 0x15, //	0001 0101	1: index	→ value	load an int value from a local variable #index
	Op_iload_0					= 0x1a, //	0001 1010		→ value	load an int value from local variable 0
	Op_iload_1					= 0x1b, //	0001 1011		→ value	load an int value from local variable 1
	Op_iload_2					= 0x1c, //	0001 1100		→ value	load an int value from local variable 2
	Op_iload_3					= 0x1d, //	0001 1101		→ value	load an int value from local variable 3
	Op_impdep1					= 0xfe, //	1111 1110			reserved for implementation-dependent operations within debuggers; should not appear in any class file
	Op_impdep2					= 0xff, //	1111 1111			reserved for implementation-dependent operations within debuggers; should not appear in any class file
	Op_imul							= 0x68, //	0110 1000		value1, value2 → result	multiply two integers
	Op_ineg							= 0x74, //	0111 0100		value → result	negate int
	Op_instanceof				= 0xc1, //	1100 0001	2: indexbyte1, indexbyte2	objectref → result	determines if an object objectref is of a given type, identified by class reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_invokedynamic		= 0xba, //	1011 1010	4: indexbyte1, indexbyte2, 0, 0	[arg1, arg2, ...] → result	invokes a dynamic method and puts the result on the stack (might be void); the method is identified by method reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_invokeinterface	= 0xb9, //	1011 1001	4: indexbyte1, indexbyte2, count, 0	objectref, [arg1, arg2, ...] → result	invokes an interface method on object objectref and puts the result on the stack (might be void); the interface method is identified by method reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_invokespecial		= 0xb7, //	1011 0111	2: indexbyte1, indexbyte2	objectref, [arg1, arg2, ...] → result	invoke instance method on object objectref and puts the result on the stack (might be void); the method is identified by method reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_invokestatic			= 0xb8, //	1011 1000	2: indexbyte1, indexbyte2	[arg1, arg2, ...] → result	invoke a static method and puts the result on the stack (might be void); the method is identified by method reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_invokevirtual		= 0xb6, //	1011 0110	2: indexbyte1, indexbyte2	objectref, [arg1, arg2, ...] → result	invoke virtual method on object objectref and puts the result on the stack (might be void); the method is identified by method reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_ior							= 0x80, //	1000 0000		value1, value2 → result	bitwise int OR
	Op_irem							= 0x70, //	0111 0000		value1, value2 → result	logical int remainder
	Op_ireturn					= 0xac, //	1010 1100		value → [empty]	return an integer from a method
	Op_ishl							= 0x78, //	0111 1000		value1, value2 → result	int shift left
	Op_ishr							= 0x7a, //	0111 1010		value1, value2 → result	int arithmetic shift right
	Op_istore						= 0x36, //	0011 0110	1: index	value →	store int value into variable #index
	Op_istore_0					= 0x3b, //	0011 1011		value →	store int value into variable 0
	Op_istore_1					= 0x3c, //	0011 1100		value →	store int value into variable 1
	Op_istore_2					= 0x3d, //	0011 1101		value →	store int value into variable 2
	Op_istore_3					= 0x3e, //	0011 1110		value →	store int value into variable 3
	Op_isub							= 0x64, //	0110 0100		value1, value2 → result	int subtract
	Op_iushr						= 0x7c, //	0111 1100		value1, value2 → result	int logical shift right
	Op_ixor							= 0x82, //	1000 0010		value1, value2 → result	int xor
	Op_jsr							= 0xa8, //	1010 1000	2: branchbyte1, branchbyte2	→ address	jump to subroutine at branchoffset (signed short constructed from unsigned bytes branchbyte1 << 8 | branchbyte2) and place the return address on the stack
	Op_jsr_w						= 0xc9, //	1100 1001	4: branchbyte1, branchbyte2, branchbyte3, branchbyte4	→ address	jump to subroutine at branchoffset (signed int constructed from unsigned bytes branchbyte1 << 24 | branchbyte2 << 16 | branchbyte3 << 8 | branchbyte4) and place the return address on the stack
	Op_l2d							= 0x8a, //	1000 1010		value → result	convert a long to a double
	Op_l2f							= 0x89, //	1000 1001		value → result	convert a long to a float
	Op_l2i							= 0x88, //	1000 1000		value → result	convert a long to a int
	Op_ladd							= 0x61, //	0110 0001		value1, value2 → result	add two longs
	Op_laload						= 0x2f, //	0010 1111		arrayref, index → value	load a long from an array
	Op_land							= 0x7f, //	0111 1111		value1, value2 → result	bitwise AND of two longs
	Op_lastore					= 0x50, //	0101 0000		arrayref, index, value →	store a long to an array
	Op_lcmp							= 0x94, //	1001 0100		value1, value2 → result	push 0 if the two longs are the same, 1 if value1 is greater than value2, -1 otherwise
	Op_lconst_0					= 0x09, //	0000 1001		→ 0L	push 0L (the number zero with type long) onto the stack
	Op_lconst_1					= 0x0a, //	0000 1010		→ 1L	push 1L (the number one with type long) onto the stack
	Op_ldc							= 0x12, //	0001 0010	1: index	→ value	push a constant #index from a constant pool (String, int, float, Class, java.lang.invoke.MethodType, java.lang.invoke.MethodHandle, or a dynamically-computed constant) onto the stack
	Op_ldc_w						= 0x13, //	0001 0011	2: indexbyte1, indexbyte2	→ value	push a constant #index from a constant pool (String, int, float, Class, java.lang.invoke.MethodType, java.lang.invoke.MethodHandle, or a dynamically-computed constant) onto the stack (wide index is constructed as indexbyte1 << 8 | indexbyte2)
	Op_ldc2_w						= 0x14, //	0001 0100	2: indexbyte1, indexbyte2	→ value	push a constant #index from a constant pool (double, long, or a dynamically-computed constant) onto the stack (wide index is constructed as indexbyte1 << 8 | indexbyte2)
	Op_ldiv							= 0x6d, //	0110 1101		value1, value2 → result	divide two longs
	Op_lload						= 0x16, //	0001 0110	1: index	→ value	load a long value from a local variable #index
	Op_lload_0					= 0x1e, //	0001 1110		→ value	load a long value from a local variable 0
	Op_lload_1					= 0x1f, //	0001 1111		→ value	load a long value from a local variable 1
	Op_lload_2					= 0x20, //	0010 0000		→ value	load a long value from a local variable 2
	Op_lload_3					= 0x21, //	0010 0001		→ value	load a long value from a local variable 3
	Op_lmul							= 0x69, //	0110 1001		value1, value2 → result	multiply two longs
	Op_lneg							= 0x75, //	0111 0101		value → result	negate a long
	Op_lookupswitch			= 0xab, //	1010 1011	8+: <0–3 bytes padding>, defaultbyte1, defaultbyte2, defaultbyte3, defaultbyte4, npairs1, npairs2, npairs3, npairs4, match-offset pairs...	key →	a target address is looked up from a table using a key and execution continues from the instruction at that address
	Op_lor							= 0x81, //	1000 0001		value1, value2 → result	bitwise OR of two longs
	Op_lrem							= 0x71, //	0111 0001		value1, value2 → result	remainder of division of two longs
	Op_lreturn					= 0xad, //	1010 1101		value → [empty]	return a long value
	Op_lshl							= 0x79, //	0111 1001		value1, value2 → result	bitwise shift left of a long value1 by int value2 positions
	Op_lshr							= 0x7b, //	0111 1011		value1, value2 → result	bitwise shift right of a long value1 by int value2 positions
	Op_lstore						= 0x37, //	0011 0111	1: index	value →	store a long value in a local variable #index
	Op_lstore_0					= 0x3f, //	0011 1111		value →	store a long value in a local variable 0
	Op_lstore_1					= 0x40, //	0100 0000		value →	store a long value in a local variable 1
	Op_lstore_2					= 0x41, //	0100 0001		value →	store a long value in a local variable 2
	Op_lstore_3					= 0x42, //	0100 0010		value →	store a long value in a local variable 3
	Op_lsub							= 0x65, //	0110 0101		value1, value2 → result	subtract two longs
	Op_lushr						= 0x7d, //	0111 1101		value1, value2 → result	bitwise shift right of a long value1 by int value2 positions, unsigned
	Op_lxor							= 0x83, //	1000 0011		value1, value2 → result	bitwise XOR of two longs
	Op_monitorenter			= 0xc2, //	1100 0010		objectref →	enter monitor for object ("grab the lock" – start of synchronized() section)
	Op_monitorexit			= 0xc3, //	1100 0011		objectref →	exit monitor for object ("release the lock" – end of synchronized() section)
	Op_multianewarray		= 0xc5, //	1100 0101	3: indexbyte1, indexbyte2, dimensions	count1, [count2,...] → arrayref	create a new array of dimensions dimensions of type identified by class reference in constant pool index (indexbyte1 << 8 | indexbyte2); the sizes of each dimension is identified by count1, [count2, etc.]
	Op_new							= 0xbb, //	1011 1011	2: indexbyte1, indexbyte2	→ objectref	create new object of type identified by class reference in constant pool index (indexbyte1 << 8 | indexbyte2)
	Op_newarray					= 0xbc, //	1011 1100	1: atype	count → arrayref	create new array with count elements of primitive type identified by atype
	Op_nop							= 0x00, //	0000 0000		[No change]	perform no operation
	Op_pop							= 0x57, //	0101 0111		value →	discard the top value on the stack
	Op_pop2							= 0x58, //	0101 1000		{value2, value1} →	discard the top two values on the stack (or one value, if it is a double or long)
	Op_putfield					= 0xb5, //	1011 0101	2: indexbyte1, indexbyte2	objectref, value →	set field to value in an object objectref, where the field is identified by a field reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_putstatic				= 0xb3, //	1011 0011	2: indexbyte1, indexbyte2	value →	set static field to value in a class, where the field is identified by a field reference index in constant pool (indexbyte1 << 8 | indexbyte2)
	Op_ret							= 0xa9, //	1010 1001	1: index	[No change]	continue execution from address taken from a local variable #index (the asymmetry with jsr is intentional)
	Op_return						= 0xb1, //	1011 0001		→ [empty]	return void from method
	Op_saload						= 0x35, //	0011 0101		arrayref, index → value	load short from array
	Op_sastore					= 0x56, //	0101 0110		arrayref, index, value →	store short to array
	Op_sipush						= 0x11, //	0001 0001	2: byte1, byte2	→ value	push a short onto the stack as an integer value
	Op_swap							= 0x5f, //	0101 1111		value2, value1 → value1, value2	swaps two top words on the stack (note that value1 and value2 must not be double or long)
	Op_tableswitch			= 0xaa, //	1010 1010	16+: [0–3 bytes padding], defaultbyte1, defaultbyte2, defaultbyte3, defaultbyte4, lowbyte1, lowbyte2, lowbyte3, lowbyte4, highbyte1, highbyte2, highbyte3, highbyte4, jump offsets...	index →	continue execution from an address in the table at offset index
	Op_wide							= 0xc4, //	1100 0100	3/5: opcode, indexbyte1, indexbyte2 or iinc, indexbyte1, indexbyte2, countbyte1, countbyte2	[same as for corresponding instructions]	execute opcode, where opcode is either iload, fload, aload, lload, dload, istore, fstore, astore, lstore, dstore, or ret, but assume the index is 16 bit; or execute iinc, where the index is 16 bits and the constant to increment by is a signed 16 bit short
	// (no name)				= cb-fd			these values are currently unassigned for opcodes and are reserved for future use
};

const char* OpCode_toString(enum OpCodes opcode) {
	switch (opcode)
	{
	case Op_aaload: 
		return "aaload";
	case Op_aastore: 
		return "aastore";
	case Op_aconst_null: 
		return "aconst_null";
	case Op_aload: 
		return "aload";
	case Op_aload_0: 
		return "aload_0";
	case Op_aload_1: 
		return "aload_1";
	case Op_aload_2: 
		return "aload_2";
	case Op_aload_3: 
		return "aload_3";
	case Op_anewarray: 
		return "anewarray";
	case Op_areturn: 
		return "areturn";
	case Op_arraylength: 
		return "arraylength";
	case Op_astore: 
		return "astore";
	case Op_astore_0: 
		return "astore_0";
	case Op_astore_1: 
		return "astore_1";
	case Op_astore_2: 
		return "astore_2";
	case Op_astore_3: 
		return "astore_3";
	case Op_athrow: 
		return "athrow";
	case Op_baload: 
		return "baload";
	case Op_bastore: 
		return "bastore";
	case Op_bipush: 
		return "bipush";
	case Op_breakpoint: 
		return "breakpoint";
	case Op_caload: 
		return "caload";
	case Op_castore: 
		return "castore";
	case Op_checkcast: 
		return "checkcast";
	case Op_d2f: 
		return "d2f";
	case Op_d2i: 
		return "d2i";
	case Op_d2l: 
		return "d2l";
	case Op_dadd: 
		return "dadd";
	case Op_daload: 
		return "daload";
	case Op_dastore: 
		return "dastore";
	case Op_dcmpg: 
		return "dcmpg";
	case Op_dcmpl: 
		return "dcmpl";
	case Op_dconst_0: 
		return "dconst_0";
	case Op_dconst_1: 
		return "dconst_1";
	case Op_ddiv: 
		return "ddiv";
	case Op_dload: 
		return "dload";
	case Op_dload_0: 
		return "dload_0";
	case Op_dload_1: 
		return "dload_1";
	case Op_dload_2: 
		return "dload_2";
	case Op_dload_3: 
		return "dload_3";
	case Op_dmul: 
		return "dmul";
	case Op_dneg: 
		return "dneg";
	case Op_drem: 
		return "drem";
	case Op_dreturn: 
		return "dreturn";
	case Op_dstore: 
		return "dstore";
	case Op_dstore_0: 
		return "dstore_0";
	case Op_dstore_1: 
		return "dstore_1";
	case Op_dstore_2: 
		return "dstore_2";
	case Op_dstore_3: 
		return "dstore_3";
	case Op_dsub: 
		return "dsub";
	case Op_dup: 
		return "dup";
	case Op_dup_x1: 
		return "dup_x1";
	case Op_dup_x2: 
		return "dup_x2";
	case Op_dup2: 
		return "dup2";
	case Op_dup2_x1: 
		return "dup2_x1";
	case Op_dup2_x2: 
		return "dup2_x2";
	case Op_f2d: 
		return "f2d";
	case Op_f2i: 
		return "f2i";
	case Op_f2l: 
		return "f2l";
	case Op_fadd: 
		return "fadd";
	case Op_faload: 
		return "faload";
	case Op_fastore: 
		return "fastore";
	case Op_fcmpg: 
		return "fcmpg";
	case Op_fcmpl: 
		return "fcmpl";
	case Op_fconst_0: 
		return "fconst_0";
	case Op_fconst_1: 
		return "fconst_1";
	case Op_fconst_2: 
		return "fconst_2";
	case Op_fdiv: 
		return "fdiv";
	case Op_fload: 
		return "fload";
	case Op_fload_0: 
		return "fload_0";
	case Op_fload_1: 
		return "fload_1";
	case Op_fload_2: 
		return "fload_2";
	case Op_fload_3: 
		return "fload_3";
	case Op_fmul: 
		return "fmul";
	case Op_fneg: 
		return "fneg";
	case Op_frem: 
		return "frem";
	case Op_freturn: 
		return "freturn";
	case Op_fstore: 
		return "fstore";
	case Op_fstore_0: 
		return "fstore_0";
	case Op_fstore_1: 
		return "fstore_1";
	case Op_fstore_2: 
		return "fstore_2";
	case Op_fstore_3: 
		return "fstore_3";
	case Op_fsub: 
		return "fsub";
	case Op_getfield: 
		return "getfield";
	case Op_getstatic: 
		return "getstatic";
	case Op_goto: 
		return "goto";
	case Op_goto_w: 
		return "goto_w";
	case Op_i2b: 
		return "i2b";
	case Op_i2c: 
		return "i2c";
	case Op_i2d: 
		return "i2d";
	case Op_i2f: 
		return "i2f";
	case Op_i2l: 
		return "i2l";
	case Op_i2s: 
		return "i2s";
	case Op_iadd: 
		return "iadd";
	case Op_iaload: 
		return "iaload";
	case Op_iand: 
		return "iand";
	case Op_iastore: 
		return "iastore";
	case Op_iconst_m1: 
		return "iconst_m1";
	case Op_iconst_0: 
		return "iconst_0";
	case Op_iconst_1: 
		return "iconst_1";
	case Op_iconst_2: 
		return "iconst_2";
	case Op_iconst_3: 
		return "iconst_3";
	case Op_iconst_4: 
		return "iconst_4";
	case Op_iconst_5: 
		return "iconst_5";
	case Op_idiv: 
		return "idiv";
	case Op_if_acmpeq: 
		return "if_acmpeq";
	case Op_if_acmpne: 
		return "if_acmpne";
	case Op_if_icmpeq: 
		return "if_icmpeq";
	case Op_if_icmpge: 
		return "if_icmpge";
	case Op_if_icmpgt: 
		return "if_icmpgt";
	case Op_if_icmple: 
		return "if_icmple";
	case Op_if_icmplt: 
		return "if_icmplt";
	case Op_if_icmpne: 
		return "if_icmpne";
	case Op_ifeq: 
		return "ifeq";
	case Op_ifge: 
		return "ifge";
	case Op_ifgt: 
		return "ifgt";
	case Op_ifle: 
		return "ifle";
	case Op_iflt: 
		return "iflt";
	case Op_ifne: 
		return "ifne";
	case Op_ifnonnull: 
		return "ifnonnull";
	case Op_ifnull: 
		return "ifnull";
	case Op_iinc: 
		return "iinc";
	case Op_iload: 
		return "iload";
	case Op_iload_0: 
		return "iload_0";
	case Op_iload_1: 
		return "iload_1";
	case Op_iload_2: 
		return "iload_2";
	case Op_iload_3: 
		return "iload_3";
	case Op_impdep1: 
		return "impdep1";
	case Op_impdep2: 
		return "impdep2";
	case Op_imul: 
		return "imul";
	case Op_ineg: 
		return "ineg";
	case Op_instanceof: 
		return "instanceof";
	case Op_invokedynamic: 
		return "invokedynamic";
	case Op_invokeinterface: 
		return "invokeinterface";
	case Op_invokespecial: 
		return "invokespecial";
	case Op_invokestatic: 
		return "invokestatic";
	case Op_invokevirtual: 
		return "invokevirtual";
	case Op_ior: 
		return "ior";
	case Op_irem: 
		return "irem";
	case Op_ireturn: 
		return "ireturn";
	case Op_ishl: 
		return "ishl";
	case Op_ishr: 
		return "ishr";
	case Op_istore: 
		return "istore";
	case Op_istore_0: 
		return "istore_0";
	case Op_istore_1: 
		return "istore_1";
	case Op_istore_2: 
		return "istore_2";
	case Op_istore_3: 
		return "istore_3";
	case Op_isub: 
		return "isub";
	case Op_iushr: 
		return "iushr";
	case Op_ixor: 
		return "ixor";
	case Op_jsr: 
		return "jsr";
	case Op_jsr_w: 
		return "jsr_w";
	case Op_l2d: 
		return "l2d";
	case Op_l2f: 
		return "l2f";
	case Op_l2i: 
		return "l2i";
	case Op_ladd: 
		return "ladd";
	case Op_laload: 
		return "laload";
	case Op_land: 
		return "land";
	case Op_lastore: 
		return "lastore";
	case Op_lcmp: 
		return "lcmp";
	case Op_lconst_0: 
		return "lconst_0";
	case Op_lconst_1: 
		return "lconst_1";
	case Op_ldc: 
		return "ldc";
	case Op_ldc_w: 
		return "ldc_w";
	case Op_ldc2_w: 
		return "ldc2_w";
	case Op_ldiv: 
		return "ldiv";
	case Op_lload: 
		return "lload";
	case Op_lload_0: 
		return "lload_0";
	case Op_lload_1: 
		return "lload_1";
	case Op_lload_2: 
		return "lload_2";
	case Op_lload_3: 
		return "lload_3";
	case Op_lmul: 
		return "lmul";
	case Op_lneg: 
		return "lneg";
	case Op_lookupswitch: 
		return "lookupswitch";
	case Op_lor: 
		return "lor";
	case Op_lrem: 
		return "lrem";
	case Op_lreturn: 
		return "lreturn";
	case Op_lshl: 
		return "lshl";
	case Op_lshr: 
		return "lshr";
	case Op_lstore: 
		return "lstore";
	case Op_lstore_0: 
		return "lstore_0";
	case Op_lstore_1: 
		return "lstore_1";
	case Op_lstore_2: 
		return "lstore_2";
	case Op_lstore_3: 
		return "lstore_3";
	case Op_lsub: 
		return "lsub";
	case Op_lushr: 
		return "lushr";
	case Op_lxor: 
		return "lxor";
	case Op_monitorenter: 
		return "monitorenter";
	case Op_monitorexit: 
		return "monitorexit";
	case Op_multianewarray: 
		return "multianewarray";
	case Op_new: 
		return "new";
	case Op_newarray: 
		return "newarray";
	case Op_nop: 
		return "nop";
	case Op_pop: 
		return "pop";
	case Op_pop2: 
		return "pop2";
	case Op_putfield: 
		return "putfield";
	case Op_putstatic: 
		return "putstatic";
	case Op_ret: 
		return "ret";
	case Op_return: 
		return "return";
	case Op_saload: 
		return "saload";
	case Op_sastore: 
		return "sastore";
	case Op_sipush: 
		return "sipush";
	case Op_swap: 
		return "swap";
	case Op_tableswitch: 
		return "tableswitch";
	case Op_wide: 
		return "wide";
	default:
		// TODO: to handle errors
		return nullptr;
	}
}