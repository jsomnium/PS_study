#include <iostream>
using namespace std;
int main() {
	int A, B, V;
	int Day = 1;
	cin >> A >> B >> V;
	Day += (V - A) / (A - B);
	if ((V - A) % (A - B) != 0) Day++;
	if (V <= A) cout << "1";
	else
		cout << Day;
}