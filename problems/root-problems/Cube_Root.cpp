/*
==================================================================================================================================

Cube Root

A cube root of a number x is a number y such that y*y*y = x.
Example: 2 × 2 × 2 = 8, so the cube root of 8 is 2.

Write a code to find the cube root of a number N  to a precision of 0.0001 without using any standard functions.

For example:
Input: 729
Output: 9

Input: 41
Output: 3.4482

Input: 2
Output: 1.2599
==================================================================================================================================

*/

#include <iostream>
using namespace std;

void show_example() {
	cout << "CUBE ROOT" << endl;
	cout <<"For example:" << endl
		 <<"Input: 729" <<endl
		 <<"Output: 9" << endl
		 << endl
		 <<"Input: 41" << endl
		 <<"Output: 3.4482" << endl
		 << endl
		 <<"Input: 2" << endl
		 <<"Output: 1.2599" << endl;
	cout << "============================" << endl;
}

double cube_root(double n) {
	double cube, precision = 0.0001;
	double i = 1.0;
	bool found = false;
	bool more = true;


	while (!found) {
		cube = i * i * i;

		if (cube == n) return i;

		else if (cube > n) {
			more = false;
			i -= precision;

		} else if (cube < n && !more) found = true;

		if (more) i+= 1.0;
	}
	return i;
}

int main()
{
	double num, result;

	show_example();
	cout << "Input: ";
	cin >> num;

	result = cube_root(num);

	cout << "Output: " << result << endl;
	return 0;
}