#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Core/Core.h"
#include "Domain/Entities/AttributeInfo.h"

struct AttributeInfo;
typedef struct AttributeInfo AttributeInfo;

/*
Attribute types:
 - ConstantValue
 - Code
 - StackMapTable
 - Exceptions
 - InnerClasses
 - EnclosingMethod
 - Synthetic
 - Signature
 - SourceFile
 - SourceDebugExtension
 - LineNumberTable
 - LocalVariableTable
 - LocalVariableTypeTable
 - Deprecated
 - RuntimeVisibleAnnotations
 - RuntimeInvisibleAnnotations
 - RuntimeVisibleParameterAnnotations
 - RuntimeInvisibleParameterAnnotations
 - AnnotationDefault
 - BootstrapMethods
*/

/*
ConstantValue_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 constantvalue_index;
}
*/
/*
Constant bindings: 
 - long	CONSTANT_Long
 - float	CONSTANT_Float
 - double	CONSTANT_Double
 - int, short, char, byte, boolean	CONSTANT_Integer
 - String	CONSTANT_String
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

Code_attribute *createCodeAttribute() {
	Code_attribute *code_attribute = (Code_attribute*)malloc(sizeof(Code_attribute));
	return code_attribute;
}

void deleteCodeAttribute(Code_attribute *code_attribute) {
	if (code_attribute->code != NULL) {
		free(code_attribute->code);
	}
	if (code_attribute->exception_table != NULL) {
		for (int i = 0; i < code_attribute->exception_table_length; i++) {
			free(code_attribute->exception_table[i]);
		}
	}
	if (code_attribute->attributes != NULL) {
		for (int i = 0; i < code_attribute->attributes_count; i++) {
			free(code_attribute->attributes[i]);
		}
	}
	free(code_attribute);
}

/*
StackMapTable_attribute {
	u2              attribute_name_index;
	u4              attribute_length;
	u2              number_of_entries;
	stack_map_frame entries[number_of_entries];
}

union stack_map_frame {
	same_frame;
	same_locals_1_stack_item_frame;
	same_locals_1_stack_item_frame_extended;
	chop_frame;
	same_frame_extended;
	append_frame;
	full_frame;
}

same_frame {
	u1 frame_type = SAME; // 0-63 
}

same_locals_1_stack_item_frame {
	u1 frame_type = SAME_LOCALS_1_STACK_ITEM; // 64-127 
	verification_type_info stack[1];
}

same_locals_1_stack_item_frame_extended {
	u1 frame_type = SAME_LOCALS_1_STACK_ITEM_EXTENDED; // 247 
	u2 offset_delta;
	verification_type_info stack[1];
}

chop_frame {
	u1 frame_type = CHOP; // 248-250 
	u2 offset_delta;
}

same_frame_extended {
	u1 frame_type = SAME_FRAME_EXTENDED; // 251 
	u2 offset_delta;
}

append_frame {
	u1 frame_type = APPEND; // 252-254
	u2 offset_delta;
	verification_type_info locals[frame_type - 251];
}
locals:
	Top_variable_info
	Integer_variable_info
	Float_variable_info
	Null_variable_info
	UninitializedThis_variable_info
	Object_variable_info
	Uninitialized_variable_info

full_frame {
	u1 frame_type = FULL_FRAME; // 255 
	u2 offset_delta;
	u2 number_of_locals;
	verification_type_info locals[number_of_locals];
	u2 number_of_stack_items;
	verification_type_info stack[number_of_stack_items];
}

union verification_type_info {
	Top_variable_info;
	Integer_variable_info;
	Float_variable_info;
	Long_variable_info;
	Double_variable_info;
	Null_variable_info;
	UninitializedThis_variable_info;
	Object_variable_info;
	Uninitialized_variable_info;
}

Top_variable_info {
	u1 tag = ITEM_Top; // 0 
}

Integer_variable_info {
	u1 tag = ITEM_Integer; // 1 
}

Float_variable_info {
	u1 tag = ITEM_Float; // 2 
}

Long_variable_info {
	u1 tag = ITEM_Long; // 4 
}

Double_variable_info {
	u1 tag = ITEM_Double; // 3 
}

Null_variable_info {
	u1 tag = ITEM_Null; // 5 
}

UninitializedThis_variable_info {
	u1 tag = ITEM_UninitializedThis; // 6 
}

Object_variable_info {
	u1 tag = ITEM_Object; // 7 
	u2 cpool_index;
}

Uninitialized_variable_info {
	u1 tag = ITEM_Uninitialized // 8 
	u2 offset;
}

*/

