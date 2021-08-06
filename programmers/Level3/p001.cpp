// 문제 : 베스트앨범 (Level 3)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/42579)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // key: 장르 이름 / value: 장르별 재생 횟수
    unordered_map<string, int> ht_i;    
    // key: 장르이름 / value: 장르에 포함된 노래의 map(key: 노래의 재생 횟수, value: 노래 번호)
    unordered_map<string, multimap<int, int, greater<int>>> ht_m;   
    // key: 장르별 재생 횟수 / value: 장르 이름
    map<int, string, greater<int>> mp;

    // 장르별 총 재생 횟수를 ht_i 해시 테이블에 저장
    // 장르별 노래, 노래별 재생횟수를 ht_m 해시 테이블에 저장
    for(int i = 0; i < genres.size(); i++)
    {
        ht_i[genres[i]] += plays[i];
        ht_m[genres[i]].insert({plays[i],i});
    }

    // (장르별 총 재생횟수)를 가진 해시테이블을 재생횟수를 기준으로 정렬하기 위해서 mltimap에 저장
    // multimap<key: 장르별 재생횟수, value: 장르 이름>
    for(auto h : ht_i)
    {
        mp.insert({h.second,h.first});
    }

    // 각 장르별 재생횟수가 가장 많은 요소부터 반복문 실행
    for(auto m : mp)
    {
        // 각 장르의 첫번째 원소(가장 많이 재생된 음악)를 가리키는 반복자 생성
        auto iter = ht_m[m.second].begin();

        // 첫 번째로 많이 재생된 음악을 answer에 저장
        answer.push_back(iter->second);
        // 두 번째 원소로 이동
        iter++;
        // 두 번째 음악이 존재한다면 두 번째 음악도 answer에 저장
        if(iter != ht_m[m.second].end())
            answer.push_back(iter->second);
    }
    return answer;
}