/*
==================================================================================================================================
Strange Root

A number has a strange root if its square and square root share any digit. For example, 2 has a strange root 
because the square root of 2 equals 1.414 (consider the first three digits after the dot) 
and it contains 4 (which is the square of 2).

Examples:
Input: 11
Output: true 
(the square root of 11 is 3.317, the square of 11 is 121. They share the same digit, 1.)
 
Input: 24
Output: false (the square root of 24 (4.899) and square (576) do not share any digits) 

Write a program to check if the user input has a strange root or not.
==================================================================================================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

void show_example() {
	cout << "Examples:" << endl
		 << "Input: 11" << endl
		 << "Output: true " << endl
		 << "(the square root of 11 is 3.317, the square of 11 is 121. They share the same digit, 1.)" << endl
		 << endl
		 << "Input: 24" << endl
		 << "Output: false (the square root of 24 (4.899) and square (576) do not share any digits) " << endl;
	cout << "========================================================================================" << endl;
}

void strange_root(int num) {
	string square = to_string(num * num);
	string root = to_string(sqrt(num));
	string same_digit, result;
	bool output = false;

	for (int i = 0; i < square.size(); i++) {
		for (int j = 0; j < root.size(); j++) {
			if (square[i] == root[j])   {
				same_digit = root[j];
				output = true;
			}
		}
	}

	if (same_digit.size() > 0) result = " They share the same digit, " + same_digit;
	else 					   result = " they do not share any digits";

	cout << boolalpha << "Output: " << output << endl;
	cout << "(the square root of " << num << " is (" << root << "), "
	     << "and square of " << num << " is (" << square << ")" << result << ")" << endl;
}


int main()
{
	int num;

	show_example();
	cout << "Input: ";
	cin >> num;

	strange_root(num);
	
	return 0;
}