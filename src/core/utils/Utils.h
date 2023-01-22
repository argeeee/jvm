#pragma once
#include <stdlib.h>

typedef u_int8_t 	byte;
typedef u_int8_t 	u8;
typedef u_int16_t u16;
typedef u_int32_t u32; 
typedef u_int64_t u64;

u16 reverse_2_bytes(u16 bytes) {
	u16 aux = 0;
	u8 byte;

	for(int i = 0; i < 16; i += 8) {
		byte = (bytes >> i) & 0xff;
		aux |= byte << (16 - 8 - i);
	}
	return aux;
}

u32 reverse_4_bytes(u32 bytes) {
	u32 aux = 0;
	u8 byte;

	for(int i = 0; i < 32; i += 8) {
		byte = (bytes >> i) & 0xff;
		aux |= byte << (32 - 8 - i);
	}
	return aux;
}

