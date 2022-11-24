#pragma once
#define _USE_MATH_DEFINES
#include <math.h>



char* analyzeTriangle(int side1, int side2, int side3);
void calculate_inside_angles(int a, int b, int c, double* res);
bool vaild_triangle(int side1, int side2, int side3);