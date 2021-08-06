// 문제 : 위장 (Level 2)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/42578)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 해시 테이블 생성 (key: 옷 종류, value: 수량)
    unordered_map<string, int> ht;

    // 동일 한 옷 종류가 들어올 때 마다 ++ 
    for(auto c : clothes){
        ht[c[1]]++;
    }

    // 하나의 옷 종류의 수량 + 1을 누적 곱셈
    for(auto h : ht){
        answer *= (h.second + 1);
    }

    // 아무것도 안입는 경우를 -1
    return answer - 1;
}