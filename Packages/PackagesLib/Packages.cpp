#include "pch.h"
#include "framework.h"
#include "Packages.h"

Package::Package(string id, int lenght, int width)
{
	this->id = id;
	this->lenght = lenght;
	this->width = width;
}

string Package::GetId()
{
	return id;
}

int Package::GetLenght()
{
	return lenght;
}

int Package::GetWidth()
{
	return width;
}

int Package::GetArea()
{
	return lenght * width;
}

void Package::SetLenght(int newLenght)
{
	lenght = newLenght;
}

void Package::SetWidth(int newWidth)
{
	width = newWidth;
}

bool Package::operator==(Package givenPackage)
{
	if (id == givenPackage.GetId())
		return true;
	return false;
}

string Package::GetInfo()
{
	return "Normal Package";
}

