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
ConstantValue_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 constantvalue_index;
}
*/
/*
long	CONSTANT_Long
float	CONSTANT_Float
double	CONSTANT_Double
int, short, char, byte, boolean	CONSTANT_Integer
String	CONSTANT_String
*/
struct ConstantValue_attribute {
	u16 constantvalue_index;
};
typedef struct ConstantValue_attribute ConstantValue_attribute;

/*
Code_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 max_stack;
	u2 max_locals;
	u4 code_length;
	u1 code[code_length];
	u2 exception_table_length;
	{ u2 start_pc;
		u2 end_pc;
		u2 handler_pc;
		u2 catch_type;
	} exception_table[exception_table_length];
	u2 attributes_count;
	attribute_info attributes[attributes_count];
}
*/

struct ExceptionInfo {
	u16 start_pc;
	u16 end_pc;
	u16 handler_pc;
	u16 catch_type;
};
typedef struct ExceptionInfo ExceptionInfo;

struct Code_attribute {
	u16 attribute_name_index;
	u32 attribute_length;
	u16 max_stack;
	u16 max_locals;
	u32 code_length;
	u8 *code;
	u16 exception_table_length;
	ExceptionInfo **exception_table;
	u16 attributes_count;
	AttributeInfo **attributes;
};
typedef struct ConstantValue_attribute ConstantValue_attribute;

/*
StackMapTable_attribute {
	u2              attribute_name_index;
	u4              attribute_length;
	u2              number_of_entries;
	stack_map_frame entries[number_of_entries];
}
*/
struct StackMapTable_attribute {
	// TODO
};
typedef struct StackMapTable_attribute StackMapTable_attribute;

/*
Exceptions_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 number_of_exceptions;
	u2 exception_index_table[number_of_exceptions];
}
*/
struct Exceptions_attribute {
	// TODO
};
typedef struct Exceptions_attribute Exceptions_attribute;

/*
InnerClasses_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 number_of_classes;
	{ u2 inner_class_info_index;
		u2 outer_class_info_index;
		u2 inner_name_index;
		u2 inner_class_access_flags;
	} classes[number_of_classes];
}
*/
struct InnerClasses_attribute {
	// TODO
};
typedef struct InnerClasses_attribute InnerClasses_attribute;

/*
EnclosingMethod_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 class_index;
	u2 method_index;
}
*/
struct EnclosingMethod_attribute {
	// TODO
};
typedef struct EnclosingMethod_attribute EnclosingMethod_attribute;

/*
Synthetic_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
}
*/
struct Synthetic_attribute {
	// TODO
};
typedef struct Synthetic_attribute Synthetic_attribute;

/*
Signature_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 signature_index;
}
*/
struct Signature_attribute {
	// TODO
};
typedef struct Signature_attribute Signature_attribute;

/*
SourceFile_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 sourcefile_index;
}
*/
struct SourceFile_attribute {
	// TODO
};
typedef struct SourceFile_attribute SourceFile_attribute;

/*
SourceDebugExtension_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u1 debug_extension[attribute_length];
}
*/
struct SourceDebugExtension_attribute {
	// TODO
};
typedef struct SourceDebugExtension_attribute SourceDebugExtension_attribute;

/*
LineNumberTable_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 line_number_table_length;
	{ u2 start_pc;
		u2 line_number;	
	} line_number_table[line_number_table_length];
}
*/
struct LineNumberTable_attribute {
	// TODO
};
typedef struct LineNumberTable_attribute LineNumberTable_attribute;

/*
LocalVariableTable_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 local_variable_table_length;
	{ u2 start_pc;
		u2 length;
		u2 name_index;
		u2 descriptor_index;
		u2 index;
	} local_variable_table[local_variable_table_length];
}
*/
struct LocalVariableTable_attribute {
	// TODO
};
typedef struct LocalVariableTable_attribute LocalVariableTable_attribute;

/*
LocalVariableTypeTable_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 local_variable_type_table_length;
	{ u2 start_pc;
		u2 length;
		u2 name_index;
		u2 signature_index;
		u2 index;
	} local_variable_type_table[local_variable_type_table_length];
}
*/
struct LocalVariableTypeTable_attribute {
	// TODO
};
typedef struct LocalVariableTypeTable_attribute LocalVariableTypeTable_attribute;

/*
Deprecated_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
}
*/
struct Deprecated_attribute {
};
typedef struct Deprecated_attribute Deprecated_attribute;

/*
RuntimeVisibleAnnotations_attribute {
	u2         attribute_name_index;
	u4         attribute_length;
	u2         num_annotations;
	annotation annotations[num_annotations];
}
*/
struct RuntimeVisibleAnnotations_attribute {
	// TODO
};
typedef struct RuntimeVisibleAnnotations_attribute RuntimeVisibleAnnotations_attribute;

/*
RuntimeInvisibleAnnotations_attribute {
	u2         attribute_name_index;
	u4         attribute_length;
	u2         num_annotations;
	annotation annotations[num_annotations];
}
*/
struct RuntimeInvisibleAnnotations_attribute {
	// TODO
};
typedef struct RuntimeInvisibleAnnotations_attribute RuntimeInvisibleAnnotations_attribute;

/*
RuntimeVisibleParameterAnnotations_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u1 num_parameters;
	{ u2         num_annotations;
		annotation annotations[num_annotations];
	} parameter_annotations[num_parameters];
}
*/
struct RuntimeVisibleParameterAnnotations_attribute {
	// TODO
};
typedef struct RuntimeVisibleParameterAnnotations_attribute RuntimeVisibleParameterAnnotations_attribute;

/*
RuntimeInvisibleParameterAnnotations_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u1 num_parameters;
	{ u2         num_annotations;
		annotation annotations[num_annotations];
	} parameter_annotations[num_parameters];
}
*/
struct RuntimeInvisibleParameterAnnotations_attribute {
	// TODO
};
typedef struct RuntimeInvisibleParameterAnnotations_attribute RuntimeInvisibleParameterAnnotations_attribute;

/*
AnnotationDefault_attribute {
	u2            attribute_name_index;
	u4            attribute_length;
	element_value default_value;
}*/
struct AnnotationDefault_attribute {
	// TODO
};
typedef struct AnnotationDefault_attribute AnnotationDefault_attribute;

/*
BootstrapMethods_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 num_bootstrap_methods;
	{ u2 bootstrap_method_ref;
		u2 num_bootstrap_arguments;
		u2 bootstrap_arguments[num_bootstrap_arguments];
	} bootstrap_methods[num_bootstrap_methods];
}
*/
struct BootstrapMethods_attribute {
	// TODO
};
typedef struct BootstrapMethods_attribute BootstrapMethods_attribute;

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
