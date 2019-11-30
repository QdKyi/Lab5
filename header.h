#include <iostream>
#include <cmath>

const int rows = 5;
const int columns = 5;

class Array
{
private:
    double arr2[columns];
public:
    friend void InputArray(Array arr[]);
    friend void OutputArray(Array arr[]);
    friend void SortColumnsByMergingInDescending(Array arr[], int rows);
    friend void CalculationofGeometricAverageofRowsandAddingthem(Array arr[]);
};
