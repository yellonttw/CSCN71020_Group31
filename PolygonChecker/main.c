#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			double res[3];
			if (vaild_triangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]))
			{
				printf_s("Angles:\n");
				calculate_inside_angles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], res);
				printf_s("%lf %lf %lf\n", res[0], res[1], res[2]);
			}

			break;
		case 0:
			continueProgram = false;
			break;

		case 2:
			printf_s("Recentangle selected.\n");
			int point1[8] = { 0,0,0,0,0,0,0,0 };
			double range;
			double circumference;
			int* coordinates = getpoints(point1);
			analyzeRecentangle(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5], coordinates[6], coordinates[7]);
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int* getpoints(int* points) {
	printf_s("Enter the 4 point Coordinates in order: ");
	for (int i = 0; i < 8; i++)
	{
		scanf_s("%d", &points[i]);
	}
	return points;
}

