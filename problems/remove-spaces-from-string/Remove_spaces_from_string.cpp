/*
Remove Spaces from a String

Given a string as input, output it without spaces.

For example:
string = "ab c  d e fgh i  j kl mn  opqr  stuvwxyz"
result = "abcdefghijklmnopqrstuvwxyz"
*/

#include <iostream>
#include <string>
using namespace std;

void display_problem() {
	cout << "Remove Spaces from a String" << endl
		 << "Given a string as input, output it without spaces." << endl
		 << "For example:" << endl
		 << "string = \"ab c  d e fgh i  j kl mn  opqr  stuvwxyz\"" << endl
  		 << "result = \"abcdefghijklmnopqrstuvwxyz\"" << endl << endl;
}

int main() 
{
	display_problem();

	string text, removed_spc;
	char space = ' ';

	cout << "Input string: ";
	getline(cin,text);

	for (int i = 0; i < text.size(); i++) {
		if (text[i] != space)	removed_spc+= text[i];
	}

	cout << "string: " << text <<endl;
	cout << "Result: " << removed_spc << endl; 

	return 0;
}