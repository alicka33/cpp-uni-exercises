#pragma once
#include<string>
using namespace std;

class Package
{
protected:
	int lenght, width; // int, poniewa¿ wielkoœæi te bêd¹ okreœlone w iloœci pól
	string id;
public:
	Package(string id, int lenght, int width);
	string GetId();
	int GetLenght();
	int GetWidth();
	int GetArea();
	void SetLenght(int newLenght);
	void SetWidth(int newWidth);
	bool operator==(Package givenPackage);
	virtual string GetInfo();

};

