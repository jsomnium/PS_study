#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int X, vector<vector<int>> H, int Y) {
    // 1. 초기 설정 및 요일 보정 (1~7 -> 0:월 ~ 6:일)
    int start_day = X - 1;
    vector<bool> IsRestDay(366, false);
    vector<int> MonthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 2. 주말(토, 일)을 먼저 휴일로 표시
    for (int i = 1; i <= 365; i++) {
        int day_of_week = (start_day + (i - 1)) % 7;
        if (day_of_week == 5 || day_of_week == 6) {
            IsRestDay[i] = true;
        }
    }

    // 3. 모든 공휴일을 "먼저" 표시 (대체 공휴일 탐색 시 중복 방지용)
    vector<int> holiday_dates;
    for (auto h : H) {
        int m = h[0], d = h[1];
        int full_date = 0;
        for (int i = 1; i < m; i++) full_date += MonthDays[i];
        full_date += d;
        
        holiday_dates.push_back(full_date);
        IsRestDay[full_date] = true;
    }

    // 4. 주말과 겹치는 공휴일에 대해 대체 공휴일 로직 적용
    for (int d : holiday_dates) {
        int day_of_week = (start_day + (d - 1)) % 7;

        if (day_of_week == 5) { // 토요일이면 이전 평일로
            int temp = d;
            while (temp >= 1 && IsRestDay[temp]) temp--; 
            if (temp >= 1) IsRestDay[temp] = true;
        } 
        else if (day_of_week == 6) { // 일요일이면 이후 평일로
            int temp = d;
            while (temp <= 365 && IsRestDay[temp]) temp++; 
            if (temp <= 365) IsRestDay[temp] = true;
        }
    }

    // 5. 월급날 계산 (매월 Y일 기준 가장 가까운 평일 탐색)
    vector<int> answer;
    int month_base_date = 0; // 각 달의 누적 일수

    for (int m = 1; m <= 12; m++) {
        int target_full_date = month_base_date + Y;
        int best_date = Y;

        // 원래 월급날이 휴일(주말/공휴일)인 경우 탐색 시작
        if (IsRestDay[target_full_date]) {
            bool found = false;
            // 거리(dist)를 1일부터 30일까지 늘려가며 탐색
            for (int dist = 1; dist < 31; dist++) {
                int prev = Y - dist;
                int next = Y + dist;

                // "더 이른 날짜 우선"이므로 prev를 먼저 체크
                if (prev >= 1) {
                    if (!IsRestDay[month_base_date + prev]) {
                        best_date = prev;
                        found = true;
                        break;
                    }
                }
                // 이후 날짜 체크
                if (next <= MonthDays[m]) {
                    if (!IsRestDay[month_base_date + next]) {
                        best_date = next;
                        found = true;
                        break;
                    }
                }
            }
            // 해당 월에 평일이 하나도 없으면 조건에 따라 Y 유지 (예외 처리)
            if (!found) best_date = Y;
        } else {
            // 평일이면 그대로 수령
            best_date = Y;
        }

        answer.push_back(best_date);
        month_base_date += MonthDays[m]; // 다음 달로 이동
    }

    return answer;
}
