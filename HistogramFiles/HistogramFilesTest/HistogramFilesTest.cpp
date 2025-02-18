#include "pch.h"
#include "CppUnitTest.h"
#include "../HistogramFilesLib/Data.h"
#include "../HistogramFilesLib/Ranges.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HistogramTest
{
	TEST_CLASS(DataTest)
	{

	public:

		TEST_METHOD(TestGetNumberOfELements)
		{
			vector<int> keys{ 2, 4, 8 };
			vector<float> allDigits{ 2, 4, 4, 8, 8 };
			Data data(keys, allDigits);
			Assert::AreEqual(5, data.GetNumberOfElements());
		}

		TEST_METHOD(TestGetMinimum)
		{
			vector<int> keys{ 2, 4, 8 };
			vector<float> allDigits{ 2, 4, 4, 8, 8 };
			Data data(keys, allDigits);
			Assert::AreEqual(2, data.GetMinimum());
		}

		TEST_METHOD(TestGetMaximum)
		{
			vector<int> keys{ 2, 4, 8 };
			vector<float> allDigits{ 2, 4, 4, 8, 8 };
			Data data(keys, allDigits);
			Assert::AreEqual(8, data.GetMaximum());
		}

		TEST_METHOD(TestGetMedian)
		{
			vector<int> keys{ 2, 4, 8 };
			vector<float> allDigits{ 2, 4, 4, 8, 8 };
			Data data(keys, allDigits);
			float num = 4;
			Assert::AreEqual(num, data.GetMedian());
		}

		TEST_METHOD(TestGetMedian2)
		{
			vector<int> keys{ 2, 4, 8, 9 };
			vector<float> allDigits{ 2, 4, 4, 8, 8, 9 };
			Data data(keys, allDigits);
			float num = 6;
			Assert::AreEqual(num, data.GetMedian());
		}
	};

	TEST_CLASS(RangesTest)
	{
	public:

		TEST_METHOD(TestGetNumRanges)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 1;
			quantityDigits[5] = 1;
			quantityDigits[7] = 1;
			quantityDigits[8] = 1;
			Ranges ranges(quantityDigits, 5);
			Assert::AreEqual(4, ranges.GetNumRanges());
		}

		TEST_METHOD(TestCreateTitle)
		{
			map<int, int> quantityDigits;
			map<string, int>result;
			vector<int>keys{ 1, 5, 7, 8 };
			vector<int>numbers{ 0, 1, 2 };
			string title = "(0-2)";
			Ranges ranges(quantityDigits, 5);
			Assert::AreEqual(title, ranges.CreateTitle(numbers));
		}

		TEST_METHOD(TestSetresultRanges)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 2;
			quantityDigits[5] = 9;
			quantityDigits[7] = 1;
			quantityDigits[8] = 1;
			map<string, int>result;
			vector<int>possibleDigits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			vector<int>lenghtRanges = { 3, 3, 2, 2 };
			vector<int>keys{ 1, 5, 7, 8 };
			Ranges ranges(quantityDigits, 5);
			result = ranges.SetResultRanges(possibleDigits, lenghtRanges);
			Assert::AreEqual(9, result["(3-5)"]);
		}

		TEST_METHOD(TestPlusOperator)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 2;
			quantityDigits[5] = 9;
			map<int, int> quantityDigits2;
			quantityDigits2[1] = 5;
			quantityDigits2[8] = 1;
			Ranges ranges1(quantityDigits, 5);
			Ranges ranges2(quantityDigits2, 5);
			Ranges resultRanges = ranges1 + ranges2;
			Assert::AreEqual(7, resultRanges.GetQuantityDigits()[1]);
		}

		TEST_METHOD(TestMinusOperator)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 5;
			quantityDigits[9] = 9;
			map<int, int> quantityDigits2;
			quantityDigits2[1] = 3;
			quantityDigits2[8] = 1;
			Ranges ranges1(quantityDigits, 5);
			Ranges ranges2(quantityDigits2, 5);
			Ranges resultRanges = ranges1 - ranges2;
			Assert::AreEqual(2, resultRanges.GetQuantityDigits()[1]);
		}

		TEST_METHOD(TestEqualOperatorFalse)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 5;
			quantityDigits[5] = 9;
			map<int, int> quantityDigits2;
			quantityDigits2[1] = 3;
			quantityDigits2[8] = 1;
			Ranges ranges1(quantityDigits, 5);
			Ranges ranges2(quantityDigits2, 5);
			bool ifEqual = ranges1 == ranges2;
			Assert::AreEqual(false, ifEqual);
		}

		TEST_METHOD(TestEqualOperatorTrue)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 5;
			quantityDigits[5] = 9;
			map<int, int> quantityDigits2;
			quantityDigits2[1] = 5;
			quantityDigits2[5] = 9;
			Ranges ranges1(quantityDigits, 5);
			Ranges ranges2(quantityDigits2, 5);
			bool ifEqual = ranges1 == ranges2;
			Assert::AreEqual(true, ifEqual);
		}

		TEST_METHOD(TestSimmilarOperatorFalse)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 5;
			quantityDigits[5] = 9;
			map<int, int> quantityDigits2;
			quantityDigits2[1] = 3;
			quantityDigits2[8] = 1;
			Ranges ranges1(quantityDigits, 5);
			Ranges ranges2(quantityDigits2, 5);
			bool ifEqual = ranges1 *= ranges2;
			Assert::AreEqual(false, ifEqual);
		}

		TEST_METHOD(TestSimmilarOperatorTrue)
		{
			map<int, int> quantityDigits;
			quantityDigits[1] = 10;
			quantityDigits[5] = 18;
			map<int, int> quantityDigits2;
			quantityDigits2[1] = 5;
			quantityDigits2[5] = 9;
			Ranges ranges1(quantityDigits, 5);
			Ranges ranges2(quantityDigits2, 5);
			bool ifEqual = ranges1 *= ranges2;
			Assert::AreEqual(true, ifEqual);
		}
	};
}

