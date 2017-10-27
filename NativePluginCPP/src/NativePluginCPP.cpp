/*                                                   
 * NativePluginCPP.cpp              
 *                                                                                                                                                    
 * Author: AdamWu (calvinmankor@gmail.com)                                                     
 *                                                          
 * Native Plugin for Unity. (Encrypt & Decrypt)                              
 *                                                          
 */

#include <string.h>
#include "NativePluginCPP.h"
#include "xxtea.h"

const char* key = "yysmart";

#define _T_(s, i) do{\
	s ^= (*(key + (i%6)));\
}while(0)

char* _() {
	char __[] = {'c', '?', ' '};
	int ___ = 0;
	while(__[___] != 0){
		_T_(__[___], ___);
		__[___] ^= 0xf1;
		___++;
	}
	return __;
}

float UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API TestMultiply(float a, float b)
{
    return a * b;
}



int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Encrypt(char* data, size_t inlen, void **result)
{
	size_t len;
	*result = xxtea_encrypt(data, inlen, _(), &len);
	return len;
}

int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Decrypt(char* data, size_t inlen, void **result) 
{
	size_t len;
	*result = xxtea_decrypt(data, inlen, _(), &len);
	return len;
}

int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API FreeMem(void** p)
{
	size_t size = _msize(*p);
	free(*p);
	*p = NULL;
	return size;
}