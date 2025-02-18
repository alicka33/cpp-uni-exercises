#pragma once
#include <vector>
#include <map>
#include <string>

using namespace std;

class Ranges
{
private:
	int diffrentDigits;
	map<int, int> quantityDigits;
	vector<int> keys;

public:
	int maxRanges = 5;
	Ranges(int diffrentDigits, int maxRanges, map<int, int> quantityDigits, vector<int> keys);
	int GetNumRanges();
	string CreateTitle(vector<int> numbers);
	void GetLenghtsRanges(vector<int>& lenghtRanges, int digits, int tempNumRange, int numRange);
	void SetResultRanges(vector<int> possibleDigits, vector<int> lenghtRanges, map<string, int>& result);
	void SeperateIntoRanges(map<string, int>& result);
	void SetMaxRanges(int newMaxRanges);
};