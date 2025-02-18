#include "pch.h"
#include "framework.h"
#include "PriorityPackage.h"


PriorityPackage::PriorityPackage(string id, int lenght, int width) : Package(id, lenght, width)
{
}

string PriorityPackage::GetInfo()
{
	return "Priority Package";
}
