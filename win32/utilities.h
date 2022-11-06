#pragma once
#include <windows.h>

struct color {
	byte r, g, b, a;
};

struct point {
	int x, y;
};

template<typename T> void swapvalue(T& v1, T& v2);

float linearInterpolation(float v1, float v2, float val);

template<typename T>
inline void swapvalue(T& v1, T& v2){
    T tmp = v1;
    v1 = v2;
    v2 = tmp;
}

