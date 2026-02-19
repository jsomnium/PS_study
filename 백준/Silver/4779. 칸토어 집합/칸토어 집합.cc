#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void solve(string& str, int start, int len){
    if (len == 1)
        return;

    int part = len / 3;

    for (int i = start + part; i < start + 2 * part; i++){
        str[i] = ' ';
    }

    solve(str, start, part);
    solve(str, start + 2 * part, part);
}

int main(){
    int N;

    while (cin >> N) {
        int total_length = pow(3, N);

        string str(total_length, '-');

        solve(str, 0, total_length);

        cout << str << endl;
    }
}