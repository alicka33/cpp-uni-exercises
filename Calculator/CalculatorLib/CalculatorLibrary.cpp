#include "pch.h"
#include "CalculatorLibrary.h"
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;

double Calculator::Add(double number1, double number2)
{
    return number1 + number2;
}

double Calculator::Sub(double number1, double number2)
{
    return number1 - number2;
}

double Calculator::Mul(double number1, double number2)
{
    return number1 * number2;
}

double Calculator::Dev(double number1, double number2)
{
    if (number2 == 0)
        throw std::invalid_argument("Devision by 0 is impossible!");
    else
        return number1 / number2;
}

void Calculator::AddMem(double number)
{
    this->memory += number;
}

void Calculator::SubMem(double number)
{
    this->memory -= number;
}

void Calculator::ClearMem()
{
    this->memory = 0;
}

double Calculator::GetMemory()
{
    return this->memory;
}

double Calculator::GetResult()
{
    return this->result;
}

void Calculator::SetResult(double number)
{
    this->result = number;
}

void Calculator::Info()
{
    cout << "Welcome to the calculator!" << endl;
    cout << "Input a number and then choose one of these operations:" << endl;
    cout << "To add choose input: +" << endl;
    cout << "To subtract choose input: -" << endl;
    cout << "To multiply choose input: *" << endl;
    cout << "To devide choose input: /" << endl;
    cout << "If you choose one of the above you will need to enter another number" << endl;
    cout << "To add to memory choose input: M+" << endl;
    cout << "To subtract from memory choose input: M-" << endl;
    cout << "To see the memory choose input: MR" << endl;
    cout << "To clear the memory choose input: MC" << endl;
    cout << "To see this information again input: INFO" << endl;
    cout << "To quit calculating input: C" << endl; 
    cout << "Please submit your choice by pressing ENTER" << endl;
}
