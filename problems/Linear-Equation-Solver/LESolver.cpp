/*
=================================================================================================================================
Linear Equation Solver

A linear equation is an equation that may be put in the form a * x + b = c, where x is the variable, a, b, c are the coefficients,
which are often real numbers.

The solution of such an equation is the value that, when substituted to the unknown (the x), make the equality true.

For example:
Input: "2x - 3 = 1"
Output: "x = 2"

Input: "3 = 1 + 2x"
Output: "x = 1"

Write a program that reads a linear equation as a string from the user input, solves and outputs the solution.
=================================================================================================================================
*/

#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;

float LE_solver(string);
string strip_space(string); 

int main()
{
	string problem;

	cout << "Input: ";
	getline(cin, problem);

	float solution = LE_solver(problem);

	cout << "Output: x = " << solution << endl;
	return 0;
}

float LE_solver(string problem) {
	string prob = strip_space(problem);
	string temp_data;
	vector<int> data;
	int toInt;
	bool goRight = false;
	int a = 0, b = 1, c = 2;

	for (int i = 0; i < prob.size(); i++) {
		if (prob[i] != 'x' && prob[i] != '=') temp_data += prob[i];
		else if (prob[i] == '=') goRight = true;
		else if (prob[i] == 'x' && goRight) {
			a = 2;
			c = 0;
		}

		if (prob[i] == 'x' || prob[i] == '=' ||i == prob.size()-1){
			stringstream val(temp_data);
			val >> toInt;
			data.push_back(toInt);
			temp_data = "";
		}

	}

	float solution = (data[b] * - 1 + data[c]) / data[a];
	
	return solution;
}

string strip_space(string problem) {
	string spaceless;
	char space = ' ';

	for (int i = 0; i < problem.size(); i++) {
		if(problem[i] != space) spaceless += problem[i];
	}

	return spaceless;
}