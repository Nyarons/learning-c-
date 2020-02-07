/*
=================================================================================================================================
Anadrome

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase. For example, "Sool" is an anagram for "Solo".

A palindrome is a word or phrase which reads the same backward as forward, such as "madam".

An anadrome is a word or phrase if any of its anagrams form a palindrome.

For example:
Input: "SoloSolo"
Output: yes ("SoollooS" is an anagram of "SoloSolo" which also is a palindrome).

Input: "3haha"
Output: yes ("ha3ah" is an anagram of "3haha" which also is a palindrome).

Input: "Solo"
Output: no

Write a program to check if the user input is an anadrome or not. 
=================================================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// exmple input/output
void show_example();

// Anadrome
string get_unique_char(string);
vector<int> get_char_count(string, string);
string anadrome(string);

// Palindrome
int count_odd_strings(string);
bool isPalindrome(string);
bool itContains(char,string);
int remove_space_from(string);


int main()
{
	string word, palindrome_res;
	bool result;

	show_example();
	cout << "Input: ";
	getline(cin,word);

	result = isPalindrome(word);
	cout << boolalpha << "Output: " << result << endl;
	if (result) {
		palindrome_res = anadrome(word);
		cout << "\t(\"" << palindrome_res <<"\" is an anagram of \"" << word << "\" which is also a palindrome!)" << endl;
	}
	else 			cout << " (Can't form a palindrome)" << endl;


	return 0;
} 

void show_example() {
	cout << "For example:" << endl
		 << "Input: \"SoloSolo\"" << endl
		 << "Output: yes (\"SoollooS\" is an anagram of \"SoloSolo\" which also is a palindrome)." << endl
		 << endl
		 << "Input: \"3haha\"" << endl
		 << "Output: yes (\"ha3ah\" is an anagram of \"3haha\" which also is a palindrome)." << endl
		 << endl
		 << "Input: \"Solo\"" <<  endl
		 << "Output: no" << endl;
	cout << "================================================================================" << endl;
	cout << endl;
}


//====================================================================================
bool isPalindrome(string word) {
	int oddLen = remove_space_from(word) % 2;
	int odd_string = count_odd_strings(word);
	bool palindrome;

	if 	    (odd_string == 0 && !oddLen) palindrome = true;
	else if (odd_string == 1 && oddLen)  palindrome = true;
	else if (word.size() < 2          )  palindrome = false;
	else								 palindrome = false;

	return palindrome;
}


int count_odd_strings(string word) {
	int odd_nums = 0;
	int isOddNum;
	int counter;
	string repeated;

	for (int i = 0; i < word.size();i++) {

		if 	    (word[i] == ' ' || word[i] ==',') continue;
		else if (itContains(word[i],repeated))    continue;
		else 							        repeated += word[i];

		counter = 0;
		for (int j = 0; j < word.size(); j++) {
			if (word[i] ==  word[j]) counter++;
		}

		isOddNum = counter % 2;
		if (isOddNum) odd_nums++;
	}
	return odd_nums;
}

// to stop any duplicate character checking
bool itContains(char c, string repeated) {

	for (int i = 0; i < repeated.size(); i++) {
		if (c == repeated[i]) return true;
	}
	return false;
}

int remove_space_from(string word) {
	string no_space;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == ' ') continue;
		no_space += word[i];
	}
	return no_space.size();
}


// =========================================================================
string get_unique_char(string word) {
	string unique_char;

	for (int i= 0; i < word.size(); i++) {
		if (itContains(word[i],unique_char)) continue;
		else unique_char += word[i];
	}

	return unique_char;
}

vector<int> get_char_count(string unique_char, string word) {
	vector<int> char_count;
	int count_char;

	for (int i = 0; i < unique_char.size(); i++) {
		count_char = 0;
		for (int j = 0; j < word.size(); j++) {
			if (unique_char[i] == word[j]) count_char++;
		}
		char_count.push_back(count_char);
	}

	return char_count;
}

string anadrome(string word) {
	string unique_char;
	vector<int> char_count;

	string half, mid, combine;
	
	unique_char = get_unique_char(word);
	char_count = get_char_count(unique_char,word);


	for (int i = 0; i < unique_char.size(); i++) {
		if (char_count[i] == 1 || char_count[i] % 2 == 1) mid = unique_char[i];
		for (int j= 0; j < char_count[i]/2; j++) {
			half += unique_char[i];
		}
	}

	combine = half + mid;
	for (int i = half.size()-1; i >= 0 ; i--) {
		combine += half[i];
	}

	return combine;

}