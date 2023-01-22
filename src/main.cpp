#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Domain/Domain.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("usage: %s <pathToClassFile>\n", argv[0]);
		exit(1);
	}

	char *className = argv[1];
	JavaClass *loadedClass = loadClass(className);
	if (loadedClass == NULL) {
		printf("error: cannot validate class filefile\n");
		exit(2);
	}

	printf("magic: %x\n", loadedClass->magic);
	printf("minor_version: %u\n", loadedClass->minor_version);
	printf("major_version: %u\n", loadedClass->major_version);
	printf("constant_pool_count: %u\n", loadedClass->constant_pool_count);
	printf("constant_pool:\n");
	for (int i = 0; i < loadedClass->constant_pool_count - 1; i++) {
		ConstantPoolInfo *cp_info = loadedClass->constant_pool[i];
		char* str = ConstantPoolInfo_to_str(cp_info);
		printf("\t #%d: cp_info(tag=%s) info: %s\n",
			(i + 1),
			ConstantPool_tag_to_str(cp_info->tag),
			str
		);
		free(str);
	}
	printf("access_flags: %u\n", loadedClass->access_flags);
	printf("this_class: %u\n", loadedClass->this_class);
	printf("super_class: %u\n", loadedClass->super_class);
	printf("interfaces_count: %u\n", loadedClass->interfaces_count);
	printf("interfaces: [");
	for (int i = 0; i < loadedClass->interfaces_count; i++) {
		printf("%u, ", loadedClass->interfaces[i]);
	}
	printf("]\n");
	printf("fields_count: %u\n", loadedClass->fields_count);
	printf("fields:\n");
	for (int i = 0; i < loadedClass->fields_count; i++) {
		FieldInfo *field = loadedClass->fields[i];
		char* str = FieldInfo_to_str(field);
		printf("\t #%d: field: %s\n",
			(i + 1),
			str
		);
		free(str);
	}
	deleteJavaClass(loadedClass);
}