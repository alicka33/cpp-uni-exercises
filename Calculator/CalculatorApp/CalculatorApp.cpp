#include <iostream>
#include "CalculatorLibrary.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;


double Count(Calculator cal, char symbol, double number1, double number2)
{
    switch (symbol)
    {
        case '+': return cal.Add(number1, number2);
        case '-': return cal.Sub(number1, number2);
        case '*': return cal.Mul(number1, number2);
        case '/': return cal.Dev(number1, number2);
    }

}


void ModifyMemory(Calculator* cal, string symbol, double number)
{
    if (symbol == "M+")
        cal->AddMem(number);
    else if (symbol == "M-")
        cal->SubMem(number);
    else if (symbol == "MC")
        cal->ClearMem();
}


int GetIndex(string symbol, vector<string> operators)
{
    int i;
    for (i = 0; i < operators.size(); i++)
        if (operators[i] == symbol)
            return i;
}


bool IfPotNegative(string sign)
{
    if (sign[0] == '-' && sign.size() > 1)
        return true;
    return false;
}


double StringToDouble(string sign)
{
    return stod(sign.c_str());
}


bool CheckNumber(string sign)
{
    int i, dots = 0, p = 0;
    if (IfPotNegative(sign))
        p = 1;
    for (i = p; i < sign.size(); i++)
    {
        if (sign[i] < '0' or sign[i] > '9')
            if (sign[i] != '.')
                return false;
            else
                dots++;
    }
    if (sign[0] != '.' and dots <= 1)
        return true;
    return false;
}


bool CheckSymbol(string sign, vector<string> operators)
{
    int i;
    for (i = 0; i < operators.size(); i++)
        if (operators[i] == sign)
            return true;
    return false;
}

char ConvertToChar(string sign, vector<string> operators, vector<char> charOperators)
{
    int i;
    i = GetIndex(sign, operators);
    return charOperators[i];
}


int main()
{    
    vector<char> calOperChar = { '+', '-', '*', '/'};
    vector<string> calOper = { "+", "-", "*", "/"};
    vector<string> memoryOper = {"M+", "M-", "MC"};
    Calculator cal;
    string sign, number;
    bool calculating = true, memory_mod;
    
    cal.Info();
    do
    {
        cin >> sign;
        /*
        cin >> sign
        BŁĄD: brak średnika na końcu linii
        Program się nie skompiluje
        */
        transform(sign.begin(), sign.end(), sign.begin(), ::toupper);
        if (CheckNumber(sign))
        {
            cal.SetResult(StringToDouble(sign));
        }
        else if (CheckSymbol(sign, calOper))
        {
            memory_mod = false;
            do
            {
                cin >> number;
                transform(number.begin(), number.end(), number.begin(), ::toupper);
                if (CheckSymbol(number, calOper))
                    sign = number;
                else if (CheckSymbol(number, memoryOper))
                {
                    ModifyMemory(&cal, number, cal.GetResult());
                    memory_mod = true;
                    break;
                }       
            } while (CheckNumber(number) == false);
            
            if (memory_mod == false)
            {
                try
                {
                    cal.SetResult(Count(cal, ConvertToChar(sign, calOper, calOperChar), cal.GetResult(), StringToDouble(number)));
                    cout << "RESULT: " << cal.GetResult() << endl;
                    /*
                    cout << 'RESULT:';
                    BŁĄD: zapisanie zmiennej string w pojedynczym cudzysłowie
                    */
                }
                catch (std::invalid_argument& e)
                {
                    cout << "You cannot devide by zero!" << endl;
                }
            }

        }
        else if (CheckSymbol(sign, memoryOper))
        {
            ModifyMemory(&cal, sign, cal.GetResult());
#if defined(_DEBUG) || !defined(NDEBUG)
            cout << cal.GetMemory() << endl;
#endif
        }
        else if (sign == "MR")
            cout << "MEMORY: " << cal.GetMemory() << endl;
        /*
        else if sign == "MR"
            cout << "MEMORY: ";
        BŁĄD: nieużycie nawiasów przy poleceniu if
        */
        else if (sign == "INFO")
            cal.Info();
        /*
        else if (sign = "INFO")
            cal.Info();
        BŁĄD: użycie jednego zamiast dwóch znaków '=' przy porówaniu
        */
        else if (sign == "C")
            calculating = false;
    } while (calculating);
    
    return 0;
}
