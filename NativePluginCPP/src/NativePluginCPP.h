#include <stdlib.h>

#if defined(__CYGWIN32__)
	#define UNITY_INTERFACE_API __stdcall
	#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY)
	#define UNITY_INTERFACE_API __stdcall
	#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(__MACH__) || defined(__ANDROID__) || defined(__linux__) || defined(__QNX__)
	#define UNITY_INTERFACE_API
	#define UNITY_INTERFACE_EXPORT
#else
	#define UNITY_INTERFACE_API
	#define UNITY_INTERFACE_EXPORT
#endif

extern "C" float UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API TestMultiply(float a, float b);
		
extern "C" int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Encrypt(char* data, size_t len, void **result);
extern "C" int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Decrypt(char* data, size_t len, void **result);
extern "C" int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API FreeMem(void** p);
