// Password Validator

// Password validator is a program that validates passwords to match specific rules.
// For example, the minimum length of the password must be eight characters long and
// it should have at least one uppercase letter in it. 

// A valid password is the one that conforms to the following rules:
//  - Minimum length is 5;
//  - Maximum length is 10;
//  - Should contain at least one number;
//  - Should contain at least one special character (such as &, +, @, $, #, %, etc.);
//  - Should not contain spaces.

// Examples:
// Input: "Sololearn"
// Output: false

// Input: "John Doe"
// Output: false

// Input: "$ololearn7"
// Output: true

// Write a program to checks if the user input is a valid password or not.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class Validator {
	string pass;
	int pass_length;

	bool valid_pass_length() {
		bool valid = false;
		int min_length = 5;
		int max_length = 10;

		if ((pass_length >= min_length) && (pass_length <= max_length)) {
			valid = true;
		}
		return valid;
	}

	bool contains_number() {
		bool valid = false;
		for (int i = 0; i < pass.size(); i++) {
			if (isdigit(pass[i])) {
				valid = true;
				break;
			}
		}
		return valid;
	}

	bool contains_schar() {
		bool valid = false;
		string special_char = "!@#$%^&*()_+-=`~";

		for (int i = 0; i < pass.size(); i++) {

			for (int j = 0; j < special_char.size(); j++) {
				if (pass[i] == special_char[j]) {
					valid = true;
					break;
				}
			}
		}
		return valid;
	}

	bool no_spaces() {
		bool valid = true;
		char space = ' ';
		for (int i = 0; i < pass.size(); i++) {
			if (pass[i] == space) {
				valid = false;
				break;
			}
		}
		return valid;
	}
public:

	Validator() {
	}

	void getPassword(string password) {
		pass = password;
		pass_length = password.size();
	}

	void display_condition() {
		cout << "Condition" << endl;
		cout << "- Minimum length is 5" << endl
	 		 << "- Maximum length is 10" << endl
	 		 << "- Should contain at least one number" << endl
	 		 << "- Should contain at least one special character (such as &, +, @, $, #, %, etc.)" << endl
	 		 << "- Should not contain spaces." << endl;
	 	cout << "--------------------------------------------------------------------------------" << endl;
	}

	bool check_result() {
		bool valid = false;

		if (valid_pass_length()) {
			cout << "1. valid length /" << endl;
			if (contains_number()) {
				cout << "2. contains a number /" << endl;
				if (contains_schar()) {
					cout << "3. contains special character /" << endl;
					if (no_spaces()) {
						cout << "4. no spaces /" << endl;
						valid = true;
					}
				}
			}
		}
		return valid;
	}

};

string get_input();

int main()
{
	Validator validator;
	bool result;

	validator.display_condition();
	string password = get_input();
	validator.getPassword(password);

	result = validator.check_result();
	
	cout << boolalpha << "\nOutput: " << result << endl;

	return 0;
}

string get_input() {
	string password;

	cout << "Input: ";
	getline(cin,password);

	return password;
}

