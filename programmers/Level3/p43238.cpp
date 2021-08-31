// 문제 : 입국심사 (Level 3)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/43238)
// 풀이 : https://dev-sbee.tistory.com/ 참고
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    // 이분 탐색을 위한 left, right, mid 선언 및 초기화
    long long left = 1;
    long long right = *max_element(times.begin(), times.end()) * static_cast<long long>(n);
    long long mid = 0;

    answer = right;

    while(left <= right)
    {
        long long count = 0;
        mid = (left + right) / 2;
        // 모든 심사관이 mid 시간 내에 심사 가능한 인원수를 계산 
        for(int time : times)
        {
            count += mid / time;
        }
        // 목표보다 많은 인원을 검사할 수 있다면 시간을 줄인다.
        if ( n <= count)
        {
        // 시간을 줄일 경우 더이상 조건을 만족하는 값을 못 찾을 수 있다.
        // 그렇다면 지금의 값이 최소값이 되기 때문에 answer에 현재 시간값을 저장.
            answer = mid;
            right = mid - 1;
        }
        // 목표보다 적은 인원을 검사한다면 시간을 늘린다.
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}