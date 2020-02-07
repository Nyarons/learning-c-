/*
==================================================================================================================================
Calculate the Distance

A Cartesian plane is defined by two perpendicular number lines: the x-axis, which is horizontal, and the y-axis, which is vertical.
Using these axes, we can describe any point in the plane using an ordered pair of numbers.

Task:
Write a program which takes two different points, A(x1,y1) and B(x2,y2), and returns the distance between these two points.
The distance formula is the Pythagorean Theorem: 


For example:
Input: (2, 2) (2, -4)
Output: 6

Input: (5, 1) (9, 4)
Output: 5

Input: (3, 3) (0, 0)
Output: 4.24
==================================================================================================================================
*/

#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

class CVector
{
	string location;
public:
	double x, y;
	CVector(string loc) {
		location = loc;
		xyFromString();
	};

	void xyFromString();
	double dist(CVector);
	double mag();
	void normalize();
	void output();
	void mul(float);
	void div(float);
	void add(CVector);
	void sub(CVector);
};

void CVector::xyFromString() {
	string temp;
	bool empty = true;

	for (int i = 0; i < location.size(); i++) {
		// bug if we ignore negative sign
		if (isdigit(location[i]) || location[i] == '-') {
			temp += location[i];
		}

		if (location[i] == ',' || location[i] == ')') {

			stringstream val(temp);

			if (empty) {
				 val >> x;
				 empty = false;
			}
			else val >> y;

			temp = "";
		}
	}
}


void CVector::mul(float scale) {
	x = x * scale;
	y = y * scale;
}

void CVector::div(float scale) {
	x = x / scale;
	y = y / scale;
}

void CVector::sub(CVector other) {
	x = x - other.x;
	y = y - other.y;
}

void CVector::add(CVector other) {
	x = x + other.x;
	y = y + other.y;
}

double CVector::dist(CVector other) {
	double distance;
	
	distance = sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	return distance;
}

double CVector::mag() {
	double magnitude;

	magnitude = sqrt(pow(x,2) + pow(y,2));
	return magnitude;
}

void CVector::normalize() {
	x = x / mag();
	y = y / mag();
}

void CVector::output() {
	cout << "(" << x << ", " << y << ")" << endl;
}


void show_example();

int main()
{

	string loc1, loc2;

	show_example();
	cout << "Input: ";
	cin >> loc1 >> loc2;

	CVector vec1(loc1);
	CVector vec2(loc2);

	double distance = vec1.dist(vec2);

	cout << "Output: " << distance << endl;

	vec1.normalize();
	vec1.output();
	return 0;
}

void show_example() {
	cout << "For example:" << endl
		 << "Input: (2, 2) (2, -4)" << endl
		 << "Output: 6" << endl
		 << endl
		 << "Input: (5, 1) (9, 4)" << endl
		 << "Output: 5" << endl
		 << endl
		 << "Input: (3, 3) (0, 0)" << endl
		 << "Output: 4.24" << endl;
	cout << "============================" << endl;
}