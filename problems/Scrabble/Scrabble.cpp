/*
=================================================================================================================================
Scrabble

Give a variable number of words, create a program to output the word with the maximum score, based on the following scoring system:
The score of a word is calculated based on its character values, according to this table:
e, a, i, o, n, r, t, l, s, u are equal 1 point
d, g	2 points
b, c, m, p	3 points
f, h, v, w, y 4 points
k 5 points
j, x 8 points
q, z 10 points

The max length of a word is 10 letters.

For example: 
input { "This",  "is", "a", "cool" , "Challenge" }
output : Challenge
=================================================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

void scrabble(string);
int get_score(string);
void display_problem();
int main()
{
	string data;

	display_problem();
	cout << "Input: ";
	getline(cin, data);

	scrabble(data);

	return 0;
}

void display_problem() {
	cout << "Scrabble" << endl
		 << endl
		 << "Give a variable number of words, create a program to output the word with the maximum score, based on the following scoring system:" << endl
		 << "The score of a word is calculated based on its character values, according to this table:" << endl
		 << "e, a, i, o, n, r, t, l, s, u are equal 1 point" <<endl
		 << "d, g	2 points" << endl
		 << "b, c, m, p	3 points" << endl
		 << "f, h, v, w, y 4 points " <<endl
		 << "k 5 points" << endl
		 << "j, x 8 points" << endl
		 << "q, z 10 points" << endl;

	cout << "The max length of a word is 10 letters." << endl
		 << endl
		 << "For example: " << endl
		 << "input { \"This\",  \"is\", \"a\", \"cool\" , \"Challenge\" } " << endl
		 << "output : Challenge" << endl;
	cout << "============================================================================" << endl;
}

void scrabble(string data) {

	bool begin = false;
	string word, bestWord;
	int bestScore = 0;
	int word_score;

	// The idea is we want to loop from every char in an array
	// and begin getting the char if it enclose by double quote ("") to get the whole word
	// if we found one calculate the score from get_score function
	// then if we found another word compare it to the previous to see
	// which one has a better score so we can get the best score
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == '"') {
			begin = !begin;
		}

		if (begin) {
			if (data[i] != '"') word += data[i];
		}

		if (data[i] == '"' && !begin) {
			word_score = get_score(word);

			if (word_score > bestScore) {
				bestScore = word_score;
				bestWord = word;
				word = "";
			}
		}
	}
	cout << "Output: " << bestWord << endl;
	cout << "Score: " << bestScore << endl;
}



int get_score(string word) {
	string one = "aeiounrtls";
	string two = "dg";
	string three = "bcmp";
	string four = "fhvmy";
	string eight = "jx";
	string ten = "qz";
	vector<string> scoring = {one, two, three, four, eight, ten};
	int totalScore = 0;

	for (int i = 0; i < scoring.size(); i++) {

		string letters = scoring[i];
		for (int j = 0; j < letters.size(); j++) {

			for (int k = 0; k < word.size(); k++) {

				if (word[k] == letters[j]) {
					switch(i) 
					{
						case 0:
							totalScore += 1;
							break;
						case 1:
							totalScore += 2;
							break;
						case 2:
							totalScore += 3;
							break;
						case 3:
							totalScore += 4;
							break;
						case 4:
							totalScore += 8;
						 	break;
						case 5:
							totalScore += 10;
							break;
					}
				}
			}
		}

	}
		return totalScore;
}