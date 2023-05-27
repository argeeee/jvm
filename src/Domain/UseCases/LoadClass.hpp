#pragma once

#include <stdio.h>
#include "Core/Core.hpp"
#include "Domain/Entities/JavaClass.hpp"
#include "Domain/Entities/ConstantPool.hpp"
#include "Domain/Entities/AttributeInfo.hpp"
#include "Domain/Entities/FieldInfo.hpp"

#define ReadField(prop, fp) \
	fread(&(prop), sizeof(prop), 1, fp); \
	if (sizeof(prop) == 2) \
		prop = reverse_2_bytes(prop); \
	else if (sizeof(prop) == 4) \
		prop = reverse_4_bytes(prop);

// TODO: error management for bad file format
class LoadClass : public UseCase<JavaClass*, char*> {
 public:
	LoadClass() { }
	virtual ~LoadClass() { }

  virtual JavaClass* operator()(char*& path) {
		FILE *fp = fopen(path, "rb");
		if (fp == NULL)
			return NULL;

		JavaClass *javaClass = CreateJavaClass();

		ReadField(javaClass->magic, fp);

		ReadField(javaClass->minor_version, fp);
		ReadField(javaClass->major_version, fp);

		ReadConstantPoolSection(fp, javaClass);

		ReadField(javaClass->access_flags, fp);
		ReadField(javaClass->this_class, fp);
		ReadField(javaClass->super_class, fp);

		ReadField(javaClass->interfaces_count, fp);

		if (javaClass->interfaces_count > 0) {
			javaClass->interfaces = (u16*)malloc(sizeof(u16) * javaClass->interfaces_count);
			fread((javaClass->interfaces), sizeof(u16) * javaClass->interfaces_count, 1, fp);
		}

		ReadFieldsSection(fp, javaClass);

		ReadMethodsSection(fp, javaClass);

		ReadAttributesSection(fp, javaClass);
		
		return fclose(fp), javaClass;
	}

