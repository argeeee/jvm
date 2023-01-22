#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Core/Core.h"
#include "Domain/Entities/AttributeInfo.h"

/*
ConstantValue
Code
StackMapTable
Exceptions
InnerClasses
EnclosingMethod
Synthetic
Signature
SourceFile
SourceDebugExtension
LineNumberTable
LocalVariableTable
LocalVariableTypeTable
Deprecated
RuntimeVisibleAnnotations
RuntimeInvisibleAnnotations
RuntimeVisibleParameterAnnotations
RuntimeInvisibleParameterAnnotations
AnnotationDefault
BootstrapMethods
*/

/*
attribute_info {
	u2 attribute_name_index;
	u4 attribute_length;
	u1 info[attribute_length];
}
*/
struct AttributeInfo {
	u16 attribute_name_index;
	u32 attribute_length;
	// TODO: to change and make it an union of all kind of atteributes
	u8 *info;
};
typedef struct AttributeInfo AttributeInfo;

AttributeInfo *createAttributeInfo() {
	AttributeInfo *attributeInfo = (AttributeInfo*)malloc(sizeof(AttributeInfo));
	return attributeInfo;
}

void deleteAttributeInfo(AttributeInfo *attributeInfo) {
	if (attributeInfo->info != NULL) {
		free(attributeInfo->info);
	}
	free(attributeInfo);
}

char *AttributeInfo_to_str(AttributeInfo *ai) {
	char *str;
	asprintf(&str, "Attribute name_index=%d, attribute_length=%d, info=%s", ai->attribute_name_index, ai->attribute_length, ai->info);
	return str;
}
