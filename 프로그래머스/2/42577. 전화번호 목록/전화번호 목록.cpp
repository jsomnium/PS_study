#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // 정렬해서 인접하는 것 끼리 동일한 숫자가 있는지 체크하면 된다
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++){
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())){
            return false;
        }
    }
    
    return true;
}