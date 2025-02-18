#include "pch.h"
#include "framework.h"
#include "Histogram.h"
#include <iostream>


Histogram::Histogram(int numElements, int min, int max, float median)
{
    this->numElements = numElements;
    this->min = min;
    this->max = max;
    this->median = median;
}

/* Caluculates the maximal lenght of ranges */
int Histogram::CalculateMaxLenght(map<string, int> result)
{
    map<string, int> ::iterator it;
    int max = 0;
    for (it = result.begin(); it != result.end(); it++)
        if (it->second > max)
            max = it->second;
    return max;
}

/* Caluculates the scale of the plot */
int Histogram::Scale(int max, int maxLenghtOfPlot)
{
    if (max <= maxLenghtOfPlot)
        return 1;
    else
    {
        int scale = max / maxLenghtOfPlot + 1;
        return scale;
    }
}

/* Prints the plot */
void Histogram::ShowPlot(map<string, int> result)
{
    map<string, int> ::iterator it_result;
    cout << endl << "HISTOGRAM:" << endl << endl;
    const int maxLenghtOfPlot = 60;
    int maxLenght = CalculateMaxLenght(result);
    int scale = Scale(maxLenght, maxLenghtOfPlot);
    for (it_result = result.begin(); it_result != result.end(); it_result++)
    {
        cout << it_result->first << ": ";
        for (int i = 0; i < it_result->second; i+=scale)
        {
            cout << char(220);
        }
        cout << endl;
    }
}

/* Prints the data */
void Histogram::ShowData()
{
    cout << endl;
    cout << "Number of elements: " << numElements << endl;
    cout << "Minimal digit: " << min << endl;
    cout << "Maximal digit: " << max << endl;
    cout << "Median: " << median << endl;
}

