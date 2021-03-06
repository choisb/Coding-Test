// 문제 : 완주하지 못한 선수 (Level 1)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/42576)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> ht;

    // 참가자의 value를 ++
    for (auto p : participant)
        ht[p]++;

    // 완주자의 value를 --
    for (auto c : completion)
        ht[c]--;

    // value가 1인경우 완주하지 못한사람.
    for (auto h : ht)   
        if (h.second == 1) 
            answer = h.first;

    cout << answer << endl;
    return answer;  
}