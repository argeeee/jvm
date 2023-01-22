#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/core.h"

#define CONSTANT_Class               7
#define CONSTANT_Fieldref            9
#define CONSTANT_Methodref           10
#define CONSTANT_InterfaceMethodref  11
#define CONSTANT_String              8
#define CONSTANT_Integer             3
#define CONSTANT_Float               4
#define CONSTANT_Long                5
#define CONSTANT_Double              6
#define CONSTANT_NameAndType         12
#define CONSTANT_Utf8                1
#define CONSTANT_MethodHandle        15
#define CONSTANT_MethodType          16
#define CONSTANT_InvokeDynamic       18

const char* ConstantPool_tag_to_str(u8 tag) {
	switch (tag)
	{
	case CONSTANT_Class:
		return "CONSTANT_Class";
	case CONSTANT_Fieldref:
		return "CONSTANT_Fieldref";
	case CONSTANT_Methodref:
		return "CONSTANT_Methodref";
	case CONSTANT_InterfaceMethodref:
		return "CONSTANT_InterfaceMethodref";
	case CONSTANT_String:
		return "CONSTANT_String";
	case CONSTANT_Integer:
		return "CONSTANT_Integer";
	case CONSTANT_Float:
		return "CONSTANT_Float";
	case CONSTANT_Long:
		return "CONSTANT_Long";
	case CONSTANT_Double:
		return "CONSTANT_Double";
	case CONSTANT_NameAndType:
		return "CONSTANT_NameAndType";
	case CONSTANT_Utf8:
		return "CONSTANT_Utf8";
	case CONSTANT_MethodHandle:
		return "CONSTANT_MethodHandle";
	case CONSTANT_MethodType:
		return "CONSTANT_MethodType";
	case CONSTANT_InvokeDynamic:
		return "CONSTANT_InvokeDynamic";
	default:
		return NULL;
	}
}

/*
CONSTANT_Class_info {
	u1 tag;
	u2 name_index;
}
*/
struct Constant_Class {
	u16 name_index;
};
typedef struct Constant_Class Constant_Class;

/*
CONSTANT_Fieldref_info {
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
}

CONSTANT_Methodref_info {
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
}

CONSTANT_InterfaceMethodref_info {
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
}
*/
struct Constant_Fieldref {
	u16 class_index;
	u16 name_and_type_index;
};
typedef struct Constant_Fieldref Constant_Fieldref;

struct Constant_Methodref {
	u16 class_index;
	u16 name_and_type_index;
};
typedef struct Constant_Methodref Constant_Methodref;

struct Constant_InterfaceMethodref {
	u16 class_index;
	u16 name_and_type_index;
};
typedef struct Constant_InterfaceMethodref Constant_InterfaceMethodref;

/*
CONSTANT_String_info {
	u1 tag;
	u2 string_index;
}
*/
struct Constant_String {
	u16 string_index;
};
typedef struct Constant_String Constant_String;

/*
CONSTANT_Integer_info {
	u1 tag;
	u4 bytes;
}

CONSTANT_Float_info {
	u1 tag;
	u4 bytes;
}
*/
struct Constant_Integer {
	u32 bytes;
};
typedef struct Constant_Integer Constant_Integer;

struct Constant_Float {
	u32 bytes;
};
typedef struct Constant_Float Constant_Float;

/*
CONSTANT_Long_info {
	u1 tag;
	u4 high_bytes;
	u4 low_bytes;
}

CONSTANT_Double_info {
	u1 tag;
	u4 high_bytes;
	u4 low_bytes;
}
*/
struct Constant_Long {
	u32 high_bytes;
	u32 low_bytes;
};
typedef struct Constant_Long Constant_Long;

struct Constant_Double {
	u32 high_bytes;
	u32 low_bytes;
};
typedef struct Constant_Double Constant_Double;

/*
CONSTANT_NameAndType_info {
	u1 tag;
	u2 name_index;
	u2 descriptor_index;
}
*/
struct Constant_NameAndType {
	u16 name_index;
	u16 descriptor_index;
};
typedef struct Constant_NameAndType Constant_NameAndType;

/*
CONSTANT_Utf8_info {
	u1 tag;
	u2 length;
	u1 bytes[length];
}
*/
struct Constant_Utf8 {
	u16 length;
	byte *bytes;
};
typedef struct Constant_Utf8 Constant_Utf8;

/*
CONSTANT_MethodHandle_info {
	u1 tag;
	u1 reference_kind;
	u2 reference_index;
}
*/
struct Constant_MethodHandle {
	u8 reference_kind;
	u16 reference_index; 
};
typedef struct Constant_MethodHandle Constant_MethodHandle;

/*
CONSTANT_MethodType_info {
	u1 tag;
	u2 descriptor_index;
}
*/
struct Constant_MethodType {
	u16 descriptor_index;
};
typedef struct Constant_MethodType Constant_MethodType;

/*
CONSTANT_InvokeDynamic_info {
	u1 tag;
	u2 bootstrap_method_attr_index;
	u2 name_and_type_index;
}
*/
struct Constant_InvokeDynamic {
	u16 bootstrap_method_attr_index;
	u16 name_and_type_index;
};
typedef struct Constant_InvokeDynamic Constant_InvokeDynamic;

/*
cp_info {
	u1 tag;
	u1 info[];
}
*/
struct ConstantPoolInfo {
	u8 tag;
	union
	{
		Constant_Class constant_Class;
		Constant_Fieldref constant_Fieldref;
		Constant_Methodref constant_Methodref;
		Constant_InterfaceMethodref constant_InterfaceMethodref;
		Constant_String constant_String;
		Constant_Integer constant_Integer;
		Constant_Float constant_Float;
		Constant_Long constant_Long;
		Constant_Double constant_Double;
		Constant_NameAndType constant_NameAndType;
		Constant_Utf8 constant_Utf8;
		Constant_MethodHandle constant_MethodHandle;
		Constant_MethodType constant_MethodType;
		Constant_InvokeDynamic constant_InvokeDynamic;
	};
	
};
typedef struct ConstantPoolInfo ConstantPoolInfo;

