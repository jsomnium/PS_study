#include <vector>
using namespace std;

vector<int> solution(int X, vector<vector<int>> H, int Y) {
    // ... (앞서 작성한 IsRestDay와 MonthDays 로직은 동일하게 유지) ...
    // (start_day, IsRestDay, MonthDays 준비 완료 상태 가정)

    vector<int> answer; // 1월부터 12월까지 저장

    int month_base_date = 0; // 각 달의 시작 전까지의 총 일수
    for (int m = 1; m <= 12; m++) {
        int target_full_date = month_base_date + Y; // 원래 월급날(Y일)
        int best_date = Y; // 찾지 못할 경우 기본값 Y

        if (!IsRestDay[target_full_date]) {
            // 1. 만약 원래 월급날이 평일이면 그대로 수령
            best_date = Y;
        } else {
            // 2. 주말/공휴일이면 가장 가까운 평일 탐색
            // d는 거리 (1일 차이, 2일 차이...)
            bool found = false;
            for (int d = 1; d < 31; d++) {
                // "더 이른 날짜 우선"이므로 -d를 먼저 확인
                int prev = Y - d;
                int next = Y + d;

                // 해당 월 범위 내의 이전 날짜(prev) 확인
                if (prev >= 1) {
                    if (!IsRestDay[month_base_date + prev]) {
                        best_date = prev;
                        found = true;
                        break;
                    }
                }

                // 해당 월 범위 내의 다음 날짜(next) 확인
                if (next <= MonthDays[m]) {
                    if (!IsRestDay[month_base_date + next]) {
                        best_date = next;
                        found = true;
                        break;
                    }
                }
            }
            // 3. 만약 해당 월에 평일이 아예 없으면 (조건에 따라) 원래 Y 수령
            if (!found) best_date = Y;
        }

        answer.push_back(best_date);
        month_base_date += MonthDays[m]; // 다음 달 계산을 위해 일수 누적
    }

    return answer;
}
