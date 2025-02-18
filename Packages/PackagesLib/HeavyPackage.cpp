#include "pch.h"
#include "framework.h"
#include "HeavyPackage.h"

HeavyPackage::HeavyPackage(string id, int lenght, int width, float weight) : Package(id, lenght, width)
{
	this->weight = weight;
}

float HeavyPackage::GetWeight()
{
	return weight;
}

void HeavyPackage::SetWeight(float newWeight)
{
	weight = newWeight;
}

bool HeavyPackage::operator==(HeavyPackage givenPackage)
{
	if (id == givenPackage.GetId())
		return true;
	return false;
}

string HeavyPackage::GetInfo()
{
	return "Heavy Package";
}


