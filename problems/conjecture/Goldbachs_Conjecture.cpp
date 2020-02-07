/*
=================================================================================================================================
Goldbach's Conjecture

Goldbach's conjecture is a rule in math that states the following: every even number greater than 2 can be expressed as the sum of two prime numbers. 

Write a program that finds every possible pair of prime numbers, whose sum equals the given number or a set of numbers within a range.

For example:
Input: 16
Output:
3 + 13
5 + 11

Input: 32
Output: 
3 + 29
13 + 19

Input: 4, 8
Output: 
4: 2 + 2  
6: 3 + 3  
8: 3 + 5
=================================================================================================================================
*/

#include <iostream>
using namespace std;


bool isPrime(int);
void goldbach(int);
int main()
{
	int num;

	cout << "Input: ";
	cin >> num;


	goldbach(num);
	return 0;
}


void goldbach(int num) {
	for (int i = 2; i < num; i++) {
		if (isPrime(i)) {
			for (int j = 2; j <= num/2; j++) {
				if (isPrime(j)) {
					int result = i +j;
					if (result == num) cout << i << " + " << j << endl;
				}
			}
		}
	}

}

bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