enum verification_type_info_tag {
	ITEM_Top = 0,
	ITEM_Integer = 1,
	ITEM_Float = 2,
	ITEM_Long = 4,
	ITEM_Double = 3,
	ITEM_Null = 5,
	ITEM_UninitializedThis = 6,
	ITEM_Object = 7,
	ITEM_Uninitialized = 8 ,
};
typedef enum verification_type_info_tag verification_type_info_tag;

struct Top_variable_info {
};

struct Integer_variable_info {
};

struct Float_variable_info {
};

struct Long_variable_info {
};

struct Double_variable_info {
};

struct Null_variable_info {
};

struct UninitializedThis_variable_info {
};

struct Object_variable_info {
	u16 cpool_index;
};

struct Uninitialized_variable_info {
	u16 offset;
};

struct verification_type_info {
	u8 tag;
	union {
		Top_variable_info top_variable_info;
		Integer_variable_info integer_variable_info;
		Float_variable_info float_variable_info;
		Long_variable_info long_variable_info;
		Double_variable_info double_variable_info;
		Null_variable_info null_variable_info;
		UninitializedThis_variable_info uninitializedThis_variable_info;
		Object_variable_info object_variable_info;
		Uninitialized_variable_info uninitialized_variable_info;
	};
	
};
typedef struct verification_type_info verification_type_info;

enum frame_type_enum {
	SAME, // 0-63
	SAME_LOCALS_1_STACK_ITEM, // 64-127
	SAME_LOCALS_1_STACK_ITEM_EXTENDED, // 247 
	CHOP, // 248-250
	SAME_FRAME_EXTENDED, // 251 
	APPEND, // 252-254
	FULL_FRAME, // 255 
};
typedef enum frame_type_enum frame_type_enum;

#define in_range(v, min, max) \
	(v) >= (min) && (v) <= (max)

frame_type_enum frame_type_from_byte(byte ft) {
	if (in_range(ft, 0, 63)) {
		return SAME;
	}
	else if (in_range(ft, 64, 127)) {
		return SAME_LOCALS_1_STACK_ITEM;
	}
	else if (ft == 247) {
		return SAME_LOCALS_1_STACK_ITEM_EXTENDED;
	}
	else if (in_range(ft, 248, 250)) {
		return CHOP;
	}
	else if (ft == 251) {
		return SAME_FRAME_EXTENDED;
	}
	else if (in_range(ft, 252, 254)) {
		return APPEND;
	}
	else if (ft == 255) {
		return FULL_FRAME;
	}
	else {
		// TODO: to manage errors
		exit(-1);
	}
}

#undef in_range

struct same_frame {
};
typedef struct same_frame same_frame;

struct same_locals_1_stack_item_frame {
	verification_type_info stack[1];
};
typedef struct same_locals_1_stack_item_frame same_locals_1_stack_item_frame;

struct same_locals_1_stack_item_frame_extended {
	u16 offset_delta;
	verification_type_info stack[1];
};
typedef struct same_locals_1_stack_item_frame_extended same_locals_1_stack_item_frame_extended;

struct chop_frame {
	u16 offset_delta;
};
typedef struct chop_frame chop_frame;

struct same_frame_extended {
	u16 offset_delta;
};
typedef struct same_frame_extended same_frame_extended;

struct append_frame {
	u16 offset_delta;
	verification_type_info *locals; //[frame_type - 251];
};
typedef struct append_frame append_frame;

struct full_frame {
	u16 offset_delta;
	u16 number_of_locals;
	verification_type_info *locals;
	u16 number_of_stack_items;
	verification_type_info *stack;
};
typedef struct full_frame full_frame;

struct stack_map_frame {
	u8 frame_type;
	union {
		same_frame same_frame_v;
		same_locals_1_stack_item_frame same_locals_1_stack_item_frame_v;
		same_locals_1_stack_item_frame_extended same_locals_1_stack_item_frame_extended_v;
		chop_frame chop_frame_v;
		same_frame_extended same_frame_extended_v;
		append_frame append_frame_v;
		full_frame full_frame_v;
	};
};
typedef struct stack_map_frame stack_map_frame;

struct StackMapTable_attribute {
	u16 number_of_entries;
	stack_map_frame *entries;
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
	u16 number_of_exceptions;
	u16 *exception_index_table;
};
typedef struct Exceptions_attribute Exceptions_attribute;

Exceptions_attribute *createExceptionsAttribute() {
	Exceptions_attribute *exceptions_attribute = (Exceptions_attribute*)malloc(sizeof(Exceptions_attribute));
	return exceptions_attribute;
}

