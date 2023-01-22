#pragma once 

#include <stdio.h>
#include "core/core.h"
#include "domain/entities/JavaClass.h"
#include "domain/entities/ConstantPool.h"

#define readField(prop, fp) \
	fread(&(prop), sizeof(prop), 1, fp); \
	if (sizeof(prop) == 2) \
		prop = reverse_2_bytes(prop); \
	else if (sizeof(prop) == 4) \
		prop = reverse_4_bytes(prop);

void readConstantPoolSection(FILE *fp, JavaClass *javaClass) {
	readField(javaClass->constant_pool_count, fp);
	// fread(&(javaClass->constant_pool_count), sizeof(javaClass->constant_pool_count), 1, fp);
	ConstantPoolInfo **constant_pool = (ConstantPoolInfo **)malloc(
		sizeof(ConstantPoolInfo*) * (javaClass->constant_pool_count - 1)
	);
	
	for (int i = 0; i < (javaClass->constant_pool_count - 1); i++) {
		constant_pool[i] = createConstantPoolInfo();
		ConstantPoolInfo *cp_info = constant_pool[i];
		fread(&(cp_info->tag), sizeof(cp_info->tag), 1, fp);

		switch (cp_info->tag) {
			case CONSTANT_Class: {
				readField(cp_info->constant_Class.name_index, fp);
				break;
			}
			case CONSTANT_Fieldref: {
				readField(cp_info->constant_Fieldref.class_index, fp);
				readField(cp_info->constant_Fieldref.name_and_type_index, fp);
				break;
			}
			case CONSTANT_Methodref: {
				readField(cp_info->constant_Methodref.class_index, fp);
				readField(cp_info->constant_Methodref.name_and_type_index, fp);
				break;
			}
			case CONSTANT_InterfaceMethodref: {
				readField(cp_info->constant_InterfaceMethodref.class_index, fp);
				readField(cp_info->constant_InterfaceMethodref.name_and_type_index, fp);
				break;
			}
			case CONSTANT_String: {
				readField(cp_info->constant_String.string_index, fp);
				break;
			}
			case CONSTANT_Integer: {
				readField(cp_info->constant_Integer.bytes, fp);
				break;
			}
			case CONSTANT_Float: {
				readField(cp_info->constant_Float.bytes, fp);
				break;
			}
			case CONSTANT_Long: {
				readField(cp_info->constant_Long.high_bytes, fp);
				readField(cp_info->constant_Long.low_bytes, fp);
				break;
			}
			case CONSTANT_Double: {
				readField(cp_info->constant_Double.high_bytes, fp);
				readField(cp_info->constant_Double.low_bytes, fp);
				break;
			}
			case CONSTANT_NameAndType: {
				readField(cp_info->constant_NameAndType.name_index, fp);
				readField(cp_info->constant_NameAndType.descriptor_index, fp);
				break;
			}
			case CONSTANT_Utf8: {
				readField(cp_info->constant_Utf8.length, fp);
				u32 len = cp_info->constant_Utf8.length + 1;
				cp_info->constant_Utf8.bytes = (byte*)malloc(sizeof(byte) * len);
				fread((cp_info->constant_Utf8.bytes), sizeof(byte) * len - 1, 1, fp);
				cp_info->constant_Utf8.bytes[len] = 0;
				break;
			}
			case CONSTANT_MethodHandle: {
				readField(cp_info->constant_MethodHandle.reference_kind, fp);
				readField(cp_info->constant_MethodHandle.reference_index, fp);
				break;
			}
			case CONSTANT_MethodType: {
				readField(cp_info->constant_MethodType.descriptor_index, fp);
				break;
			}
			case CONSTANT_InvokeDynamic: {
				readField(cp_info->constant_InvokeDynamic.bootstrap_method_attr_index, fp);
				readField(cp_info->constant_InvokeDynamic.name_and_type_index, fp);
				break;
			}
				
			default: {
				// TODO: to handle errors 
				break;
			}
		}
		
	}
	javaClass->constant_pool = constant_pool;
}

JavaClass *loadClass(char *path) {
	FILE *fp = fopen(path, "rb");
	if (fp == NULL)
		return NULL;

	JavaClass *javaClass = createJavaClass();

	readField(javaClass->magic, fp);

	readField(javaClass->minor_version, fp);
	readField(javaClass->major_version, fp);

	readConstantPoolSection(fp, javaClass);
	
	return fclose(fp), javaClass;
}