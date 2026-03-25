#include <vector>
#include <algorithm>

using namespace std;

bool can_survive(int mid, int n, int k, const vector<int>& enemy) {
    vector<int> rounds;
    
    // 0부터 mid 라운드까지의 적들을 복사
    for (int i = 0; i <= mid; i++) rounds.push_back(enemy[i]);
    
    // 내림차순 정렬 (큰 놈들부터 무적권 쓰기 위해)
    sort(rounds.begin(), rounds.end(), greater<int>());
    
    long long required_n = 0;
    for (int i = k; i < rounds.size(); i++) {
        required_n += rounds[i];
    }
    
    return required_n <= n;
}

int solution(int n, int k, vector<int> enemy) {
    int low = 0, high = enemy.size() - 1;
    int answer = 0;

    if (k >= enemy.size()) return enemy.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_survive(mid, n, k, enemy)) {
            answer = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return answer;
}