void deleteExceptionsAttribute(Exceptions_attribute *exceptions_attribute) {
	if (exceptions_attribute->exception_index_table != NULL) {
		free(exceptions_attribute->exception_index_table);
	}
	free(exceptions_attribute);
}

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

struct InnerClass {
	u16 inner_class_info_index;
	u16 outer_class_info_index;
	u16 inner_name_index;
	u16 inner_class_access_flags;
};
typedef struct InnerClass InnerClass;

struct InnerClasses_attribute {
	u16 number_of_classes;
	InnerClass *classes;
};
typedef struct InnerClasses_attribute InnerClasses_attribute;

InnerClasses_attribute *createInnerClassesAttribute() {
	InnerClasses_attribute *innerClasses_attribute = (InnerClasses_attribute*)malloc(sizeof(InnerClasses_attribute));
	return innerClasses_attribute;
}

void deleteInnerClassesAttribute(InnerClasses_attribute *innerClasses_attribute) {
	if (innerClasses_attribute->classes != NULL) {
		free(innerClasses_attribute->classes);
	}
	free(innerClasses_attribute);
}

/*
EnclosingMethod_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 class_index;
	u2 method_index;
}
*/
struct EnclosingMethod_attribute {
	u16 class_index;
	u16 method_index;
};
typedef struct EnclosingMethod_attribute EnclosingMethod_attribute;

/*
Synthetic_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
}
*/
struct Synthetic_attribute {
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
	u16 signature_index;
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
	u16 sourcefile_index;
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
	u8 *debug_extension;
};
typedef struct SourceDebugExtension_attribute SourceDebugExtension_attribute;

SourceDebugExtension_attribute *createSourceDebugExtensionAttribute() {
	SourceDebugExtension_attribute *sourceDebugExtension_attribute = (SourceDebugExtension_attribute*)malloc(sizeof(SourceDebugExtension_attribute));
	return sourceDebugExtension_attribute;
}

void deleteSourceDebugExtensionAttribute(SourceDebugExtension_attribute *sourceDebugExtension_attribute) {
	if (sourceDebugExtension_attribute->debug_extension != NULL) {
		free(sourceDebugExtension_attribute->debug_extension);
	}
	free(sourceDebugExtension_attribute);
}

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

struct line_number_table_row {
	u16 start_pc;
	u16 line_number;	
};
typedef struct line_number_table_row line_number_table_row;

struct LineNumberTable_attribute {
	u16 line_number_table_length;
	line_number_table_row *line_number_table;
};
typedef struct LineNumberTable_attribute LineNumberTable_attribute;

LineNumberTable_attribute *createLineNumberTableAttribute() {
	LineNumberTable_attribute *lineNumberTable_attribute = (LineNumberTable_attribute*)malloc(sizeof(LineNumberTable_attribute));
	return lineNumberTable_attribute;
}

void deleteLineNumberTableAttribute(LineNumberTable_attribute *lineNumberTable_attribute) {
	if (lineNumberTable_attribute->line_number_table != NULL) {
		free(lineNumberTable_attribute->line_number_table);
	}
	free(lineNumberTable_attribute);
}

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

struct local_variable_table_row {
	u16 start_pc;
	u16 length;
	u16 name_index;
	u16 descriptor_index;
	u16 index;
};
typedef struct local_variable_table_row local_variable_table_row;

struct LocalVariableTable_attribute {
	u16 local_variable_table_length;
	local_variable_table_row *local_variable_table;
};
typedef struct LocalVariableTable_attribute LocalVariableTable_attribute;

LocalVariableTable_attribute *createLocalVariableTableAttribute() {
	LocalVariableTable_attribute *localVariableTable_attribute = (LocalVariableTable_attribute*)malloc(sizeof(LocalVariableTable_attribute));
	return localVariableTable_attribute;
}

void deleteLocalVariableTableAttribute(LocalVariableTable_attribute *localVariableTable_attribute) {
	if (localVariableTable_attribute->local_variable_table != NULL) {
		free(localVariableTable_attribute->local_variable_table);
	}
	free(localVariableTable_attribute);
}

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
struct local_variable_type_table_row {
	u16 start_pc;
	u16 length;
	u16 name_index;
	u16 signature_index;
	u16 index;
};
typedef struct local_variable_type_table_row local_variable_type_table_row;

struct LocalVariableTypeTable_attribute {
	u16 local_variable_type_table_length;
	local_variable_type_table_row *local_variable_type_table;
};
typedef struct LocalVariableTypeTable_attribute LocalVariableTypeTable_attribute;

LocalVariableTypeTable_attribute *createLocalVariableTypeTableAttribute() {
	LocalVariableTypeTable_attribute *localVariableTypeTable_attribute = (LocalVariableTypeTable_attribute*)malloc(sizeof(LocalVariableTypeTable_attribute));
	return localVariableTypeTable_attribute;
}

