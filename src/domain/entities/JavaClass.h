#pragma once

#include "core/core.h"
#include "domain/entities/ConstantPool.h"

/*
ClassFile {
	u4             magic;
	u2             minor_version;
	u2             major_version;
	u2             constant_pool_count;
	cp_info        constant_pool[constant_pool_count-1];
	u2             access_flags;
	u2             this_class;
	u2             super_class;
	u2             interfaces_count;
	u2             interfaces[interfaces_count];
	u2             fields_count;
	field_info     fields[fields_count];
	u2             methods_count;
	method_info    methods[methods_count];
	u2             attributes_count;
	attribute_info attributes[attributes_count];
}
*/
struct JavaClass {
	u32 magic;

	u16 minor_version;
	u16 major_version;
	
	u16 constant_pool_count;
	ConstantPoolInfo **constant_pool;

	u16 access_flags;
	u16 this_class;
	u16 super_class;

	u16 interfaces_count;
	u16 *interfaces;
};
typedef struct JavaClass JavaClass;

JavaClass *createJavaClass() {
	JavaClass *javaClass = (JavaClass*)malloc(sizeof(JavaClass));
	return javaClass;
}

void deleteJavaClass(JavaClass *javaClass) {
	if (javaClass->constant_pool != NULL) {
		for (int i = 0; i < javaClass->constant_pool_count - 1; i++) {
			deleteConstantPoolInfo(javaClass->constant_pool[i]);
		}
	}
	free(javaClass);
}