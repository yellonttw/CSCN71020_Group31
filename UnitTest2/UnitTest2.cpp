#include "pch.h"
#include "CppUnitTest.h"

extern "C" void calculate_inside_angles(int , int , int, double*);



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// this testcase is testing the Equilateral triangle function 
			double res[3];
			calculate_inside_angles(3, 3, 3, res);
			int a = res[0];
			int b = res[1];
			int c = res[2];
			Assert::AreEqual(60,a);
			Assert::AreEqual(60,b);
			Assert::AreEqual(60,c);
		}


		TEST_METHOD(TestMethod2)
		{
			// this testcase is testing the Scalene triangle function 
			double res[3];
			calculate_inside_angles(3, 4, 3, res);
			int a = res[0];
			int b = res[1];
			int c = res[2];
			Assert::AreEqual(48, a);
			Assert::AreEqual(83, b);
			Assert::AreEqual(48, c);
		}


		TEST_METHOD(TestMethod3)
		{
			// this testcase is testing the Isosceles triangle function 
			double res[3];
			calculate_inside_angles(3, 4, 5, res);
			int a = res[0];
			int b = res[1];
			int c = res[2];
			Assert::AreEqual(36, a);
			Assert::AreEqual(53, b);
			Assert::AreEqual(90, c);
		}
	};
}
