#include "pch.h"
#include "framework.h"
#include "Histogram.h"
#include <iostream>
#include <fstream>

using ResultType = map<string, int>;

Histogram::Histogram(map<string, int> result, map<string, int> dataMap)
{
    this->result = result;
    this->dataMap = dataMap;
}

/* Caluculates the maximal lenght of ranges */
int Histogram::CalculateMaxLenght(map<string, int> result)
{
    map<string, int> ::iterator it;
    int max = 0;
    for (it = this->result_begin(); it != this->result_end(); it++)
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
void Histogram::ShowPlot()
{
    map<string, int> ::iterator it_result;
    cout << endl << "HISTOGRAM:" << endl << endl;
    const int maxLenghtOfPlot = 60;
    int maxLenght = CalculateMaxLenght(result);
    int scale = Scale(maxLenght, maxLenghtOfPlot);
    for (it_result = this->result_begin(); it_result != this->result_end(); it_result++)
    {
        cout << it_result->first << ": ";
        for (int i = 0; i < it_result->second; i += scale)
        {
            cout << char(220);
        }
        cout << "  " << it_result->second;
        cout << endl;
    }
}

/* Prints the data */
void Histogram::ShowData()
{
    ofstream outputFile;
    cout << endl;
    map<string, int> ::iterator it;
    for (it = this->data_begin(); it != this->data_end(); it++)
    {
        cout << it->first << it->second << endl;
    }
}

/* Manages showing proces */
void Histogram::Show()
{
    ShowPlot();
    ShowData();
}

/* Saves plot to file */
void Histogram::SavePlot(string outputFileName)
{
    ofstream outputFile(outputFileName);
    map<string, int> ::iterator it_result;
    outputFile << endl << "HISTOGRAM:" << endl << endl;
    const int maxLenghtOfPlot = 60;
    int maxLenght = CalculateMaxLenght(result);
    int scale = Scale(maxLenght, maxLenghtOfPlot);
    for (it_result = this->result_begin(); it_result != this->result_end(); it_result++)
    {
        outputFile << it_result->first << ": ";
        for (int i = 0; i < it_result->second; i += scale)
        {
            outputFile << char(220);
        }
        outputFile << endl;
    }
}

/* Saves data to file */
void Histogram::SaveData(string outputFileName)
{
    ofstream outputFile;
    outputFile.open(outputFileName, std::ios_base::app);
    outputFile << endl;
    map<string, int> ::iterator it;
    for (it = this->data_begin(); it != this->data_end(); it++)
    {
        outputFile << it->first << it->second << endl;
    }
    outputFile.close();
}

/* Manages saving process */
void Histogram::Save(string outputFileName)
{
    SavePlot(outputFileName);
    SaveData(outputFileName);
}

ResultType::iterator Histogram::result_begin()
{
    return result.begin();
}

ResultType::iterator Histogram::result_end()
{
    return result.end();
}

ResultType::iterator Histogram::data_begin()
{
    return dataMap.begin();
}

ResultType::iterator Histogram::data_end()
{
    return dataMap.end();
}
