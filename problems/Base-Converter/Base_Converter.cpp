/*
=================================================================================================================================
Base Converter

In mathematics, a base is the number of different digits or combination of digits and letters that a system of counting uses to represent numbers. 
For example, the most common base used today is the decimal system. Because "dec" means 10, it uses the 10 digits from 0 to 9.
A decimal number has base 10, a binary has base 2, an octal has base 8, etc.

Given a non-negative integer & a base as input, create a program to convert the given decimal into the corresponding base.

Some Examples:
Input: 25 7
Output: 34

Input: 368 4
Output: 11300

Input: 78 3
Output: 2220
=================================================================================================================================
*/

#include <iostream>
#include <sstream>
using namespace std;

string base_convert(int,int);
string reverse(string);
void show_example();

int main()
{
	int dec, base;


	show_example();
	cout << "Input: ";
	cin >> dec >> base;

	string val = base_convert(dec,base);
	cout << "Output: " << val << endl;

	return 0;
}

string base_convert(int d,int b) {
	int dec = d;
	int base = b;
	string result;

	if (d > 0) {
		while (dec != 0) {
			result += to_string(dec % base);
			dec = dec / base;
		}
	} else result = '0';

	result = reverse(result);

	return result;
}	


string reverse(string converted) {
	string reverse_base;

	for (int i = converted.size()-1; i >= 0; i--) {
		reverse_base += converted[i];
	}

	return reverse_base;
}

void show_example() {
	cout << "Some Examples:" << endl
		 << "Input: 25 7" << endl
		 << "Output: 34" << endl
		 << endl
		 << "Input: 368 4" << endl
		 << "Output: 11300" << endl
		 << endl
		 << "Input: 78 3" << endl
		 << "Output: 2220" << endl;
	cout << "=========================" << endl;
	cout << endl;
}