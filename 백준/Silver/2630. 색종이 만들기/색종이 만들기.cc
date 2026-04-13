#include <iostream>
#include <vector>

using namespace std;

int N;
int paper[128][128];
int white = 0;
int blue = 0;

// 해당 영역이 모두 같은 색인지 체크하는 함수
bool is_uniform(int y, int x, int size) {
    int color = paper[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

// 분할 정복 함수
void solve(int y, int x, int size) {
    // 1. 현재 영역이 모두 같은 색인가?
    if (is_uniform(y, x, size)) {
        if (paper[y][x] == 0) white++;
        else blue++;
        return;
    }

    // 2. 다른 색이 섞여 있다면 4등분으로 쪼개기
    int next_size = size / 2;
    solve(y, x, next_size);                         // 왼쪽 위
    solve(y, x + next_size, next_size);             // 오른쪽 위
    solve(y + next_size, x, next_size);             // 왼쪽 아래
    solve(y + next_size, x + next_size, next_size); // 오른쪽 아래
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}