#include <string>
#include <vector>
using namespace std;

int solution(string t, string p)
{
    int t_len=t.size(), p_len=p.size();
    long long num = stoll(p);//stoi를 하면 int형을 넘어간 문자열이 들어오므로 abort된다.
    int answer = 0;
    for(int i=0;i<(t_len-p_len+1);i++)
        if (stoll(t.substr(i,p_len)) <= num) answer++;
    return answer;
}
