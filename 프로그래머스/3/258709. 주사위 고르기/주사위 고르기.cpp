#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 가능한 모든 주사위 합을 재귀로 계산
void dfs(const vector<vector<int>>& dice, const vector<int>& selected, int depth, int sum, vector<int>& results) {
    if (depth == selected.size()) {
        results.push_back(sum);
        return;
    }

    for (int face : dice[selected[depth]]) {
        dfs(dice, selected, depth + 1, sum + face, results);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int r = n / 2;
    vector<int> answer;

    vector<int> mask(n, 0);
    fill(mask.end() - r, mask.end(), 1);

    int maxWin = -1;
    vector<int> bestComb;

    do {
        vector<int> aIdx, bIdx;
        for (int i = 0; i < n; i++) {
            if (mask[i]) aIdx.push_back(i);
            else bIdx.push_back(i);
        }

        // A, B가 나올 수 있는 모든 합 구하기
        vector<int> aSums, bSums;
        dfs(dice, aIdx, 0, 0, aSums);
        dfs(dice, bIdx, 0, 0, bSums);

        sort(bSums.begin(), bSums.end());

        // A의 승리 횟수 계산
        int win = 0;
        for (int a : aSums) {
            win += lower_bound(bSums.begin(), bSums.end(), a) - bSums.begin();
        }

        if (win > maxWin) {
            maxWin = win;
            bestComb = aIdx;
        }

    } while (next_permutation(mask.begin(), mask.end()));

    // 인덱스를 1-based로 변환해서 반환
    for (int idx : bestComb) answer.push_back(idx + 1);
    return answer;
}
