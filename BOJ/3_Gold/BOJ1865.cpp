// 문제 : 웜홀 (Gold 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/1865)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int INF = 2'000'000'000;

struct Edge {
    Edge(int _start, int _end, int _time) : start(_start), end(_end), time(_time) {}
    int start;
    int end;
    int time;
};

bool Solve()
{
    vector<Edge> edges;
    vector<int> distances;

    int N; // 지점의 수 N(1 ≤ N ≤ 500)
    int M; // 도로의 개수 M(1 ≤ M ≤ 2500)
    int W; // 웜홀의 개수 W(1 ≤ W ≤ 200)

    cin >> N >> M >> W;

    edges.reserve(M);
    distances.resize(N+1, INF);

    for (int i = 0; i < M; ++i)
    {
        int S, E, T;
        cin >> S >> E >> T;
        edges.emplace_back(S, E, T);
        edges.emplace_back(E, S, T);
    }

    for (int i = 0; i < W; ++i)
    {
        int S, E, T;
        cin >> S >> E >> T;
        edges.emplace_back(E, S, -T);
    }

    // 벨만-포드
    // 시작점
    distances[1] = 0;
    for (int i = 0; i <= N; ++i)
    {
        for (auto edge : edges)
        {
            if (distances[edge.end] > distances[edge.start] + edge.time)
            {
                distances[edge.end] = distances[edge.start] + edge.time;

                // 음의 순환이 존재하는 경우
                if (i == N)
                    return true;
            }
        }
    }
   
    return false;
}
int main() {
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while (TC--)
    {
        if (Solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}