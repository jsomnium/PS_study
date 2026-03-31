#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long N;
    cin >> N;

    vector<int> lis;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;

        if (lis.empty() || lis.back() < num){
            lis.push_back(num);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            *it = num;
        }
    }

    cout << lis.size() << endl;
}