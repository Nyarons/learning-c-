/*
=================================================================================================================================

Lab Numbers

A lab number is a number such that the square of any of its prime divisors is still one of its divisors.

For example:
Input: 8
Output: true (2 is a prime divisor of 8, and 2x2=4 is also a divisor of 8)

Input: 50
Output: true (5 is a prime divisor of 50, and 5x5=25 is also a divisor of 50)

Write a program to check if the user input is a Lab number or not.

=================================================================================================================================
*/

#include <iostream>
using namespace std;

void lab_number(int);
bool isPrimeNumber(int);
void prime_numbers();
int main()
{
	int num;

	cout << "Input: ";
	cin >> num;

	lab_number(num);
	//prime_numbers();	
	return 0;
}

void lab_number(int n) {

	int prime_divisor, prime_square;
	bool lab_num = false;

	for (int i = 2; i <= n; i++) {
		if (isPrimeNumber(i)) if (n % i == 0) prime_divisor = i;
	}

	// get the square of the prime number
	prime_square = prime_divisor * prime_divisor;

	if (n % prime_square == 0) {
		lab_num = true;
		cout << " ("<< prime_divisor << " is a prime divisor of " << n << ", and " << prime_divisor << "x" << prime_divisor << " = " << prime_square
		 << " is also a divisor of " << n << ")" << endl;
		}

	cout << boolalpha << "Output: " << lab_num << endl;
}

bool isPrimeNumber(int n) {
	for (int i = 2; i <= n; i++) {
		if (n == i) return true;
		if (n % i == 0) return false;
	}

	return true;
}

// void prime_numbers() {

// 	for (int i = 2; i < 100; i++) {
		
// 		for (int j = 2; j <= i; j++) {
// 			if (i == j) cout << i << endl;
// 			if (i % j == 0) break;
// 		}
// 	}
// }