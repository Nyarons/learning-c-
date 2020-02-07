

#include <iostream>
using namespace std;

void anagram(string s1, string s2) {
	string result, temps2;
	string str1 = s1, str2 = s2;

	if (str1.size() == str2.size()) {
		for (int i = 0; i < str1.size(); i++) {
			bool more = true;
			for (int j = 0; j < str2.size(); j++) {
				if (str1[i] == str2[j] && more) {
					result += str2[j];
					more = false;
				} else {
					temps2 += str2[j];
				}
			}
			str2 = temps2;
			temps2 = "";
		}

		if (str1 == result) cout << "yes, " << s2 << " is anagram of " << s2 << endl;
		else 			  cout << "no, they are not an anagram" << endl;

	} else {
		cout << s1 << " is not an anagram of " << s2 << endl;
	}

}

int main()
{
	string s1, s2;
	cout << "Input s1: ";
	cin >> s1;
	cout << "Input s2: ";
	cin >> s2;

	anagram(s1,s2);
	

	return 0;
}