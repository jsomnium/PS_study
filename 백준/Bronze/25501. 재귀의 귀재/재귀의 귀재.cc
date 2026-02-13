#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int recur_count = 0;

int recursion(const char *s, int l, int r){
    recur_count++; // 호출될 때마다 카운트 증가

    if (l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, (int)strlen(s)-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--){
        string str;
        recur_count = 0;
        cin >> str;
        
        // 3. string 객체를 const char*로 변환하여 전달
        int available = isPalindrome(str.c_str());
        cout << available << " " << recur_count << "\n";
    }
    return 0;
}