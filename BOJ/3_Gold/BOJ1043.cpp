// 문제 : 거짓말 (Gold 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/1043)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX = 51;
struct Node {
    bool fact{};
    vector<int> partyID{};
};


int main() {
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    array<Node, MAX> person;
    array<array<int, MAX>, MAX> party; //party[파티 ID][파티 참석자]
    queue<int> q;

    int N, M; // N(사람 수), M(파티 수)은 50 이하의 자연수
    cin >> N >> M;

    int num;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        int input;
        cin >> input;
        person[input].fact = true;
        q.push(input);
    }

    for (int i = 0; i < M; ++i)
    {
        // i 번 파티 참석자 수
        cin >> party[i][0];
        for (int j = 1; j <= party[i][0]; ++j)
        {
            // i번 파티 참석자 정보
            cin >> party[i][j];
            person[party[i][j]].partyID.push_back(i);
        }
    }

    // BFS
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int ID : person[cur].partyID)
        {
            for (int i = 1; i <= party[ID][0]; ++i)
            {
                int index = party[ID][i];
                if (person[index].fact == false)
                {
                    person[index].fact = true;
                    q.push(index);
                }
            }
        }
    }

    int answer{};
    for (int i = 0; i < M; ++i)
    {
        // 파티 참석자는 최소 1명 이상
        int index = party[i][1];
        if (person[index].fact == false)
            answer++;
    }
    cout << answer;

    return 0;
}