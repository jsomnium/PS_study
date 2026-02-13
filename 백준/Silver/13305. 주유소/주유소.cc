#include <iostream>
#include <vector>
using namespace std;

int main(){
    // 도시의 개수
    int N;
    cin >> N;

    // 원 안의 수: 주유소의 리터당 가격
    // 도로 위의 수: 도로의 길이 (소모하는 기름)
    vector<int> LoadLength(N - 1, 0);
    vector<int> OilPrice(N, 0);

    for (int i = 0; i < N - 1; i++) cin >> LoadLength[i];
    for (int i = 0; i < N; i++) cin >> OilPrice[i];

    // 만약 현재 도시의 기름 가격보다, 다음 도시의 기름 가격이 더 싸다면 다음 도시에서 기름을 더 채운다
    int cur_oil_price;
    int final_price = 0;

    for (int i = 0; i < N - 1;)
    {
        cur_oil_price = OilPrice[i];

        while (cur_oil_price <= OilPrice[i]){
            final_price += cur_oil_price * LoadLength[i];
            i++;
        }
    }

    cout << final_price;
    return 0;
}