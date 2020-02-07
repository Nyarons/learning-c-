/*
==================================================================================================================================

Prime Strings

A String is called prime if it can't be constructed by concatenating multiple (more than one) equal strings.

For example:
"abac" is prime, but "xyxy" is not ("xyxy" = "xy" + "xy").

Implement a program which outputs whether a given string is prime.

Examples
Input: "xyxy"
Output: "not prime"

Input: "aaaa"
Output: "not prime"

Input: "hello"
Output: "prime"
==================================================================================================================================

*/

#include <iostream>
using namespace std;


void show_example() {
	cout << "Examples" << endl
		 << "Input: \"xyxy\"" << endl
		 << "Output: \"not prime\"" << endl
		 << endl
		 << "Input: \"aaaa\"" << endl
		 << "Output: \"not prime\"" << endl
		 << endl
		 << "Input: \"hello\"" << endl
		 << "Output: \"prime\"" << endl;
	cout << "===============================" << endl;	
}

string prime_string(string s) {
	// half of the string
	int size = s.size() / 2.0;
	// separate the two string to left and right
	string left, right, answer;

	for (int i = 0; i < s.size(); i++) {
		if (i < size) left += s[i];
		else 		  right += s[i];
	}

	if (left == right) answer = "not prime";
	else 			   answer = "prime";
	return answer;
}

int main()
{
	string input;

	show_example();
	cout << "Input: ";
	getline(cin,input);

	string result = prime_string(input);
	
	cout << "Output: " << result << endl;
	return 0;
}