#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/core.h"
#include "domain/entities/AttributeInfo.h"

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
