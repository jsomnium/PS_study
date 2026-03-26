#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // LIS의 형태를 유지할 벡터 (실제 수열과는 다를 수 있지만 길이는 정확함)
    vector<int> lis;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // 리스트가 비어있거나, 현재 숫자가 리스트의 마지막 값보다 크면 뒤에 추가
        if (lis.empty() || lis.back() < num) {
            lis.push_back(num);
        } // 현재 숫자가 마지막 값보다 작거나 같다면, 적절한 위치를 찾아 교체
        else {
            // lower_bound는 num보다 크거나 같은 첫 번째 원소의 포인터(반복자)를 반환
            auto it = lower_bound(lis.begin(), lis.end(), num);
            // 해당 위치의 값을 num으로 덮어씀 (더 작은 값으로 교체하여 유리하게 만듦)
            *it = num;
        }
    }

    cout << lis.size() << "\n";

    return 0;
}