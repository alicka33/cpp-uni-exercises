#include "pch.h"
#include <iostream>
#include "Histogram.h"
#include "Data.h"
#include "Ranges.h"
#include <map>
#include <vector>

using namespace std;

#define possibleRanges 5


/* Checks if given input is a digitv */
bool IfValid(char input)
{
    if (input >= '0' and input <= '9')
        return true;
    return false;
}

/* Checks char into int */
int ConvertToInt(char input)
{
    return input - '0';
}

/* Takes input from the user */
void GetDigit(map<int, int>& quantityDigits)
{
    cout << "Please input the digits (to stop enter '$'):" << endl;
    char input;
    do
    {
        cin >> input;
        if (IfValid(input))
            quantityDigits[ConvertToInt(input)]++;
    } while (input != '$');
    
}

/* Sets the keys vector */
void SetKeys(map<int, int> quantityDigits, vector<int>& keys)
{
    map<int, int> ::iterator it;
    for (it = quantityDigits.begin(); it != quantityDigits.end(); it++)
        keys.push_back(it->first);
}

/* Sets the allDigits vecotr - a collection of all inputed digits */
void SetAllDigits(map<int, int> quantityDigits, vector<float>& allDigits)
{
    map<int, int> ::iterator it;
    for (it = quantityDigits.begin(); it != quantityDigits.end(); it++)
    {
        for (int i = 0; i < it->second; i++)
        {
            allDigits.push_back(it->first);
        }
    }
}

/* Allows the user to input the number of ranges */
void GetWishedNumRanges(int& maxRanges)
{
    cout << endl << "Please enter the maximal number of ranges for your historgam" << endl;
    cout << "Currently the max is: " << possibleRanges << endl;
    cout << "Type a number between 1-10:" << endl;
    cin >> maxRanges;
}


int main()
{
    map<int, int> quantityDigits;
    int maxRanges = possibleRanges;
    GetDigit(quantityDigits);
    //GetWishedNumRanges(maxRanges);
    map<string, int> result;

    vector<int> keys;
    SetKeys(quantityDigits, keys);
    vector<float> allDigits;
    SetAllDigits(quantityDigits, allDigits);

    Ranges ranges(allDigits.size(), maxRanges, quantityDigits, keys);
    ranges.SeperateIntoRanges(result);

    Data data(keys, allDigits);
    int numElements = data.GetNumberOfElements();
    int min = data.GetMinimum();
    int max = data.GetMaximum();
    float median = data.GetMedian();
    
    Histogram histogram(numElements, min, max, median);
    histogram.ShowPlot(result);
    histogram.ShowData();

    return 0;
}
