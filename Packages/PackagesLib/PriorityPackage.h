#pragma once
#include "Packages.h"

class PriorityPackage : public Package
{
public:
	PriorityPackage(string id, int lenght, int width);
	string GetInfo();
};
