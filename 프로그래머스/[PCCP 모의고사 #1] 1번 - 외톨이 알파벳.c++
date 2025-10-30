#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(string input_string)
{
    string answer = "";
    map<char, vector<int>> map;

    // e d e aaa bb cc d
    // e d e a b c d
    // e의 위치: 0, 2
    // d의 위치: 1, 6
    // a의 위치: 3, 4, 5
    // b의 위치: 6, 7
    // c의 위치: 8, 9

    // 즉, 알파벳의 인덱스를 체크해서,
    // 연속되는 숫자라면 외톨이 알파벳이 아님.
    // 또한 하나만 있어도 외톨이 알파벳 X

    // 연속되는 숫자가 아닌 수들이 있다면 외톨이 알파벳

    for (int i = 0; i < input_string.size(); i++)
    {
        map[input_string[i]].push_back(i);
    }

    for (const auto &pair : map)
    {
        cout << pair.first << "의 인덱스들 " << endl;

        int prevIndex = -1;
        int nextIndex = -1;
        int cnt = 0;
        for (auto index : pair.second)
        {
            nextIndex = index;

            cout << cnt++ << "회 실행" << endl;
            cout << "nextIndex: " << nextIndex << endl;
            cout << "prevIndex: " << prevIndex << endl;
            cout << "[index]: " << index << endl;

            int size = pair.second.size();

            if (size == 1)
            {
                cout << "size가 1이므로 건너뛰기" << endl;
                break;
            };

            if (prevIndex == -1)
            {
                prevIndex = index;
                continue;
            }

            if (prevIndex + 1 != nextIndex)
            {
                cout << "외톨이 알파벳 찾았다!" << pair.first << endl;
                answer.push_back(pair.first);
                cout << "answer: " << answer << endl;
                break;
            }

            prevIndex = nextIndex;
        }
        cout << endl;
    }

    if (answer == "")
        return "N";

    return answer;
}