 private:
	void ReadConstantPoolSection(FILE *fp, JavaClass *javaClass) {
		ReadField(javaClass->constant_pool_count, fp);

		// fread(&(javaClass->constant_pool_count), sizeof(javaClass->constant_pool_count), 1, fp);
		ConstantPoolInfo **constant_pool = (ConstantPoolInfo **)malloc(
			sizeof(ConstantPoolInfo*) * (javaClass->constant_pool_count - 1));
		
		for (int i = 0; i < (javaClass->constant_pool_count - 1); i++) {
			constant_pool[i] = CreateConstantPoolInfo();

			ConstantPoolInfo *cp_info = constant_pool[i];

			fread(&(cp_info->tag), sizeof(cp_info->tag), 1, fp);

			switch (cp_info->tag) {
				case CONSTANT_Class: {
					ReadField(cp_info->constant_Class.name_index, fp);
					break;
				}
				case CONSTANT_Fieldref: {
					ReadField(cp_info->constant_Fieldref.class_index, fp);
					ReadField(cp_info->constant_Fieldref.name_and_type_index, fp);
					break;
				}
				case CONSTANT_Methodref: {
					ReadField(cp_info->constant_Methodref.class_index, fp);
					ReadField(cp_info->constant_Methodref.name_and_type_index, fp);
					break;
				}
				case CONSTANT_InterfaceMethodref: {
					ReadField(cp_info->constant_InterfaceMethodref.class_index, fp);
					ReadField(cp_info->constant_InterfaceMethodref.name_and_type_index, fp);
					break;
				}
				case CONSTANT_String: {
					ReadField(cp_info->constant_String.string_index, fp);
					break;
				}
				case CONSTANT_Integer: {
					ReadField(cp_info->constant_Integer.bytes, fp);
					break;
				}
				case CONSTANT_Float: {
					ReadField(cp_info->constant_Float.bytes, fp);
					break;
				}
				case CONSTANT_Long: {
					ReadField(cp_info->constant_Long.high_bytes, fp);
					ReadField(cp_info->constant_Long.low_bytes, fp);
					break;
				}
				case CONSTANT_Double: {
					ReadField(cp_info->constant_Double.high_bytes, fp);
					ReadField(cp_info->constant_Double.low_bytes, fp);
					break;
				}
				case CONSTANT_NameAndType: {
					ReadField(cp_info->constant_NameAndType.name_index, fp);
					ReadField(cp_info->constant_NameAndType.descriptor_index, fp);
					break;
				}
				case CONSTANT_Utf8: {
					ReadField(cp_info->constant_Utf8.length, fp);
					u32 len = cp_info->constant_Utf8.length + 1;
					cp_info->constant_Utf8.bytes = (byte*)malloc(sizeof(byte) * len);
					fread((cp_info->constant_Utf8.bytes), sizeof(byte) * len - 1, 1, fp);
					cp_info->constant_Utf8.bytes[len] = 0;
					break;
				}
				case CONSTANT_MethodHandle: {
					ReadField(cp_info->constant_MethodHandle.reference_kind, fp);
					ReadField(cp_info->constant_MethodHandle.reference_index, fp);
					break;
				}
				case CONSTANT_MethodType: {
					ReadField(cp_info->constant_MethodType.descriptor_index, fp);
					break;
				}
				case CONSTANT_InvokeDynamic: {
					ReadField(cp_info->constant_InvokeDynamic.bootstrap_method_attr_index, fp);
					ReadField(cp_info->constant_InvokeDynamic.name_and_type_index, fp);
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

	void ReadAttribute(FILE *fp, AttributeInfo *attribute) {
		ReadField(attribute->attribute_name_index, fp);
		ReadField(attribute->attribute_length, fp);
		// TODO: to read specific attribute with a switch statement
		attribute->info = (u8*) malloc(sizeof(u8) * attribute->attribute_length + 1);
		fread((attribute->info), sizeof(u8) * attribute->attribute_length, 1, fp);
		attribute->info[attribute->attribute_length] = 0;
	}

	// TODO: to refactor and remove duplicate code
	void ReadAttributesSection(FILE *fp, JavaClass *javaClass) {
		ReadField(javaClass->attributes_count, fp);

		if (javaClass->attributes_count > 0) {
			AttributeInfo **attributes = (AttributeInfo **) malloc(
				sizeof(AttributeInfo *) * javaClass->attributes_count);
			
			for (int i = 0; i < javaClass->attributes_count; i++) {
				attributes[i] = CreateAttributeInfo();
				ReadAttribute(fp, attributes[i]);
			}

			javaClass->attributes = attributes;
		}
	}

	void ReadFieldsSection(FILE *fp, JavaClass *javaClass) {
		ReadField(javaClass->fields_count, fp);

		FieldInfo **fields = (FieldInfo **)malloc(
			sizeof(FieldInfo*) * (javaClass->fields_count));

		for (int i = 0; i < javaClass->fields_count; i++) {
			fields[i] = CreateFieldInfo();

			FieldInfo* field = fields[i];

			ReadField(field->access_flags, fp);
			ReadField(field->name_index, fp);
			ReadField(field->descriptor_index, fp);
			ReadField(field->attributes_count, fp);

			if (field->attributes_count > 0) {
				AttributeInfo **attributes = (AttributeInfo **) malloc(
					sizeof(AttributeInfo *) * field->attributes_count);

				for (int j = 0; j < field->attributes_count; j++) {
					attributes[j] = CreateAttributeInfo();
					ReadAttribute(fp, attributes[j]);
				}

				field->attributes = attributes;
			}
		}
		javaClass->fields = fields;
	}

	void ReadMethodsSection(FILE *fp, JavaClass *javaClass) {
		ReadField(javaClass->methods_count, fp);

		MethodInfo **methods = (MethodInfo **)malloc(
			sizeof(MethodInfo*) * (javaClass->methods_count));

		for (int i = 0; i < javaClass->methods_count; i++) {
			methods[i] = CreateMethodInfo();

			MethodInfo* method = methods[i];

			ReadField(method->access_flags, fp);
			ReadField(method->name_index, fp);
			ReadField(method->descriptor_index, fp);
			ReadField(method->attributes_count, fp);
		
			if (method->attributes_count > 0) {
				AttributeInfo **attributes = (AttributeInfo **) malloc(
					sizeof(AttributeInfo *) * method->attributes_count);
		
				for (int j = 0; j < method->attributes_count; j++) {
					attributes[j] = CreateAttributeInfo();
					ReadAttribute(fp, attributes[j]);
				}
		
				method->attributes = attributes;
			}
		}
		
		javaClass->methods = methods;
	}

};

#undef ReadField