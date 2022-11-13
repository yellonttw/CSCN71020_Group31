#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Triangle_case1)
			//If a value less than or equal to 0 is entered, "Not a triangle" will be output,because the side length must be greater than 0
		{
			char Result[25];
			strcpy_s(Result, analyzeTriangle(-1, 3, 2));
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(Triangle_case2)
		{
			//If the three sides are equal, the output will be "equilateral triangle"
			char Result[25];
			strcpy_s(Result, analyzeTriangle(3, 3, 3));
			Assert::AreEqual("Equilateral triangle", Result);
		}
		TEST_METHOD(Triangle_case3)
			//Two sides are equal but not equal to the third side, the output will be "Isosceles triangle"
		{
			char Result[25];
			strcpy_s(Result, analyzeTriangle(3, 3, 2));
			Assert::AreEqual("Isosceles triangle", Result);
		}
		TEST_METHOD(Triangle_case4)
		{
			//If all three sides are not equal and the sum of two sides is equal to the third side, "not a triangle" should be output, because the sum of two sides must greater than the third side
			char Result[25];
			strcpy_s(Result, analyzeTriangle(2, 3, 5));
			Assert::AreEqual("Not a triangle", Result);
		}
		
		TEST_METHOD(Triangle_case5)
			//If all three sides are not equal and the sum of the two sides is greater than the third side, "Scalene triangle" will be output
		{
			char Result[25];
			strcpy_s(Result, analyzeTriangle(3, 4, 5));
			Assert::AreEqual("Scalene triangle", Result);
		}
	};
}
