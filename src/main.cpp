#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Domain/Domain.h"
#include "Container.h"

int main(int argc, char **argv) {
	using namespace Container;
	
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

	dumpClass({
		.javaClass = loadedClass, 
		.fp = stdout
	});

	deleteJavaClass(loadedClass);

	return 0;
}