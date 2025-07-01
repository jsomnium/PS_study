#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    int n = citations.size();
    int h = 0;
    
    for (int i = 0; i < n; i++) {
        int possibleH = n - i;
        if (citations[i] >= possibleH) {
            h = possibleH;
            break;
        }
    }
    
    return h;
}
