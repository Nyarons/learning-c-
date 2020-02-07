/*
======================================================================================================================== 
String Rotations

Create a function that accepts a string argument and returns an array of strings, which are shifted versions of the argument string.

Sample Input
"Hello"

Sample Output
["elloH", "lloHe", "loHel", "oHell", "Hello"]  

As you can see from the example above, each element shifts the first character of the previous version to the end.
The original string should be included in the output array. The order matters; each element of the output array should be the shifted version of the previous element.
The output array should have the same length as the input string. 
The function should return an empty array when a zero-length String is provided as the argument.
======================================================================================================================== 
*/

#include <iostream>
using namespace std;

void string_rotation(string);
void show_array(string*, int);
void show_example();
int main()
{
	string input;

	show_example();
	cout << "Input: ";
	getline(cin,input);

	string_rotation(input);	
	return 0;
}

void string_rotation(string original) {
	int first_index = 0;
	string word = original;
	string append;
	string rotated[word.size()];

	for (int i = 0; i < word.size(); i++) {

		for (int j = 0; j < word.size(); j++) {
			if (j != first_index) append += word[j];
		}

		word = append + word[first_index];
		append = "";

		rotated[i] = word;
		if (word == original) break;
	}	

	cout << "Output: " << endl;
	show_array(rotated, word.size());
}


void show_array(string* rotated_strings, int len) {
	char dquote = '\"';

	cout << endl;
	cout << "[";
	for (int i = 0; i < len; i++) {
		cout << dquote << rotated_strings[i] << dquote;
		if (i != len-1) cout << ", ";
	}
	cout << "]" << endl;
}

void show_example() {
	cout << "Sample Input" << endl;
	cout << "Hello" << endl;
	cout << endl;
	cout << "Sample Output" << endl;
	cout << "[\"elloH\", \"lloHe\", \"loHel\", \"oHell\", \"Hello\"]" << endl;
	cout << "=============================================" << endl;
}