#include "pch.h"
#include "CppUnitTest.h"
#include "../HistogramLib/Data.h"
#include "../HistogramLib/Ranges.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HistogramTest
{
	TEST_CLASS(DataTest)
	{
	public:
		
		TEST_METHOD(TestGetNumberOfELements)
		{
			vector<int> keys{ 2, 4, 8};
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
			vector<int> keys{ 2, 4, 8, 9};
			vector<float> allDigits{ 2, 4, 4, 8, 8, 9};
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
			map<string, int>result;
			vector<int>keys{ 1, 5, 7, 8 };
			Ranges ranges(4, 5, quantityDigits, keys);
			Assert::AreEqual(4, ranges.GetNumRanges());
		}

		TEST_METHOD(TestCreateTitle)
		{
			map<int, int> quantityDigits;
			map<string, int>result;
			vector<int>keys{ 1, 5, 7, 8 };
			vector<int>numbers{ 0, 1, 2 };
			string title = "(0-2)";
			Ranges ranges(4, 5, quantityDigits, keys);
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
			Ranges ranges(4, 5, quantityDigits, keys);
			ranges.SetResultRanges(possibleDigits, lenghtRanges, result);
			Assert::AreEqual(9, result["(3-5)"]);
		}
	};
}
