#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void display_options();
void display_log(string);
void check_inconsistencies(string);
int count_rows(string);

int main()
{
	int select;
	string filename;

	display_options();
	cout << "Select: ";
	cin >> select;

	switch(select) {
		case 1:
			filename = "feb-apr.txt";
			break;
		case 2:
			filename = "jul-sep.txt";
			break;
		case 3:
			filename = "oct-dec.txt";
			break;
		default:
			cout << "Invalid!" << endl;
	}

	display_log(filename);
	check_inconsistencies(filename);

	return 0;
}


void display_options() {
	cout << "[1] feb-apr" << endl
		 << "[2] jul-sep" << endl
		 << "[3] oct-dec" << endl;
	cout << endl;
}


void display_log(string filename) {
	// 1. open the file
	ifstream file("log/" + filename);
	// 2. set the index of a line and initialize the line to be outputed
	int count = 1;
	string line;
	cout << "========================" << endl;

	// 3. get the line in the text file then output it.
	while (getline(file,line)) {
		cout << count << ". " <<  line << endl;
		count++;
	}
	cout << "========================" << endl; 
	// 4. close the file
	file.close();
}

void check_inconsistencies(string filename) {

	const int ROWS = count_rows(filename);	// 1. get the number of rows need for the array
	const int MONTH = 0, REASON = 1, AMOUNT = 2, KMB = 3, COLS = 4;	
											// COLS is default to 4 because expenses log has 4 columns which means array needs 4 columns

	ifstream file("log/" + filename);		// 3. open the file

	string index;
	string data[ROWS][COLS];				// create an array of rows and columns


	// 4. 2D array to store every log from text to string data[ROWS][COLS] array
	for (int i =0; i< ROWS; i++) {

		for (int j= 0; j < COLS; j++) {
			file >> index;
			data[i][j] = index;

			// if we found a million convert it to thousand
			if (data[i][j] == "M") {
				int increase = stoi(data[i][j-1]);
				data[i][j-1] = to_string(increase * 1000);
			}
		}


	}

	//5. create a temporary array where we can check the inconsistencies of expenses
	string temp[ROWS][COLS] = data;

	// 6. move downwards after a loop to check another index
	int move = 0;
	//int another_month = repeated_months(data);
	// 7. for every rows 
	for (int i = 0; i < ROWS; i++) {
		// 8. to check whether an inconsistecy happend we want to count the inequalities of expenses
		int inconsistent = 0;
		for (int j =0 + move; j < ROWS; j+=3) {
			if (temp[i][AMOUNT]!= data[j][AMOUNT]) {			// 9. for every index of temp[i][column of amount] check 
				inconsistent++;									// 10. if != data[j][column of amount] note j+=another_month means jump the loop to another month
			}
			if (inconsistent > 1) {
			cout << "Warning! There's an inconsistent expenses in the month of:" << endl;
			cout << data[i][MONTH] << " | " << data[i][REASON] << " | " << data[i][AMOUNT] << data[i][KMB]<< endl; 
			}													// 11. if inconsistecy is greater than 2 then we found one!
		}
		move++;
		if (move == 3) move = 0;								// 12. if it reaches another month reset the checking of month to first index
	}

	
}

int count_rows(string filename) {
	// 1. open the file
	ifstream file("log/" + filename);

	int count = 0;
	string out;
	
	// 2. count how many line are there in the text.
	while(getline(file,out)) {
		count++;
	}

	file.close();
	// 3. close the file
	return count;
}
