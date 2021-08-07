// 문제 : 문자열 집합 (Silver 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/14425)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <unordered_set>
#include <string>
#include <iostream>

// 입출력 성능 향상을 위한 설정
#define endl '\n'

using namespace std;

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; // 집합 S의 문자열 개수
    int M; // 검사할 문자열 개수
    cin >> N >> M;

    int answer{ 0 };
    unordered_set<string> ht;
    while (N--)
    {
        string str;
        cin >> str;
        ht.emplace(str);
    }

    while (M--)
    {
        string str;
        cin >> str;
        if (ht.find(str) != ht.end())
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}