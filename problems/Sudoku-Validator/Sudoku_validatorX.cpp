/*
=================================================================================================================================
Sudoku Validator

A solved sudoku puzzle is a matrix of typically 9*9 in which every row, every column and every block contains every number from 1 to 9 
exactly once.

Create an algorithm that checks any solved sudoku's validity.

Examples:
Input: [
    [3, 5, 2, 9, 1, 8, 6, 7, 4],
    [8, 9, 7, 2, 4, 6, 5, 1, 3],
    [6, 4, 1, 7, 5, 3, 2, 8, 9],
    [7, 8, 3, 5, 6, 9, 4, 2, 1],
    [9, 2, 6, 1, 3, 4, 7, 5, 8],
    [4, 1, 5, 8, 2, 7, 9, 3, 6],
    [8, 6, 4, 3, 7, 5, 8, 9, 2],
    [2, 7, 8, 4, 9, 1, 3, 6, 5],
    [5, 3, 9, 6, 8, 2, 1, 4, 7]
  ]
Output: false

Input: [
    [3, 5, 2, 9, 1, 8, 6, 7, 4],
    [8, 9, 7, 2, 4, 6, 5, 1, 3],
    [6, 4, 1, 7, 5, 3, 2, 8, 9],
    [7, 8, 3, 5, 6, 9, 4, 2, 1],
    [9, 2, 6, 1, 3, 4, 7, 5, 8],
    [4, 1, 5, 8, 2, 7, 9, 3, 6],
    [1, 6, 4, 3, 7, 5, 8, 9, 2],
    [2, 7, 8, 4, 9, 1, 3, 6, 5],
    [5, 3, 9, 6, 8, 2, 1, 4, 7]
  ]
Output: true
=================================================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

void show_line(int*,string);
bool isValidLine(int*);
bool sudoku_validator(vector<vector<int>> sudoku_arr);
int main()
{

	vector<vector<int>> sudoku_arr1 = {
		{3, 5, 2, 9, 1, 8, 6, 7, 4},
		{8, 9, 7, 2, 4, 6, 5, 1, 3},
	    {6, 4, 1, 7, 5, 3, 2, 8, 9},
	    {7, 8, 3, 5, 6, 9, 4, 2, 1},
	    {9, 2, 6, 1, 3, 4, 7, 5, 8},
	    {4, 1, 5, 8, 2, 7, 9, 3, 6},
	    {8, 6, 4, 3, 7, 5, 8, 9, 2},
	    {2, 7, 8, 4, 9, 1, 3, 6, 5},
	    {5, 3, 9, 6, 8, 2, 1, 4, 7}
	};

	vector<vector<int>> sudoku_arr2 = {
		{3, 5, 2, 9, 1, 8, 6, 7, 4},
	    {8, 9, 7, 2, 4, 6, 5, 1, 3},
	    {6, 4, 1, 7, 5, 3, 2, 8, 9},
	    {7, 8, 3, 5, 6, 9, 4, 2, 1},
	    {9, 2, 6, 1, 3, 4, 7, 5, 8},
	    {4, 1, 5, 8, 2, 7, 9, 3, 6},
	    {1, 6, 4, 3, 7, 5, 8, 9, 2},
	    {2, 7, 8, 4, 9, 1, 3, 6, 5},
	    {5, 3, 9, 6, 8, 2, 1, 4, 7}
	};

	bool result = sudoku_validator(sudoku_arr1);

	cout << boolalpha << "Output: " <<  result << endl;
	return 0;
}

bool sudoku_validator(vector<vector<int>> sudoku_arr) {
	int horizontal[9];
	int vertical[9];
	int block[9];

	int prev, x,y, max_step;
	x = 0;
	y = 0;
	max_step = 2;
	prev = x;

	for (int i = 0; i < sudoku_arr.size(); i++) {

		for (int j = 0; j < sudoku_arr.size(); j++) {

			horizontal[j] = sudoku_arr[i][j];
			vertical[j]   = sudoku_arr[j][i];
			block[j]      = sudoku_arr[y][x];

			if (x == max_step) {
				y++;
				x = prev;
				continue;
			}
			x++;
		}
		if (y == 9) {
		    y = 0;
			x += 3;
			max_step += 3;
			prev = x;
		}

		if (!isValidLine(horizontal) || !isValidLine(vertical) || !isValidLine(block)) return false;
	}

	return true;

}

bool isValidLine(int *line) {

	for (int i = 1; i <= 9; i++) {
		int count = 0;
		for (int j = 0; j < 9; j++) {
			if (i == line[j]) count++;
		}
		if (count > 1) {
			cout << "Invalid " << i << endl;
			return false;
		}
	}
	return true;
}

void show_line(int *line, string r) {

	bool box_mode = false;
	int range = 3;
	string rotate = " ";

	if 		(r == "vertical") 	rotate = "\n";
	else if (r == "horizontal") rotate = " ";
	else if (r == "block" || r == "box") box_mode = true;

	// display the type of rotation
	cout << r << endl;

	// loop for every element and do the desired rotation
	int count = 0;
	for (int i = 0; i < 9; i++) {
		cout << line[i] << rotate;

		count++;
		if (count == range && box_mode) {
			cout << endl;
			range += 3;
		}
	}
	cout << endl;
	cout << "----------------------------------" << endl;
}