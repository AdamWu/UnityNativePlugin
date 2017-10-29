/*                                                   
 * NativePluginCPP.cpp              
 *                                                                                                                                                    
 * Author: AdamWu (calvinmankor@gmail.com)                                                     
 *                                                          
 * Native Plugin for Unity. (Encrypt & Decrypt)                              
 *                                                          
 */

#include <string.h>
#include <malloc.h>
#include "NativePluginCPP.h"
#include "xxtea/xxtea.h"

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

float UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API TestMultiply(float a, float b)
{
    return a * b;
}



int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Encrypt(void* data, size_t inlen, void **result)
{
	size_t len;
	char *__ = _();
	*result = xxtea_encrypt(data, inlen, key, &len);
	free(__);
	return len;
}

int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Decrypt(void* data, size_t inlen, void **result) 
{
	size_t len;
	char *__ = _();
	*result = xxtea_decrypt(data, inlen, key, &len);
	free(__);
	return len;
}

int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API FreeMem(void** p)
{
	size_t size = _msize(*p);
	free(*p);
	*p = NULL;
	return size;
}