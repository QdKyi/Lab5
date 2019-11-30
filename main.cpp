#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;

void InputArray(Array  arr[])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            cout << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> arr[i].arr2[j];
        }
}
void OutputArray(Array  arr[])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << arr[i].arr2[j] << "\t";
        }
        cout << endl;
    }
}
void SortColumnsByMergingInDescending(Array  arr[], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int blockSizeIterator = 1; blockSizeIterator < rows; blockSizeIterator *= 2)
        {
            for (int blockIterator = 0; blockIterator < rows - blockSizeIterator; blockIterator += 2 * blockSizeIterator)
            {
                int leftBlockIterator = 0;
                int rightBlockIterator = 0;
                int leftBorder = blockIterator;
                int midBorder = blockIterator + blockSizeIterator;
                int rightBorder = blockIterator + 2 * blockSizeIterator;
                rightBorder = (rightBorder < rows) ? rightBorder : rows;
                int* sortedBlock = new int[rightBorder - leftBorder];

                while (leftBorder + leftBlockIterator < midBorder && midBorder + rightBlockIterator < rightBorder)
                {
                    if (arr[leftBorder + leftBlockIterator].arr2[i] > arr[midBorder + rightBlockIterator].arr2[i])
                    {
                        sortedBlock[leftBlockIterator + rightBlockIterator] = arr[leftBorder + leftBlockIterator].arr2[i];
                        leftBlockIterator++;
                    }
                    else
                    {
                        sortedBlock[leftBlockIterator + rightBlockIterator] = arr[midBorder + rightBlockIterator].arr2[i];
                        rightBlockIterator++;
                    }
                }
                while (leftBorder + leftBlockIterator < midBorder)
                {
                    sortedBlock[leftBlockIterator + rightBlockIterator] = arr[leftBorder + leftBlockIterator].arr2[i];
                    leftBlockIterator++;
                }
                while (midBorder + rightBlockIterator < rightBorder)
                {
                    sortedBlock[leftBlockIterator + rightBlockIterator] = arr[midBorder + rightBlockIterator].arr2[i];
                    rightBlockIterator++;
                }

                for (int mergeIterator = 0; mergeIterator < leftBlockIterator + rightBlockIterator; mergeIterator++)
                {
                    arr[leftBorder + mergeIterator].arr2[i] = sortedBlock[mergeIterator];
                }
                delete sortedBlock;

            }

        }
    }
}
void CalculationofGeometricAverageofRowsandAddingthem(Array arr[])
{
    double summ = 0.0;
    for (int i = 0; i < (rows - 1);++i)
    {
        double product = 1;
        for (int j = i + 1; j < rows; ++j)
        {
            product = product * arr[i].arr2[j];
        }
        double geometricaverage;

        double n1 = rows - i - 1;
        geometricaverage = pow(product, (1/n1));
        summ = summ + geometricaverage;
        cout << "f(ryadok[" << i + 1 << "])=" << geometricaverage << endl;
    }
    cout << "\nF(f)=" << summ << endl;
}

int main() {
    cout << "Enter elements of matrix:\n" << endl;
    Array arr[rows];
    InputArray(arr);
    cout << "\nYour matrix:\n" << endl;
    OutputArray(arr);
    SortColumnsByMergingInDescending(arr, 5);
    cout << "\nSorted matrix:\n" << endl;
    OutputArray(arr);
    cout << "\nCalculations:\n" << endl;
    CalculationofGeometricAverageofRowsandAddingthem(arr);



    return 0;
}
