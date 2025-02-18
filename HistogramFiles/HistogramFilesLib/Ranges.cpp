#include "pch.h"
#include "Ranges.h"
#include "framework.h"


Ranges::Ranges()
{
    this->maxRanges = 5;
    this->quantityDigits = map<int, int> ();
}

Ranges::Ranges(map<int, int> quantityDigits, int maxRanges)
{
    this->maxRanges = maxRanges;
    this->quantityDigits = quantityDigits;
}

/* Sets the keys vector */
vector<int> Ranges::GetKeys()
{
    vector<int> keys;
    map<int, int> ::iterator it;
    for (it = quantityDigits.begin(); it != quantityDigits.end(); it++)
        keys.push_back(it->first);
    return keys;
}

/* Sets the allDigits vecotr - a collection of all inputed digits */
vector<float> Ranges::GetAllDigits()
{
    vector<float> allDigits;
    map<int, int> ::iterator it;
    for (it = quantityDigits.begin(); it != quantityDigits.end(); it++)
    {
        for (int i = 0; i < it->second; i++)
        {
            allDigits.push_back(it->first);
        }
    }
    return allDigits;
}

/* Calculates number of ranges */
int Ranges::GetNumRanges()
{
    vector<float> allDigits = GetAllDigits();
    int diffrentDigits = allDigits.size();                  
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

/* Gets result ranges */
map<string, int> Ranges::SetResultRanges(vector<int> possibleDigits, vector<int> lenghtRanges)
{
    map<string, int> result;
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
    return result;
}

/* Coordinates the proces of creating ranges */
map<string, int> Ranges::SeperateIntoRanges()
{
    int tempNumRange = GetNumRanges();
    int numRange = tempNumRange;
    const int digits = 10;
    vector<int>lenghtRanges;
    if (tempNumRange != 0)
        GetLenghtsRanges(lenghtRanges, digits, tempNumRange, numRange);
    else
        lenghtRanges = { 10 };
    vector<int>possibleDigits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    return SetResultRanges(possibleDigits, lenghtRanges);
}

/* Sets maxRange to a new value */
void Ranges::SetMaxRanges(int newMaxRanges)
{
    maxRanges = newMaxRanges;
}

/* Adds two histograms */
Ranges Ranges::operator+(Ranges range2)
{
    map<int, int> quantityDigits2 = range2.GetQuantityDigits();
    map<int, int> resultMap = quantityDigits;
    map<int, int> ::iterator it;
    for (it = quantityDigits2.begin(); it != quantityDigits2.end(); it++)
        resultMap[it->first] += it->second;
    Ranges resultRange(resultMap, maxRanges);
    return resultRange;
}

/* Subtracts two histograms */
Ranges Ranges::operator-(Ranges range2)
{
    map<int, int> quantityDigits2 = range2.GetQuantityDigits();
    map<int, int> resultMap = quantityDigits;
    map<int, int> ::iterator it;
    for (it = quantityDigits2.begin(); it != quantityDigits2.end(); it++)
    {
        if (resultMap[it->first] > 0)
            resultMap[it->first] -= it->second;
        if (resultMap[it->first] <= 0)
            resultMap.erase(it->first);
    }
    Ranges resultRange(resultMap, maxRanges);
    return resultRange;
}

/* Checks if histograms are equal */
bool Ranges::operator==(Ranges range2)
{
    map<int, int> quantityDigits2 = range2.GetQuantityDigits();
    if (quantityDigits.size() != quantityDigits2.size())
        return false;
    map<int, int> ::iterator it;
    for (it = quantityDigits.begin(); it != quantityDigits.end(); it++)
        if (quantityDigits[it->first] != quantityDigits2[it->first])
            return false;
    return true;
}

/* Checks if histograms are similar - they have the same keys and all of the values: v1 = k* v2 */
bool Ranges::operator*=(Ranges range2)
{
    map<int, int> quantityDigits2 = range2.GetQuantityDigits();
    if (quantityDigits.size() != quantityDigits2.size())
        return false;

    vector<int> keys1 = GetKeys();
    vector<int> keys2 = range2.GetKeys();
    for (int i = 0; i < keys1.size(); i++)
        if (keys1[i] != keys2[i])
            return false;

    map<int, int> ::iterator it;
    map<float, int> scale;
    for (it = quantityDigits.begin(); it != quantityDigits.end(); it++)
        scale[quantityDigits[it->first] / quantityDigits2[it->first]] = 1;
    if (scale.size() == 1)
        return true;
    return false;
}

/* Getter for quantity digits */
map<int, int> Ranges::GetQuantityDigits()
{
    return quantityDigits;
}


/* Gets first range from a map<fileName, Range> */
Ranges Ranges::GetFirstRange(map<string, Ranges> histogramsMap)
{
    map<string, Ranges> ::iterator it;
    for (it = histogramsMap.begin(); it != histogramsMap.end(); it++)
    {
        return it->second;
    }
}

/* Adds multiple histograms */
Ranges Ranges::AddHistograms(map<string, Ranges> histogramsMap)
{
    map<string, Ranges> ::iterator it;
    Ranges range;
    for (it = histogramsMap.begin(); it != histogramsMap.end(); it++)
        range = range + it->second;
    return range;
}

/* Subtracts multiple histograms */
Ranges Ranges::SubHistograms(map<string, Ranges> histogramsMap)
{
    Ranges resultRange = GetFirstRange(histogramsMap);
    map<string, Ranges> ::iterator it;
    bool ifFirst = true;
    for (it = histogramsMap.begin(); it != histogramsMap.end(); it++)
    {
        if (ifFirst)
            ifFirst = false;
        else
            resultRange = resultRange - it->second;
    }
    return resultRange;
}

/* Checks if multiple histograms are equal */
bool Ranges::IfEqualHistograms(map<string, Ranges> histogramsMap)
{

    Ranges resultRange = GetFirstRange(histogramsMap);
    map<string, Ranges> ::iterator it;
    bool ifFirst = true;
    bool result;
    for (it = histogramsMap.begin(); it != histogramsMap.end(); it++)\
    {
        if (ifFirst)
            ifFirst = false;
        else
        {
            result = resultRange == it->second; 
            resultRange = it->second; 
            if (result == false) 
                return false;
        }
    }
    return true;
}

/* Checks if multiple histograms have the same scale */
bool Ranges::IfSameScaleHistograms(map<string, Ranges> histogramsMap)
{

    Ranges resultRange = GetFirstRange(histogramsMap);
    map<string, Ranges> ::iterator it;
    bool ifFirst = true;
    bool result;
    for (it = histogramsMap.begin(); it != histogramsMap.end(); it++)\
    {
        if (ifFirst)
            ifFirst = false;
        else
        {
            result = resultRange *= it->second;
            resultRange = it->second;
            if (result == false)
                return false;
        }
    }
    return true;
}


