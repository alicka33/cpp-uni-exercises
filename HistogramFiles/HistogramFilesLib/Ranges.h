#pragma once
#include <vector>
#include <map>
#include <string>

using namespace std;

class Ranges
{
private:
	map<int, int> quantityDigits;

public:
	int maxRanges = 5;
	Ranges();
	Ranges(map<int, int> quantityDigits, int maxRanges);
	int GetNumRanges();
	string CreateTitle(vector<int> numbers);
	vector<int> GetKeys();
	vector<float> GetAllDigits();
	void GetLenghtsRanges(vector<int>& lenghtRanges, int digits, int tempNumRange, int numRange);
	map<string, int> SetResultRanges(vector<int> possibleDigits, vector<int> lenghtRanges);
	map<string, int> SeperateIntoRanges();
	void SetMaxRanges(int newMaxRanges);
	
	Ranges operator+(Ranges range2);
	Ranges operator-(Ranges range2);
	bool operator==(Ranges range2);
	bool operator*=(Ranges range2);

	map<int, int> GetQuantityDigits();
	Ranges AddHistograms(map<string, Ranges>histogramsMap);
	Ranges SubHistograms(map<string, Ranges>histogramsMap);
	bool IfEqualHistograms(map<string, Ranges>histogramsMap);
	bool IfSameScaleHistograms(map<string, Ranges>histogramsMap);
	Ranges GetFirstRange(map<string, Ranges>histogramsMap);
};
