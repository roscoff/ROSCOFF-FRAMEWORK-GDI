#pragma once
#include "utilities.h"

float linearInterpolation(float v1, float v2, float val) {
    return (v2 - v1) * val + v1;
};