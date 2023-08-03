#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    queue<int> q;
    stack<int> st;
    int next = 1;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        q.push(num);
    }
    
    while (!q.empty()) {
        if (q.front() == next) {
            q.pop();
            next++;
        } else {
            if (!st.empty() && st.top() == next) {
                st.pop();
                next++;
            } else {
                st.push(q.front());
                q.pop();
            }
        }
    }
    
    while (!st.empty()) {
        if (st.top() != next) {
            cout << "Sad";
            return 0;
        }
        st.pop();
        next++;
    }
    cout << "Nice";
    return 0;
}