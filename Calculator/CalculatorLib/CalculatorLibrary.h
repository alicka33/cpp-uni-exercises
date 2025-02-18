#pragma once

class Calculator
{
private:
    double memory = 0, result =0;
public:
    double Add(double number1, double number2);
    double Sub(double number1, double number2);
    double Mul(double number1, double number2);
    double Dev(double number1, double number2);
    void AddMem(double number);
    void SubMem(double number);
    void ClearMem();
    double GetMemory();
    double GetResult();
    void SetResult(double number);
    void Info();
};
   

