#include <iostream>
#include <cmath>

const int n = 5;
const int m = 5;

class Array
{
private:
    double dArr[m];
public:
    friend void InputArray(Array arr[]);
    friend void OutputArray(Array arr[]);
    friend void SortArray(Array arr[], int n);
    friend void CalcArray(Array arr[]);
};