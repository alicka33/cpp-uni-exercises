#include "pch.h"
#include "CppUnitTest.h"
#include "../PackagesLib/Packages.h"
#include "../PackagesLib/PriorityPackage.h"
#include "../PackagesLib/HeavyPackage.h"
#include "../PackagesLib/Delivery.h"
#include<string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PackagesTest
{
	TEST_CLASS(Packages)
	{
	public:

		TEST_METHOD(GetLenghtInt)
		{
			Package package = Package("1", 2, 3);
			Assert::AreEqual(2, package.GetLenght());
		}
		
		TEST_METHOD(GetWidth)
		{
			Package package = Package("1", 2, 3);
			Assert::AreEqual(3, package.GetWidth());
		}

		TEST_METHOD(SetLenght)
		{
			Package package = Package("1", 2, 3);
			package.SetLenght(4);
			Assert::AreEqual(4, package.GetLenght());
		}

		TEST_METHOD(SetWidth)
		{
			Package package = Package("1", 2, 3);
			package.SetWidth(4);
			Assert::AreEqual(4, package.GetWidth());
		}

		TEST_METHOD(comparisonTrue)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("1", 2, 3);
			bool result = package1 == package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(comparisonFalse)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("2", 5, 3);
			bool result = package1 == package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(GetInfo)
		{
			Package package = Package("1", 2, 3);
			string info = package.GetInfo();
			string result = "Normal Package";
			Assert::AreEqual(result, info); 
		} 
	};

	TEST_CLASS(PriorityPackages)
	{
	public:

		TEST_METHOD(GetInfo)
		{
			PriorityPackage prioPackage = PriorityPackage("p1", 2, 3);
			string info = prioPackage.GetInfo();
			string result = "Priority Package";
			Assert::AreEqual(result, info);
		}
	};

	TEST_CLASS(HeavyPackages)
	{
	public:

		TEST_METHOD(GetWeight)
		{
			float a = 5.0;
			HeavyPackage package = HeavyPackage("h1", 2, 4, a);
			Assert::AreEqual(a, package.GetWeight());
		}

		TEST_METHOD(SetWeight)
		{
			HeavyPackage package = HeavyPackage("h1", 2, 4, 4.f);
			package.SetWeight(2.f);
			Assert::AreEqual(2.f, package.GetWeight());
		}

		TEST_METHOD(havyComparisonTrue)
		{
			HeavyPackage package1 = HeavyPackage("h1", 2, 4, 2.f);
			HeavyPackage package2 = HeavyPackage("h1", 2, 4, 2.f);
			bool result = package1 == package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(havyComparisonFalse)
		{
			HeavyPackage package1 = HeavyPackage("h1", 2, 3, 1.f);
			HeavyPackage package2 = HeavyPackage("h2", 4, 2, 3.f);
			bool result = package1 == package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(GetInfo)
		{
			HeavyPackage prioPackage = HeavyPackage("h1", 2, 3, 5.f);
			string info = prioPackage.GetInfo();
			string result = "Havy Package";
			Assert::AreEqual(result, info);
		}
	};

	/*
	TEST_CLASS(Deliveries)
	{
	public:

		TEST_METHOD(AddPackage)
		{
			Package normalPackage1 = Package(1, 2);
			PriorityPackage prioPackage = PriorityPackage(2, 4);
			HavyPackage havyPackage = HavyPackage(1, 3, 90);
			vector<Package> deliveryVector = { normalPackage1, prioPackage, havyPackage };
			Delivery delivery = Delivery(deliveryVector);
			Package normalPackage2 = Package(8, 5);
			delivery.AddPackage(normalPackage2);
			vector<Package> result = delivery.GetDeliveryVector();
			Assert::AreEqual(result[3], normalPackage2);
		}

	};*/
} 
