#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> trees(N, 0);
    
    long long hi = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (hi < trees[i]) hi = trees[i];
    }
    
    sort(trees.begin(), trees.end());
    
    long long lo = 0;
    long long ans = 0;
    
    while (lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        long long tempHeight = 0;
        
        for (int t : trees){
            if (t > mid) tempHeight += (t - mid);
        }
        
        if (tempHeight >= M){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    cout << ans << endl;
}