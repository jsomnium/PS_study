#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    // 인접하는 두 배열이 동일한지 체크하면 됨
    // 배열에서 필요한 만큼을 추출하는 방법이 substr
    for (int i = 0; i < phone_book.size() - 1; i++){
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())){
            answer = false;
            break;
        }
    }
    
    return answer;
}