#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Core/Core.hpp"
#include "Domain/Entities/AttributeInfo.hpp"

/*
ACC_PUBLIC	0x0001	Declared public; may be accessed from outside its package.
ACC_PRIVATE	0x0002	Declared private; usable only within the defining class.
ACC_PROTECTED	0x0004	Declared protected; may be accessed within subclasses.
ACC_STATIC	0x0008	Declared static.
ACC_FINAL	0x0010	Declared final; never directly assigned to after object construction (JLS §17.5).
ACC_VOLATILE	0x0040	Declared volatile; cannot be cached.
ACC_TRANSIENT	0x0080	Declared transient; not written or read by a persistent object manager.
ACC_SYNTHETIC	0x1000	Declared synthetic; not present in the source code.
ACC_ENUM	0x4000	Declared as an element of an enum.
*/
#define ACC_PUBLIC		0x0001
#define ACC_PRIVATE		0x0002
#define ACC_PROTECTED	0x0004
#define ACC_STATIC		0x0008
#define ACC_FINAL			0x0010
#define ACC_VOLATILE	0x0040
#define ACC_TRANSIENT	0x0080
#define ACC_SYNTHETIC	0x1000
#define ACC_ENUM			0x4000

/*
field_info {
	u2             access_flags;
	u2             name_index;
	u2             descriptor_index;
	u2             attributes_count;
	attribute_info attributes[attributes_count];
}
*/
struct FieldInfo {
	u16 access_flags;
	u16 name_index;
	u16 descriptor_index;
	u16 attributes_count;
	AttributeInfo **attributes;
};
typedef struct FieldInfo FieldInfo;

FieldInfo *createFieldInfo() {
	FieldInfo *fieldInfo = (FieldInfo*)malloc(sizeof(FieldInfo));
	return fieldInfo;
}

void deleteFieldInfo(FieldInfo *fieldInfo) {
	if (fieldInfo->attributes != NULL) {
		for (int i = 0; i < fieldInfo->attributes_count; i++) {
			deleteAttributeInfo(fieldInfo->attributes[i]);
		}
	}
	free(fieldInfo);
}

char *FieldInfo_to_str(FieldInfo *fi) {
	char *str;
	asprintf(&str, "FieldInfo access_flags=%d, name_index=%d, descriptor_index=%d, attributes_count=%d", fi->access_flags, fi->name_index, fi->descriptor_index, fi->attributes_count);
	int i;
	for(i = 0; i < fi->attributes_count; i++){
		char *temp;
		asprintf(&temp, "\n\t %s", AttributeInfo_to_str(fi->attributes[i]));
		str = (char*)realloc(str, strlen(str) + strlen(temp) + 1);
		strcat(str, temp);
		free(temp);
	}
	return str;
}