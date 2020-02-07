/*
Factorial Zeros

The factorial of a non-negative integer n, denoted by n! is the product of all positive integers less than or equal to n. For example, 5! = 5 x 4 x 3 x 2 x 1 = 120.

Write a program to calculate the number of trailing zeros in n! where n is any positive number less than 10^7.

For Example:
Input: 5
Output: 1 (5! = 120 has one trailing zero)

Input: 10
Output: 2 (10! = 3628800 has two trailing zeroes)
*/

#include <iostream>
using namespace std;

long factorial(long);
int trailing_zero(long);
void show_example();
int main()
{
	long n;

	show_example();
	cout << "Input: ";
	cin >> n;

	long result = factorial(n);
	int countZero = trailing_zero(result);

	cout << "Output: ";
	cout << countZero << " (" << n << "! = " << result << " has " << countZero << " trailing zero(s))" << endl;
}

long factorial(long n) {
	if (n == 1) return 1;

	return n * factorial(n-1);
}

int trailing_zero(long num) {
	int count = 0;
	bool done = false;
	int r1, r2;
	int base = 10;
	int base2 = 10;

	// separate last digit from the rest to avoid conflict
	r1 = num % base;

	// if it's zero continue
	if (r1 == 0) {
		count++;
		base *= 10;		// next we need to check tens so increase the base

		while (!done) {

			r2 = num % base;	  // num % 100(base) will give us two digits ex: 132 % 100 = 32
			r2 = r2 - r1;		  // to get the tens remove ones then divide by 10 ex: 32 - 2 = 30
			r2 = r2 / base2;  	  // ex: r2(30) / base2(10)  = 3    [tens(3),ones(2)]
			if (r2 == 0) count++; // if r2 equal to 0 ex: 3 == 0 	increment count
			else done = true;	  // else exit the loop there are no trailing zeros anymore
			r1 = num % base;	  // update the value of r1 as tens... ex: 32 so we can subtract hundrend by the tenth value
			base *= 10;			  // ex: 100 * 10 = 1000, 132 % 1000 = 132 - 32(tens), 100 / base2(100) = 1 
			base2 *= 10;
		}
	}

	return count;
}

void show_example() {
	cout << "For Example:" << endl
		 << "Input: 5" << endl
		 << "Output: 1 (5! = 120 has one trailing zero)" << endl
		 << endl
		 << "Input: 10" << endl
		 << "Output: 2 (10! = 3628800 has two trailing zeroes)" << endl;
	cout << "=================================================" << endl;
	cout << endl;
}