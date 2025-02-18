#include "pch.h"
#include "Data.h"
#include "framework.h"


Data::Data(vector<int> keys, vector<float> allDigits)
{
    this->keys = keys;
    this->allDigits = allDigits;
}

/* Calculates the number of all inputed elements */
int Data::GetNumberOfElements()
{
	return allDigits.size();
}

/* Calculates the minimal value of the inputed digits */
int Data::GetMinimum()
{
	return keys[0];
}

/* Calculates the maximal value of the inputed digits */
int Data::GetMaximum()
{
    return keys[keys.size() - 1];
}

/* Calculates the median of the inputed digits */
float Data::GetMedian()
{
    int lenght = allDigits.size();
    if (lenght % 2 == 0)
    {
        float first_ind, second_ind;
        first_ind = lenght / 2 - 1;
        second_ind = lenght / 2;
        return (allDigits[first_ind] + allDigits[second_ind]) / 2;
    }
    return allDigits[lenght / 2];
}


