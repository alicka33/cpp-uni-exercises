#include "pch.h"
#include <iostream>
#include "Histogram.h"
#include "Data.h"
#include "Ranges.h"
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

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

/* Gets the keys vector from map */
vector<int> GetKeys(map<int, int> map1)
{
    vector<int> keys;
    map<int, int> ::iterator it;
    for (it = map1.begin(); it != map1.end(); it++)
        keys.push_back(it->first);
    return keys;
}

/* Allows the user to input the number of ranges */
void GetWishedNumRanges(int& maxRanges)
{
    cout << endl << "Please enter the maximal number of ranges for your historgam" << endl;
    cout << "Currently the max is: " << possibleRanges << endl;
    cout << "Type a number between 1-10:" << endl;
    cin >> maxRanges;
}

/* Reads digits form file */
map<int, int> GetDigitsFromFile(string file_name)
{
    ifstream ReadFile(file_name);
    string digitsString;
    map<int, int> quantityDigits;
    while (getline(ReadFile, digitsString))
    {
        for (int i = 0; i < digitsString.size(); i++)
        {
            if (digitsString[i] == '$')
                break;
            else if (IfValid(digitsString[i]))
                quantityDigits[ConvertToInt(digitsString[i])]++;
        }
    }
    ReadFile.close();
    return quantityDigits;
}

/* Prints histogram stored in the given file */
void ShowHistogramFromFile(string fileName)
{
    ifstream ReadFile(fileName);
    string digitsString;
    while (getline(ReadFile, digitsString))
    {
        cout << digitsString << endl;
    }
    ReadFile.close();
}

/* Manages the process of creating a histogram */
void CreateHistrogram(Ranges range, string outputFileName)
{
    Data data(range.GetKeys(), range.GetAllDigits());
    Histogram histogram(range.SeperateIntoRanges(), data.GetData());
    histogram.Show();
    histogram.Save(outputFileName);
}

/* Performs the operation which has been given by the user */
void PerformOperation(map<string, Ranges> fileMap, string operation, string outputFileName)
{
    Ranges rangeResult;
    bool result;
    switch (operation[0])
    {
    case '+': rangeResult = rangeResult.AddHistograms(fileMap); CreateHistrogram(rangeResult, outputFileName); break;
    case '-': rangeResult = rangeResult.SubHistograms(fileMap); CreateHistrogram(rangeResult, outputFileName); break;
    case '=': result = rangeResult.IfEqualHistograms(fileMap); cout << result;  break;
    case '*': result = rangeResult.IfSameScaleHistograms(fileMap); cout << result; break;
    }
}


int main(int argc, char* argv[])
{
    map<string, Ranges> fileMap;
    string outputFileName;
    map<int, int> quantityDigits;
    string operation;

    if (argc < 2)
        cerr << "To few parameters were given!";
    else if (argc == 2)
    {
        ShowHistogramFromFile(argv[1]);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            
            if (i == argc - 1)
            {
                operation = argv[i];
                break;
            }
            else if (i == argc - 2)
            {
                outputFileName = argv[i];
            }
            else
            {
                quantityDigits = GetDigitsFromFile(argv[i]);
                Ranges range(quantityDigits, possibleRanges);
                fileMap[argv[i]] = range;
                quantityDigits.clear();
            }
        }
    }

    PerformOperation(fileMap, operation, outputFileName);
    return 0;
}
