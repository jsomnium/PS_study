#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N, K; // 응시자 수, 수상자 수
    cin >> N >> K;
    
    vector<int> Student (N, 0);
    
    for (int i = 0; i < N; i++) cin >> Student[i];
    
    sort(Student.begin(), Student.end(), greater<int>());
    
    cout << Student[K-1] << endl;
    
    return 0;
}