#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int N;
    cin >> N;

	while (N--){
		stack<char> st;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); ++i){
			if (s[i] == '('){
                st.push(s[i]);
            }
            else if (s[i] == ')'){
                if (st.empty()) break;
                if (!st.empty() && st.top == '(') st.pop();
            }
		}
		if (st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    
	return 0;
}