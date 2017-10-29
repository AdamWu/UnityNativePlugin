// Test.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <string.h>
#include "../src/NativePluginCPP.h"

#if defined(_MSC_VER) && _MSC_VER < 1600
typedef unsigned __int8 uint8_t;
typedef unsigned __int32 uint32_t;
#else
#if defined(__FreeBSD__) && __FreeBSD__ < 5
/* FreeBSD 4 doesn't have stdint.h file */
#include <inttypes.h>
#else
#include <stdint.h>
#endif
#endif

#define FIXED_KEY \
    size_t i;\
    uint8_t fixed_key[16];\
    memcpy(fixed_key, key, 16);\
    for (i = 0; (i < 16) && (fixed_key[i] != 0); ++i);\
    for (++i; i < 16; ++i) fixed_key[i] = 0;\

unsigned char key[] = "yysmart";

#define _T_(s, i) do{\
	s ^= (*(key + (i%7)));\
}while(0)

char* _() {
	char* __ = (char*)malloc(17 * sizeof(char));
	memset(__, 0, 17);
	__[0] = 'C';__[1] = '?';__[2] = '3';__[3] = 'w';__[4] = 'u';__[5] = '>';__[6] = '#';__[7] = '8';
	__[8] = 'j';__[9] = ';';__[10] = 'H';__[11] = '^';__[12] = '-';__[13] = 'S';__[14] = '[';__[15] = ']';
	int ___ = 0;
	while(__[___] != 0){
		_T_(__[___], ___);
		__[___] ^= 0x1f; 
		___++;
	}
	return __;
}

int main(int argc, char* argv[])
{
	char* key = _();
	size_t len = strlen((const char*)key);
	printf((const char*)key);

	size_t i;
    uint8_t fixed_key[16];
    memcpy(fixed_key, key, 16);
    for (i = 0; (i < 16) && (fixed_key[i] != 0); ++i);
    for (++i; i < 16; ++i) fixed_key[i] = 0;
		
	free(key);

	len = strlen((const char*)fixed_key);
	printf((const char*)fixed_key);

	return 0;
}

