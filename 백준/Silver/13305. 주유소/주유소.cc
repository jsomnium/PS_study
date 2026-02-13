#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> LoadLength(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> LoadLength[i];

    vector<long long> OilPrice(N);
    for (int i = 0; i < N; i++) cin >> OilPrice[i];

    long long final_price = 0;
    long long min_price = OilPrice[0];

    for (int i = 0; i < N - 1; i++) {
        // 지금까지 본 주유소 중 더 싼 곳이 있다면 최저가 갱신
        if (OilPrice[i] < min_price) {
            min_price = OilPrice[i];
        }

        // 현재 가장 싼 기름값으로 다음 도시까지 이동
        final_price += (min_price * LoadLength[i]);
    }

    cout << final_price;
    return 0;
}