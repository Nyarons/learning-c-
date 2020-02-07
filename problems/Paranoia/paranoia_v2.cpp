/*
Paranoia

This assignment describes a situation in a company.
ByteCorp is a famous technological company in Byteania. 
The CEO of ByteCorp doesn't trust anyone and thinks that his accountant managed to move huge amounts of money to a competitor company, MegaCorp.
He hires a computer crime investigator, and asks him to find inconsistencies in the money transfers. 


Here is a sample transaction log of the company:
Feb SLR 4 M
Feb ENT 800 K
Mar SLR 4000 K
Mar ENT 800 K
Apr SLR 4010 K
Apr ENT 810 K

There are four columns:
1. Month of the transaction
2. Reason of the expense (SLR for "salary", ENT for "entertainment", OTR for "other")
3. Amount
4. M, K, or B (M for million, K for thousands, B for billion)

In the example above, April expenses show an inconsistency and should be reported.

Another example:
Jul SLR 4 M
Jul ENR 800 K
Jul OTR 1200 K
Aug SLR 4000 K
Aug ENR 800 K
Aug OTR 1190 K
Sep SLR 4000 K
Sep ENR 800 K
Sep OTR 1190 K 

Here, July expenses show an inconsistency and should be reported..

As the computer investigator, write a program, which reads the transaction logs, detects inconsistent expenses and prints the exact month containing the "unusual" activities
==================================================================================================================================
*/


#include <iostream>
#include <fstream>
using namespace std;

class Paranoia {
	const int MONTH = 0, REASON = 1, AMOUNT = 2, KMB = 3;
    int ROWS;
	int COLS = 4;
	int another_month;
	string filename,path;

	void count_rows();
	void repeated_months();
	void check_inconsistencies();

	public:
		Paranoia(string f) {
			filename = f;
			path = "log/" + filename;
		}

		void run();
		void display_log();
};


void Paranoia::display_log() {

	ifstream file(path);
	int count = 1;
	string line;

	cout << "========================" << endl;
	while (getline(file,line)) 
	{
		cout << count << ". " <<  line << endl;
		count++;
	}
	cout << "========================" << endl; 

	file.close();
	}

void Paranoia::count_rows() {
	// 1. open the file
	ifstream file(path);

	int count = 0;
	string out;
			
	// 2. count how many line are there in the text.
	while(getline(file,out)) {
		count++;
	}

	file.close();
	// 3. close the file
	ROWS = count;
}

void Paranoia::check_inconsistencies() {
	count_rows();
	repeated_months();
	string data[ROWS][COLS];

	ifstream file(path);		

	string index;				

	for (int i =0; i< ROWS; i++)
	{

		for (int j= 0; j < COLS; j++)
		{
			file >> index;
			data[i][j] = index;

			// if we found a million convert it to thousand
			if (data[i][j] == "M") {
				int increase = stoi(data[i][j-1]);
				data[i][j-1] = to_string(increase * 1000);
				data[i][j] = "K";
			}
		}
	}
	file.close();
	
			
	int move = 0;

	for (int i = 0; i < ROWS; i++)
	{

		int inconsistent = 0;
		for (int j =0 + move; j < ROWS; j+=another_month)
		{
			if (data[i][AMOUNT]!= data[j][AMOUNT]) {			
				inconsistent++;				
			}
											
		}
		if (inconsistent > 1) {
				cout << "Warning! There's an inconsistent expenses in the month of:" << endl;
				cout << data[i][MONTH] << " | " << data[i][REASON] << " | " << data[i][AMOUNT] << data[i][KMB]<< endl; 
		}	

		move++;
		if (move == another_month) move = 0;		
	}
}

void Paranoia::repeated_months() {
	ifstream file(path);

	string out, check_month;
	int count = 0;

	while(file >> out) {
		if (check_month.size() == 0) check_month = out;	// the first value is the month
		if (check_month == out) count++;
	}
	file.close();

	another_month = count;
}

void Paranoia::run() {
	display_log();
	check_inconsistencies();
}

void display_options() {
	cout << "[1] jan-mar" << endl
		 << "[2] apr-jun" << endl
		 << "[3] jul-sep" << endl
		 << "[4] oct-dec" << endl;
	cout << endl;
}

int main()
{
	int select;
	string filename;

	display_options();
	cout << "Select: ";
	cin >> select;
	switch(select) {
		case 1:
			filename = "jan-mar.txt";
			break;
		case 2:
			filename = "apr-jun.txt";
			break;
		case 3:
			filename = "jul-sep.txt";
			break;
		case 4:
			filename = "oct-dec.txt";
			break;
		default:
			cout << "Invalid!" << endl;
			return 0;
	}

	Paranoia paranoia(filename);
	paranoia.run();
	return 0;
}