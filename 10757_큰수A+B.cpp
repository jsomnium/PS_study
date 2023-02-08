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
			b.insert(0,"0");
		}
	}
	else if (a.length() < b.length()) {
		for (int i = b.length(); i < b.length(); i++) {
			a.insert(0, "0");
		}
	}
	cout << "a : " << b << endl;
	cout << "b : " << a << endl;
	int carry = 0;
	for (int i = 0; a[i]; i++) {
		cout << "first carry : " << carry << endl;
		int zero = 0;
		for (int j = 0; j < i; j++) {
			zero++;
		}
		int temp = 0;
		if (carry > 0) {
			temp = ((int)a[a.length() - 1 - i] - 48) + ((int)b[b.length() - i - 1] - 48) + 1;
			carry = 0;
			cout << "temp : " << temp << endl;
		}
		temp = ((int)a[a.length() - 1 - i] - 48) + ((int)b[b.length() - i - 1] - 48);
		cout << "temp : " << temp << endl;
		if (temp > 10) {
			carry++;
			tempString = to_string(temp - 10);
		}
		else tempString = to_string(temp);
		cout << "tempString: " << tempString << endl;
		cout << "temp: " << temp << endl;
		String.insert(0,tempString);
		cout << "String: " << String << endl;
		cout << "carry : " << carry << endl;
	}
	if (carry == 1) String.insert(0, "1");
	cout << "tempString: " << tempString << endl;
	cout << "String: " << String;
}