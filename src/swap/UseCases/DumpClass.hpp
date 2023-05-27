#pragma once

#include <stdio.h>
#include "Core/Core.hpp"
#include "Domain/Entities/JavaClass.hpp"
#include "Domain/Entities/ConstantPool.hpp"
#include "Domain/Entities/AttributeInfo.hpp"
#include "Domain/Entities/FieldInfo.hpp"

struct DumpClassParams {
	JavaClass* javaClass;
	FILE *fp;
};

class DumpClass : public UseCase<void, DumpClassParams> {
 public:
	DumpClass() { }
	virtual ~DumpClass() { }

	virtual void operator()(const DumpClassParams& params) {
		auto javaClass = params.javaClass;
		auto fp = params.fp;

		fprintf(fp, "magic: %x\n", javaClass->magic);
		fprintf(fp, "minor_version: %u\n", javaClass->minor_version);
		fprintf(fp, "major_version: %u\n", javaClass->major_version);
		fprintf(fp, "constant_pool_count: %u\n", javaClass->constant_pool_count);
		fprintf(fp, "constant_pool:\n");
		for (int i = 0; i < javaClass->constant_pool_count - 1; i++) {
			ConstantPoolInfo *cp_info = javaClass->constant_pool[i];
			char* str = ConstantPoolInfo_to_str(cp_info);
			fprintf(fp, "   #%d = %s\n",
				(i + 1),
				// ConstantPool_tag_to_str(cp_info->tag),
				str
			);
			free(str);
		}
		fprintf(fp, "access_flags: %u\n", javaClass->access_flags);
		fprintf(fp, "this_class: %u\n", javaClass->this_class);
		fprintf(fp, "super_class: %u\n", javaClass->super_class);
		fprintf(fp, "interfaces_count: %u\n", javaClass->interfaces_count);
		fprintf(fp, "interfaces: [");
		for (int i = 0; i < javaClass->interfaces_count; i++) {
			fprintf(fp, "%u, ", javaClass->interfaces[i]);
		}
		fprintf(fp, "]\n");
		fprintf(fp, "fields_count: %u\n", javaClass->fields_count);
		fprintf(fp, "fields:\n");
		for (int i = 0; i < javaClass->fields_count; i++) {
			FieldInfo *field = javaClass->fields[i];
			char* str = FieldInfo_to_str(field);
			fprintf(fp, "\t #%d: field: %s\n",
				(i + 1),
				str
			);
			free(str);
		}
	}

};