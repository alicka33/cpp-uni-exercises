#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

class Histogram
{
private:
	map<string, int> dataMap;
	map<string, int> result;

public:
	Histogram(map<string, int> result, map<string, int> dataMap);
	int CalculateMaxLenght(map<string, int> result);
	int Scale(int maxLenght, int maxLenghtOfPlot);
	void ShowPlot();
	void ShowData();
	void Show();
	void SavePlot(string outputFileName);
	void SaveData(string outputFileName);
	void Save(string outputFileName);
	using ResultType = map<string, int>;
	ResultType::iterator result_begin();
	ResultType::iterator result_end();
	ResultType::iterator data_begin();
	ResultType::iterator data_end();
};
