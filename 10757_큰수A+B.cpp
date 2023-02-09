#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int plusNum = 0;
	string tempString = "";
	string String = "";

	if (a.length() > b.length()) {
		for (int i = b.length(); i < a.length(); i++) {
			b.insert(0, "0");
		}
	}
	else if (a.length() < b.length()) {
		for (int i = b.length(); i < b.length(); i++) {
			a.insert(0, "0");
		}
	}
	int carry = 0;
	for (int i = 0; a[i]; i++) {
		int temp = 0;
		if (carry > 0) {
			temp = ((int)a[a.length() - 1 - i] - 48) + ((int)b[b.length() - i - 1] - 48) + 1;
			carry = 0;
		}
		else temp = ((int)a[a.length() - 1 - i] - 48) + ((int)b[b.length() - i - 1] - 48);
		if (temp >= 10) {
			carry++;
			tempString = to_string(temp - 10);
		}
		else tempString = to_string(temp);
		String.insert(0, tempString);
		/*
		cout << "carry: " << carry << endl;
		cout << "temp: " << temp << endl;
		cout << "String: " << String << endl;
		*/
	}
	if (carry == 1) String.insert(0, "1");
	cout << String;
}