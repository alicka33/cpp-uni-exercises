#pragma once
#include <vector>
#include <map>
#include <string>


using namespace std;

class Data
{
private:
	vector<int> keys;
	vector<float> allDigits;
public:
	Data(vector<int>keys, vector<float> allDigits);
	int GetNumberOfElements();
	int GetMinimum();
	int GetMaximum();
	float GetMedian();
	map<string, int> GetData();
};
