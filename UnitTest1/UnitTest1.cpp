#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.3_rec/7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 3;
			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[n];
			}

			matrix[0][0] = 3; matrix[0][1] = 2; matrix[0][2] = -1;
			matrix[1][0] = 4; matrix[1][1] = 1; matrix[1][2] = 5;
			matrix[2][0] = -2; matrix[2][1] = 6; matrix[2][2] = 0;

			SortDiagonal(matrix, n);

			Assert::AreEqual(matrix[0][0], 3);
			Assert::AreEqual(matrix[1][1], 1);
			Assert::AreEqual(matrix[2][2], 0);

			for (int i = 0; i < n; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
