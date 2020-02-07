/*
==================================================================================================================================
Gapful Numbers

A gapful number is  a number of at least 3 digits that is divisible by the number formed by the first and last digit 
of the original number.

For Example:
Input: 192
Output: true (192 is gapful because it is divisible 12)

Input: 583
Output: true (583 is gapful because it is divisible by 53)

Input: 210
Output: false (210 is not gapful because it is not divisible by 20)

Write a program to check if the user input is a gapful number or not.

==================================================================================================================================
*/

#include <iostream>
using namespace std;

bool gapful_num(int);
void display_problem();

int main() 
{
	display_problem();

	int x;
	bool result;

	cout << "Input: ";
	cin >> x;

	result = gapful_num(x);

	cout << boolalpha << "Output: " << result << endl;
	return 0;
}

void display_problem() {
	cout << "Gapful Numbers" << endl << endl
		 << "A gapful number is  a number of at least 3 digits that is divisible by" << endl
		 << "the number formed by the first and last digit" << endl
		 << "of the original number." << endl
		<< "For Example:" << endl
		<< "Input: 192" << endl
		<< "Output: true (192 is gapful because it is divisible 12)" << endl
		<< endl
		<< "Input: 583" << endl
		<< "Output: true (583 is gapful because it is divisible by 53)" << endl
		<< endl
		<< "Input: 210" << endl
		<< "Output: false (210 is not gapful because it is not divisible by 20)" << endl;
	cout << "=====================================================================" << endl;
}

bool gapful_num(int x) {

	int original_num = x;
	int first_digit, last_digit, combine, result;
	bool gapful = false;

	first_digit = (x - (x % 100)) / 100;
	last_digit = x % 10; 
	combine =  first_digit * 10 + last_digit;
	result = original_num % combine;

	if (result == 0) gapful = true;

	return gapful;
}