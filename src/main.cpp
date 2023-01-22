#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "domain/domain.h"

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
	deleteJavaClass(loadedClass);
}