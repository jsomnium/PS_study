#include <iostream>
#include <vector>

using namespace std;

// 전역 변수로 관리하면 편합니다
int N, K, cnt = 0, result = -1;
vector<int> tmp; // 병합을 위한 임시 배열

void merge(vector<int>& A, int p, int q, int r) {
    int i = p, j = q + 1, t = 0;

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    // 왼쪽 배열이 남은 경우
    while (i <= q) tmp[t++] = A[i++];
    // 오른쪽 배열이 남은 경우
    while (j <= r) tmp[t++] = A[j++];

    i = p; t = 0;
    while (i <= r) {
        cnt++; // 여기서 저장 횟수를 셉니다!
        if (cnt == K) result = tmp[t]; // K번째 저장되는 값 기록
        
        A[i++] = tmp[t++];
    }
}

void merge_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    vector<int> A(N);
    tmp.resize(N); // 임시 배열 크기 조절

    for (int i = 0; i < N; i++) cin >> A[i];

    merge_sort(A, 0, N - 1);

    cout << result; // K번째 값을 출력 (못 찾았다면 초기값 -1 출력)

    return 0;
}