#include "pch.h"
#include "CppUnitTest.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" void calculatelength(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, double* r); 
extern "C" bool judgerectangle(double a, double b, double c, double d, double e, double f);

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double line[6];
			int point[8] = { 0,1,1,0,2,1,1,2 };
			calculatelength(point[0], point[1], point[2], point[3], point[4], point[5], point[6], point[7], line);
			Assert::IsTrue(judgerectangle(line[0], line[1], line[2], line[3], line[4], line[5]));
		}

		TEST_METHOD(TestMethod2)
		{
			double line[6];
			int point[8] = { 0,0,1,0,1,2,0,2 };
			calculatelength(point[0], point[1], point[2], point[3], point[4], point[5], point[6], point[7], line);
			Assert::IsTrue(judgerectangle(line[0], line[1], line[2], line[3], line[4], line[5]));
		}

		TEST_METHOD(TestMethod3)
		{
			double line[6];
			int point[8] = { 2,1,3,4,5,6,3,2 };
			calculatelength(point[0], point[1], point[2], point[3], point[4], point[5], point[6], point[7], line);
			Assert::IsFalse(judgerectangle(line[0], line[1], line[2], line[3], line[4], line[5]));
		}
	};
}
