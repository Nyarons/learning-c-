/*
=================================================================================================================================
Array Partitioning

Divide a given array of numbers into two subarrays such that the absolute difference between their sums is the smallest possible. 
For example, the array [2, 5, 4, 7, 15, 20] can be divided into subarrays [15, 7, 4] and [20, 5, 2]. 
The difference between the sums of those arrays is 1, and it is the smallest.

For example:
Input:
6
4, 15, 20, 2, 7, 5

Output:
[15, 7, 4]
[20, 5, 2]
1
(The sum of the first subarray is 26, the sum of the second subarray is 27, the difference is 1.)
=================================================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

void array_partitioning(vector<int>);
int array_sum(vector<int>);
vector<int> sorted_descending(vector<int>);

int main()
{
	int len,user_input;
	vector<int> arr_vec;

	cout << "Input array length: ";
	cin >> len;

	cout << "Input array: ";
	for (int i = 0; i < len; i++) {
		cin >> user_input;
		arr_vec.push_back(user_input);
	}

	array_partitioning(arr_vec);
	return 0;
}

void array_partitioning(vector<int> array) {

	
}

int array_sum(vector<int> array) {
	int sum_element = 0;
	for (int i = 0; i < array.size(); i++)  sum_element += array[i];

	return sum_element;
}

vector<int> sorted_descending(vector<int> arr_vec) {
	// bubble sort descending order
	int temp;
	for (int i = 0; i < arr_vec.size(); i++) {
		for (int j = 0; j < arr_vec.size()-1-i; j++) {
			temp = arr_vec[j];

			if (arr_vec[j] < arr_vec[j+1]) {
				arr_vec[j] = arr_vec[j+1];
				arr_vec[j+1] = temp;
			}
		}
	}
	return arr_vec;
}