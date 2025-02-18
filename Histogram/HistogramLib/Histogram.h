#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

class Histogram
{
private:
	int numElements = 0;
	int min = 0;
	int max = 0;
	float median = 0;

public:
	Histogram(int numElements, int min, int max, float median);
	int CalculateMaxLenght(map<string, int> result);
	int Scale(int maxLenght, int maxLenghtOfPlot);
	void ShowPlot(map<string, int> result);
	void ShowData();
	
};