#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"
//Need add one more judgment to determain two sides add together need to bigger than the third side in the triangleSolver.c file.

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if ((side1 <= 0 || side2 <= 0 || side3 <= 0) || (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2))
	{
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) 
	{
		result = "Equilateral triangle";
	}
	//this function didn't judgment the side2 equal the side3
	else if ((side1 == side2) || (side2 == side3) || (side3 == side1))
	{
		result = "Isosceles triangle";
	}
	else 
	{
		result = "Scalene triangle";
	}

	return result;
}

void calculate_inside_angles(int a, int b, int c, double* res)
{
	double cosA, cosB, cosC;
	cosA = (c * c + b * b - a * a) / (2.0f * b * c);
	cosB = (a * a + c * c - b * b) / (2.0f * a * c);
	cosC = (a * a + b * b - c * c) / (2.0f * a * b);

	res[0] = (acos(cosA) / M_PI) * 180;
	res[1] = (acos(cosB) / M_PI) * 180;
	res[2] = (acos(cosC) / M_PI) * 180;
}

bool vaild_triangle(int side1, int side2, int side3)
{
	if ((side1 <= 0 || side2 <= 0 || side3 <= 0) || (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2))
	{
		return false;
	}
	return true;
}