#pragma once
#include "Packages.h"

class HeavyPackage : public Package
{
private:
	float weight;
public:
	HeavyPackage(string id, int lenght, int width, float weight);
	float GetWeight();
	void SetWeight(float newWeight);
	bool operator==(HeavyPackage givenPackage);
	string GetInfo();
};
