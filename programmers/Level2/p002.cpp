// 문제 : 전화번호 목록 (Level 2)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/42577)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {

    unordered_map<string, int> ht;

    // 해시 테이블에 모든 전화번호를 등록하고 value를 1로 마킹
    for(auto number : phone_book)
        ht[number] = 1;

    for(auto number : phone_book)    // 모든 전화번호에 대해서
        for(int i = 1; i < number.length(); i++) //  모든 경우의 수에 대해서 (자기자신 제외)
            if(ht.find(number.substr(0,i)) != ht.end())    // 중복된 번호가 있다면 false
                return false;

    return true;
}