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
	double lineA, lineB, lineC, lineD, lineE, lineF;
	double range, circumference;
	double line[6] = { 0.0,0.0,0.0,0.0,0.0,0.0};
	calculatelength(p1, p2, p3, p4, p5, p6, p7, p8,line);
	
	lineA = line[0];
	lineB = line[1];
	lineC = line[2];
	lineD = line[3];
	lineE = line[4];
	lineF = line[5];
	
	if (judgerectangle(lineA, lineB, lineC, lineD, lineE, lineF))
	{
		range = calculaterange(lineA, lineB);
		circumference = calculatecircumference(lineA, lineB, lineC, lineD);
		printf("It is a rectangle.\n");
		printf("Range = %f\n", range);
		printf("Circumference = %f\n", circumference);

	}
	else
	{
		circumference = calculatecircumference(lineA, lineB, lineC, lineD);
		printf("It is not a rectangle.\n");
		printf("Circumference = %f\n", circumference);

	}
}
		
bool analyzerightangle(double line1, double line2, double line3)
{
	float a = line1 * line1;
	float b = line2 * line2;
	float c = line3 * line3;
	/*
	int a = s1;
	int b = s2;
	int c = s3;
	*/
	if (a == 0 && b == 0 && c == 0)
	{
		return false;
	}
	if ((a + b == c)|| (a + c == b) || (b + c == a))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}


void calculatelength(int p1, int p2, int p3, int p4,int p5,int p6,int p7,int p8,double* r)
{
	r[0] = sqrt((p3 - p1) * (p3 - p1) + (p4 - p2) * (p4 - p2));
	r[1] = sqrt((p5 - p3) * (p5 - p3) + (p6 - p4) * (p6 - p4));
	r[2] = sqrt((p7 - p5) * (p7 - p5) + (p8 - p6) * (p8 - p6));
	r[3] = sqrt((p1 - p7) * (p1 - p7) + (p2 - p8) * (p2 - p8));
	r[4] = sqrt((p5 - p1) * (p5 - p1) + (p6 - p2) * (p6 - p2));
	r[5] = sqrt((p7 - p3) * (p7 - p3) + (p8 - p4) * (p8 - p4));
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

bool judgerectangle(double a, double b, double c, double d, double e, double f)
{
	int judge;
	if (analyzerightangle(a, b, e) && analyzerightangle(a, b, f) && analyzerightangle(c, d, f) && analyzerightangle(b, c, e))
	{
		return true;
	}
	else
	{
		return false;
	}

}