void deleteLocalVariableTypeTableAttribute(LocalVariableTypeTable_attribute *localVariableTypeTable_attribute) {
	if (localVariableTypeTable_attribute->local_variable_type_table != NULL) {
		free(localVariableTypeTable_attribute->local_variable_type_table);
	}
	free(localVariableTypeTable_attribute);
}
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
annotation {
	u2 type_index;
	u2 num_element_value_pairs;
	{ u2 element_name_index;
		element_value value;
	} element_value_pairs[num_element_value_pairs];
}

element_value {
	u1 tag;
	union {
		u2 const_value_index;

		{ u2 type_name_index;
			u2 const_name_index;
		} enum_const_value;

		u2 class_info_index;

		annotation annotation_value;

		{ u2 num_values;
			element_value values[num_values];
		} array_value;
	} value;
}

tag Value	-> Element Type
s	String
e	enum constant
c	class
@	annotation type
[	array
*/
struct annotation;
struct element_value;

struct enum_const_value_t {
	u16 type_name_index;
	u16 const_name_index;
};

struct array_value_t {
	u16 num_values;
	element_value *values; //[num_values];
};

struct element_value {
	u8 tag;
	union {
		u16 const_value_index;
		enum_const_value_t enum_const_value;
		u16 class_info_index;
		annotation *annotation_value;
		array_value_t array_value;
	} value;
};

struct element_value_pair {
	u16 element_name_index;
	element_value value;
};

struct annotation {
	u16 type_index;
	u16 num_element_value_pairs;
	element_value_pair *element_value_pairs;
};

/*
RuntimeVisibleAnnotations_attribute {
	u2         attribute_name_index;
	u4         attribute_length;
	u2         num_annotations;
	annotation annotations[num_annotations];
}
*/
struct RuntimeVisibleAnnotations_attribute {
	u16 num_annotations;
	annotation *annotations; //[num_annotations];
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
	u16 num_annotations;
	annotation *annotations; //[num_annotations];
};
typedef struct RuntimeInvisibleAnnotations_attribute RuntimeInvisibleAnnotations_attribute;

struct parameter_annotation {
	u16 num_annotations;
	annotation *annotations; //[num_annotations];
};

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
	u8 num_parameters;
	parameter_annotation *parameter_annotations; //[num_parameters];
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
	u8 num_parameters;
	parameter_annotation *parameter_annotations; //[num_parameters];
};
typedef struct RuntimeInvisibleParameterAnnotations_attribute RuntimeInvisibleParameterAnnotations_attribute;

/*
AnnotationDefault_attribute {
	u2            attribute_name_index;
	u4            attribute_length;
	element_value default_value;
}
*/
struct AnnotationDefault_attribute {
	element_value default_value;
};
typedef struct AnnotationDefault_attribute AnnotationDefault_attribute;

struct bootstrap_method {
	u16 bootstrap_method_ref;
	u16 num_bootstrap_arguments;
	u16 *bootstrap_arguments; //[num_bootstrap_arguments];
};

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
	u16 num_bootstrap_methods;
	bootstrap_method *bootstrap_methods;
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
	union {
		// Old usage
		u8 *info;
		// New usage
		ConstantValue_attribute *constantValue;
		Code_attribute *code;
		StackMapTable_attribute *stackMapTable;
		Exceptions_attribute *exceptions;
		InnerClasses_attribute *innerClasses;
		EnclosingMethod_attribute *enclosingMethod;
		Synthetic_attribute *synthetic;
		Signature_attribute *signature;
		SourceFile_attribute *sourceFile;
		SourceDebugExtension_attribute *sourceDebugExtension;
		LineNumberTable_attribute *sineNumberTable;
		LocalVariableTable_attribute *localVariableTable;
		LocalVariableTypeTable_attribute *localVariableTypeTable;
		Deprecated_attribute *deprecated;
		RuntimeVisibleAnnotations_attribute *runtimeVisibleAnnotations;
		RuntimeInvisibleAnnotations_attribute *runtimeInvisibleAnnotations;
		RuntimeVisibleParameterAnnotations_attribute *runtimeVisibleParameterAnnotations;
		RuntimeInvisibleParameterAnnotations_attribute *runtimeInvisibleParameterAnnotations;
		AnnotationDefault_attribute *annotationDefault;
		BootstrapMethods_attribute *bootstrapMethods;
	};
	
};

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
	asprintf(&str, "Attribute name_index=%d, attribute_length=%d, info=TODO!()", ai->attribute_name_index, ai->attribute_length);
	return str;
}
