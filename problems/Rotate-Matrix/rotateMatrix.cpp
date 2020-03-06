/*
Rotate the Matrix

Write a program that takes a NxN square matrix as an input and rotates it clockwise by 90 degrees.

For example:
Input:
1  2  3
4  5  6
7  8  9
Output:
7  4  1
8  5  2
9  6  3
*/

// Refactor for user interaction

#include<iostream>

using namespace std;

void rotateMatrix(int m[3][3])
{
    int len = 2;
    for (int i = 0; i <= len; i++) {
        for (int j = len; j >= 0; j--) {
            cout << m[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9} };

    rotateMatrix(matrix);
    return 0;
}