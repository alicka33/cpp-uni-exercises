#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculatorLib/CalculatorLibrary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest
{
	TEST_CLASS(CalculatorTest)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			Calculator cal;
			Assert::AreEqual(6.0, cal.Add(2.0, 4.0));
		}

		TEST_METHOD(TestAdd2)
		{
			Calculator cal;
			Assert::AreEqual(6.34, cal.Add(2.34, 4.0));
		}

		TEST_METHOD(TestSub)
		{
			Calculator cal;
			Assert::AreEqual(-2.0, cal.Sub(2.0, 4.0));
		}

		TEST_METHOD(TestMul)
		{
			Calculator cal;
			Assert::AreEqual(8.0, cal.Mul(2.0, 4.0));
		}

		TEST_METHOD(TestDev)
		{
			Calculator cal;
			Assert::AreEqual(0.5, cal.Dev(2.0, 4.0));
		}

		TEST_METHOD(TestGetMem)
		{
			Calculator cal;
			Assert::AreEqual(0.0, cal.GetMemory());
		}

		TEST_METHOD(TestGetRes)
		{
			Calculator cal;
			Assert::AreEqual(0.0, cal.GetResult());
		}

		TEST_METHOD(TestSetRes)
		{
			Calculator cal;
			Assert::AreEqual(0.0, cal.GetResult());
			cal.SetResult(5.6);
			Assert::AreEqual(5.6, cal.GetResult());
		}
		
		TEST_METHOD(TestAddMem)
		{
			Calculator cal;
			Assert::AreEqual(0.0, cal.GetMemory());
			cal.AddMem(4.89);
			Assert::AreEqual(4.89, cal.GetMemory());
		}

		TEST_METHOD(TestSubMem)
		{
			Calculator cal;
			Assert::AreEqual(0.0, cal.GetMemory());
			cal.SubMem(4.89);
			Assert::AreEqual(-4.89, cal.GetMemory());
		}

		TEST_METHOD(TestClearMem)
		{
			Calculator cal;
			cal.AddMem(5.6);
			Assert::AreEqual(5.6, cal.GetMemory());
			cal.ClearMem();
			Assert::AreEqual(0.0, cal.GetMemory());
		}

	};
}
