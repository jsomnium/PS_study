#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    int b;
    cin >> a >> b;
    
    cout << a.substr(b - 1, 1);
}