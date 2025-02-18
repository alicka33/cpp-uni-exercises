#include "pch.h"
#include "Ranges.h"
#include "framework.h"


Ranges::Ranges(int diffrentDigits, int maxRanges, map<int, int> quantityDigits, vector<int> keys)
{
    this->diffrentDigits = diffrentDigits;
    this->maxRanges = maxRanges;
    this->quantityDigits = quantityDigits;
    this->keys = keys;
}

/* Calculates number of ranges */
int Ranges::GetNumRanges()
{
	if (diffrentDigits <= maxRanges)
		return diffrentDigits;
	return maxRanges;
}

/* Creates a title for range - (digit-digit) */
string Ranges::CreateTitle(vector<int> numbers)
{
    string rangeTitle = "";
    int last = numbers.size() - 1;
    rangeTitle = rangeTitle + '(' + char(numbers[0] + '0');
    if (numbers.size() > 1)
        rangeTitle = rangeTitle + '-' + char(numbers[last] + '0');
    rangeTitle = rangeTitle + ')';
    if (numbers.size() == 1)
        rangeTitle = rangeTitle + "  ";
    return rangeTitle;
}


/* Calculates the lenghts of ranges */
void Ranges::GetLenghtsRanges(vector<int>& lenghtRanges, int digits, int tempNumRange, int numRange)
{
    while (digits % tempNumRange != 0)
    {
        lenghtRanges.push_back(digits / tempNumRange + 1);
        digits -= digits / tempNumRange + 1;
        tempNumRange -= 1;
    }

    for (int i = lenghtRanges.size(); i < numRange; i++)
    {
        lenghtRanges.push_back(digits / tempNumRange);
    }
}

/* Sets result ranges */
void Ranges::SetResultRanges(vector<int> possibleDigits, vector<int> lenghtRanges, map<string, int>& result)
{
    for (int i = 0; i < lenghtRanges.size(); i++)
    {
        vector<int> numbers;
        int temp_sum = 0;
        for (int j = 0; j < lenghtRanges[i]; j++)
        {
            numbers.push_back(possibleDigits[j]);
            temp_sum += quantityDigits[possibleDigits[j]];
        }
        string title = CreateTitle(numbers);
        result[title] = temp_sum;
        possibleDigits.erase(possibleDigits.begin(), possibleDigits.begin() + lenghtRanges[i]);
        numbers.clear();
    }
}

/* Coordinates the proces of creating ranges */
void Ranges::SeperateIntoRanges(map<string, int>& result)
{
    int tempNumRange = GetNumRanges();
    int numRange = tempNumRange;
    const int digits = 10;
    vector<int>lenghtRanges;
    GetLenghtsRanges(lenghtRanges, digits, tempNumRange, numRange);
    vector<int>possibleDigits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    SetResultRanges(possibleDigits, lenghtRanges, result);
}

/* Sets maxRange to a new value */
void Ranges::SetMaxRanges(int newMaxRanges)
{
    maxRanges = newMaxRanges;
}

