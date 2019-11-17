#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;

void InputArray(Array  arr[])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> arr[i].dArr[j];
        }
}
void OutputArray(Array  arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i].dArr[j] << "\t";
        }
        cout << endl;
    }
}
void SortArray(Array  arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
                int* SortedBlock = new int[RightBorder - LeftBorder];

                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                {
                    if (arr[LeftBorder + LeftBlockIterator].dArr[i] > arr[MidBorder + RightBlockIterator].dArr[i])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                    RightBlockIterator++;
                }

                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    arr[LeftBorder + MergeIterator].dArr[i] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;

            }

        }
    }
}
void CalcArray(Array arr[])
{
    double summ = 0.0;
    for (int i = 0; i < (n - 1);++i)
    {
        double prod = 1;
        for (int j = i + 1; j < n; ++j)
        {
            prod = prod * arr[i].dArr[j];
        }
        double geom;

        double n1 = n - i - 1;
        geom = pow(prod, (1/n1));
        summ = summ + geom;
        cout << "f(ryadok[" << i + 1 << "])=" << geom << endl;
    }
    cout << "\nF(f)=" << summ << endl;
}

int main() {
    cout << "Enter elements of matrix:\n" << endl;
    Array arr[n];
    InputArray(arr);
    cout << "\nYour matrix:\n" << endl;
    OutputArray(arr);
    SortArray(arr, 5);
    cout << "\nSorted matrix:\n" << endl;
    OutputArray(arr);
    cout << "\nCalculations:\n" << endl;
    CalcArray(arr);



    return 0;
}