/*
=================================================================================================================================
Magic Square

A magic square is a matrix of numbers in which the sums of elements in each row/column/diagonal are the same. That sum is called the magic sum.

For example:
Input:
  4 3 8
  9 5 1
  2 7 6

Output:
  It is a magic square with the magic sum 15.
  4 + 3 + 8 = 9 + 5 + 1 = 2 + 7 + 6 = 15 (Rows)
  4 + 9 + 2 = 3 + 5 + 7 = 8 + 1 + 6 = 15 (Columns)
  4 + 5 + 6 = 8 + 5 + 2 = 15 (Diagonals)

Write a program to check if the input matrix is a magic square or not. If it is a magic square, display the magic sum.
=================================================================================================================================
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int>> toMatrix(vector<int>);
void magic_square(vector<int>);
void show_example();
int main()
{

	vector<int> data;
	int num;

	show_example();
	cout << "Input character to quit" << endl;
	cout << "Input:" << endl;

	while (true) {

		cin >> num;
		if (num == 0) break;
		data.push_back(num);
	}

	magic_square(data);
	return 0;
}

vector<vector<int>> toMatrix(vector<int> data) {
	vector<vector<int>> matrix;

	int matrix_size = sqrt(data.size());
	int index = 0;

	for (int i = 0; i < matrix_size; i++) {
		vector<int> temp;
		for (int j = 0; j < matrix_size; j++) {
			temp.push_back(data[index]);
			index++;
		}
		matrix.push_back(temp);
	}

	return matrix;
}

void magic_square(vector<int> data) {
	vector<vector<int>> matrix = toMatrix(data);
	bool validRowCol = true;
	bool magic_square = false;
	int total;

	int forward_diagonal = 0, backward_diagonal = 0;
	int d_index = 0;

	for (int i = 0; i < matrix.size(); i++) {

		int sum_row = 0, sum_col = 0;
		for (int j = 0; j < matrix.size(); j++) {
			sum_row += matrix[i][j];
			sum_col += matrix[j][i];
		}

		forward_diagonal += matrix[i][d_index];
		backward_diagonal += matrix[i][matrix.size() -1 - d_index];
		d_index++;

		if (sum_row != sum_col) {
			validRowCol = false;
			break;
		}

		total = sum_row;
	}

	if (validRowCol && forward_diagonal == backward_diagonal) magic_square = true;

	cout << "Output: " << endl;

	if (magic_square) cout << "It is a magic square with the magic sum " << total << "! :)"<< endl;
	else 			  cout << "Not a magic square :(" << endl;
}


void show_example() {
	cout << endl;
	cout << "Magic Square" << endl
		 << endl
		 << "A magic square is a matrix of numbers in which the sums of elements in each row/column/diagonal are the same." << endl
		 << " That sum is called the magic sum." << endl
		 << endl
		 << "For example:" << endl
		 << "Input:" << endl
		 << "4 3 8"  << endl
		 << "9 5 1"  << endl
		 << "2 7 6"  << endl
		 << endl
		 << "Output:" << endl
		 << "It is a magic square with the magic sum 15." << endl;
	cout << "================================================================================" << endl;
}