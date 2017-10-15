#include "NativePluginCPP.h"

extern "C" {
    float TestMultiply(float a, float b)
    {
        return a * b;
    }
}