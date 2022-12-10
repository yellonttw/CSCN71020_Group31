#pragma once
#define _USE_MATH_DEFINES
#include <math.h>



char* analyzeTriangle(int side1, int side2, int side3);
void calculate_inside_angles(int a, int b, int c, double* res);
bool vaild_triangle(int side1, int side2, int side3);
void analyzeRecentangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
bool analyzerightangle(double line1, double line2, double line3);
void calculatelength(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, double* r);
double calculatecircumference(double a, double b, double c, double d);
double calculaterange(double a, double b);
bool judgerectangle(double a, double b, double c, double d, double e, double f);