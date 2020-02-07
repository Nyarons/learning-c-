/*
==================================================================================================================================

Summations Calculator

Create a program that takes 3 inputs, a lower bound, an upper bound and the expression. Calculate the sum of that range based on the given expression and output the result.

For Example:
Input: 2 4 *2
Output: 18 (2*2 + 3*2 + 4*2)

Input: 1 5 %2
Output: 3 (1%2 + 2%2 + 3%2 + 4%2 + 5%2)
==================================================================================================================================
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
double calculator(double,char,double);
void summation_calc(double, double, char, double);

void show_example(){
	cout << "For Example:\n"
		 << "Input: 2 4 *2\n"
		 << "Output: 18 (2*2 + 3*2 + 4*2)\n\n"

		 << "Input: 1 5 %2\n"
		 << "Output: 3 (1%2 + 2%2 + 3%2 + 4%2 + 5%2) " << endl;
	cout << "==================================================" << endl;
}


int main()
{
	string mode;
	double lower, upper, val;
	char op;

	show_example();
	cout << "Input: ";
	cin >> lower >> upper >> op >> val;

	summation_calc(lower, upper, op,val);

	return 0;
}

void summation_calc(double l, double u, char op, double val) {

	double sum = 0;
	string equation;
	for (int x = l; x <= u; x++) {

		if (x == l) equation += "(";

		sum += calculator(x,op,val);
		equation += to_string(x) + op + to_string(int(val));
		if (x == u) equation += ")";
		if (x != u) equation += " + ";
	}
	cout << "Output: " << sum << " " << equation<< endl;

}

double calculator(double x, char op, double val) {
	double result;
		 if (op == '+') result = x + val;
	else if (op == '-') result = x - val;
	else if (op == '*') result = x * val;
	else if (op == '/') result = x / val;
	else if (op == '%') result = abs(remainder(x,val));

	return result;
}