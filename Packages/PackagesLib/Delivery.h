#pragma once
#include <vector>
#include "Packages.h"
#include<iostream>

using namespace std;

class Delivery
{
private:
	vector<unique_ptr<Package>> delivery;
public:
	Delivery(vector<unique_ptr<Package>> delivery);
	vector<unique_ptr<Package>> GetDeliveryVector();

	template <typename T>
	void AddPackage(T newPackage); 

	template <typename T>
	T TakeOutGivenPackage(T givenPackage); // moze by wiele takich samych paczek --> ta implementacja wyjmuje pierwsza ze znalezionych

	//template <typename T>
	//T TakeOutPerfectPackage(T perfectPackage);
};

class EmptyDeliveryException : public exception
{
public:
	string what()
	{
		return "Empty delivery!";
	}
};


class PackageNotInDeliveryException : public exception
{
public:
	string what()
	{
		return "No such package in delivery!";	
	}
};

template<typename T>
inline void Delivery::AddPackage(T newPackage)
{
	delivery.push_back(&newPackage);
}

template<typename T>
inline T Delivery::TakeOutGivenPackage(T givenPackage)
{
	for (int i = 0; i < delivery.size(); i++)
		if (*delivery[i] == givenPackage)
		{
			delivery.erase(delivery.begin() + i);
			return givenPackage;
		}
	throw PackageNotInDeliveryException();
}

/*
// TODO: implement algorith for pefect package
template<typename T>
inline T Delivery::TakeOutPerfectPackage(T perfectPackage)
{
	int perfectLenght = givenPackage.GetLenght();
	int perfectWidth = givenPackage.GetWidth();
	int perfectArea = givenPackage.GetArea();
	// T bestPackage = 
	for (int = 0; i < delivery.size(); i++)
	{

	}

}*/