ConstantPoolInfo *createConstantPoolInfo() {
	ConstantPoolInfo *constantPoolInfo = (ConstantPoolInfo*)malloc(sizeof(ConstantPoolInfo));
	return constantPoolInfo;
}

void deleteConstantPoolInfo(ConstantPoolInfo *constantPoolInfo) {
	if (constantPoolInfo->tag == CONSTANT_Utf8 && constantPoolInfo->constant_Utf8.bytes != NULL) {
		free(constantPoolInfo->constant_Utf8.bytes);
	} 
	free(constantPoolInfo);
}

// TO_STRING methods

char *Constant_Class_to_str(Constant_Class *cc) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Class: name_index=%d", cc->name_index);
	return str;
}

char *Constant_Fieldref_to_str(Constant_Fieldref *cf) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Fieldref: class_index=%d, name_and_type_index=%d", cf->class_index, cf->name_and_type_index);
	return str;
}

char *Constant_Methodref_to_str(Constant_Methodref *cm) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Methodref: class_index=%d, name_and_type_index=%d", cm->class_index, cm->name_and_type_index);
	return str;
}

char *Constant_InterfaceMethodref_to_str(Constant_InterfaceMethodref *cim) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant InterfaceMethodref: class_index=%d, name_and_type_index=%d", cim->class_index, cim->name_and_type_index);
	return str;
}

char *Constant_String_to_str(Constant_String *cs) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant String: string_index=%d", cs->string_index);
	return str;
}

char *Constant_Integer_to_str(Constant_Integer *ci) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Integer: bytes=%d", ci->bytes);
	return str;
}

char *Constant_Float_to_str(Constant_Float *cf) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Float: bytes=%d", cf->bytes);
	return str;
}

char *Constant_Long_to_str(Constant_Long *cl) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Long: high_bytes=%d, low_bytes=%d", cl->high_bytes, cl->low_bytes);
	return str;
}

char *Constant_Double_to_str(Constant_Double *cd) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant Double: high_bytes=%d, low_bytes=%d", cd->high_bytes, cd->low_bytes);
	return str;
}

char *Constant_NameAndType_to_str(Constant_NameAndType *cnt) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant NameAndType: name_index=%d, descriptor_index=%d", cnt->name_index, cnt->descriptor_index);
	return str;
}

char *Constant_Utf8_to_str(Constant_Utf8 *cu) {
	char *str = (char *)malloc(sizeof(char) * (cu->length + 128));
	snprintf(str, cu->length + 128, "Constant Utf8: length=%d, bytes=%s", cu->length, cu->bytes);
	return str;
}

char *Constant_MethodHandle_to_str(Constant_MethodHandle *cmh) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant MethodHandle: reference_kind=%d, reference_index=%d", cmh->reference_kind, cmh->reference_index);
	return str;
}

char *Constant_MethodType_to_str(Constant_MethodType *cmt) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant MethodType: descriptor_index=%d", cmt->descriptor_index);
	return str;
}

char *Constant_InvokeDynamic_to_str(Constant_InvokeDynamic *cid) {
	char *str = (char *)malloc(sizeof(char) * 128);
	snprintf(str, 128, "Constant InvokeDynamic: bootstrap_method_attr_index=%d, name_and_type_index=%d", cid->bootstrap_method_attr_index, cid->name_and_type_index);
	return str;
}

char *ConstantPoolInfo_to_str(ConstantPoolInfo *cpi) {
	char *str;
	switch(cpi->tag)
	{
	case CONSTANT_Class:
		str = Constant_Class_to_str(&cpi->constant_Class);
		break;
	case CONSTANT_Fieldref:
		str = Constant_Fieldref_to_str(&cpi->constant_Fieldref);
		break;
	case CONSTANT_Methodref:
		str = Constant_Methodref_to_str(&cpi->constant_Methodref);
		break;
	case CONSTANT_InterfaceMethodref:
		str = Constant_InterfaceMethodref_to_str(&cpi->constant_InterfaceMethodref);
		break;
	case CONSTANT_String:
		str = Constant_String_to_str(&cpi->constant_String);
		break;
	case CONSTANT_Integer:
		str = Constant_Integer_to_str(&cpi->constant_Integer);
		break;
	case CONSTANT_Float:
		str = Constant_Float_to_str(&cpi->constant_Float);
		break;
	case CONSTANT_Long:
		str = Constant_Long_to_str(&cpi->constant_Long);
		break;
	case CONSTANT_Double:
		str = Constant_Double_to_str(&cpi->constant_Double);
		break;
	case CONSTANT_NameAndType:
		str = Constant_NameAndType_to_str(&cpi->constant_NameAndType);
		break;
	case CONSTANT_Utf8:
		str = Constant_Utf8_to_str(&cpi->constant_Utf8);
		break;
	case CONSTANT_MethodHandle:
		str = Constant_MethodHandle_to_str(&cpi->constant_MethodHandle);
		break;
	case CONSTANT_MethodType:
		str = Constant_MethodType_to_str(&cpi->constant_MethodType);
		break;
	case CONSTANT_InvokeDynamic:
		str = Constant_InvokeDynamic_to_str(&cpi->constant_InvokeDynamic);
		break;
	default:
		str = (char *)malloc(sizeof(char) * 16);
		snprintf(str, 16, "Unknown Type");
	}
	return str;
}

