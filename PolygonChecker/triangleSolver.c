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

void analyzeRecentangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
	char* result = "";
	double lineA, lineB, lineC, lineD, lineE, lineF;
	double range, circumference;
	lineA = calculatelength(p1, p2, p3, p4);
	lineB = calculatelength(p3, p4, p7, p8);
	lineC = calculatelength(p7, p8, p5, p6);
	lineD = calculatelength(p5, p6, p1, p2);
	lineE = calculatelength(p5, p6, p3, p4);
	lineF = calculatelength(p1, p2, p7, p8);
	if (analyzerightangle(lineA,lineD,lineE) && analyzerightangle(lineA, lineB, lineF) && analyzerightangle(lineC, lineD, lineF) && analyzerightangle(lineB, lineC, lineE))
	{
		range = calculaterange(lineA, lineB);
		circumference = calculatecircumference(lineA, lineB, lineC, lineD);
		printf("It is a triangle.\n");
		printf("Range = %f\n", range);
		printf("Circumference = %f\n", circumference);

	}
	else
	{
		circumference = calculatecircumference(lineA, lineB, lineC, lineD);
		printf("It is not a triangle.\n");
		printf("Circumference = %f\n", circumference);

	}
}
		
bool analyzerightangle(double line1, double line2, double line3)
{
	double s1 = line1 * line1;
	double s2 = line2 * line2;
	double s3 = line3 * line3;
	if (s1 == 0 && s2 == 0 && s3 == 0)
	{
		return false;

	}
	if ((s1 + s2 == s3) || (s1 + s3 == s2) || (s2 + s3 == s1))
	{
		return true;
	}
		return false;
	
}


double calculatelength(int x1, int x2, int y1, int y2)
{
	double length;
	length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return length;
}

double calculatecircumference(double a, double b, double c, double d)
{
	double cir = a + b + c + d;
	return cir;
}

double calculaterange(double a, double b)
{
	double ran = a * b;
	return ran;
}
