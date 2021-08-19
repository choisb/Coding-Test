// 문제 : 토마토 (Silver 1)
// 출처 : 백준 (https://www.acmicpc.net/problem/7576)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <queue>
#define endl '\n'
using namespace std;

struct Node {
    Node(int mNum)
        : mAdjacent{}, mNum(mNum)   // 모든 노드는 노드에 할당된 번호를 0으로 초기화.
    {
    }
    array<Node*, 4> mAdjacent;    // 인접 노드에 대한 정보, 상하좌우 4방향
    int mNum;                   // 토마토 깊이 정보 (1 이상: 익은 토마토, 0: 익지 않은 토마토)
};
// 박스를 표현하기 위한 맵
using NodeMap = array<array<Node*,1'000>,1'000>;

class Tomato {
public:
    Tomato(int _M, int _N) : M(_M), N(_N), map{}, numTomato(0)
    {}
    ~Tomato();
    void InputData();
    void ConnectAdjacent();
    int BFS();

private:
    NodeMap map;
    queue<Node*> q;
    int M, N;
    int numTomato;
};
void Tomato::InputData()
{
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            int num;
            cin >> num;
            if (num == -1) continue;
            map[n][m] = new Node(num);
            if (num == 1)
                q.push(map[n][m]);
            numTomato++;
        }
    }
}
void Tomato::ConnectAdjacent()
{
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            if (map[n][m] == nullptr) continue;

            if (n > 0)
            {
                map[n][m]->mAdjacent[0] = map[n - 1][m];
            }
            if (n < N - 1)
            {
                map[n][m]->mAdjacent[1] = map[n + 1][m];
            }

            if (m > 0)
            {
                map[n][m]->mAdjacent[2] = map[n][m - 1];
            }
            if (m < M - 1)
            {
                map[n][m]->mAdjacent[3] = map[n][m + 1];
            }
        }
    }
}
int Tomato::BFS()
{
    int answer = 0;

    // 큐가 빌때까지 탐색 시작
    Node* cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        numTomato--;

        for (auto neighbor : cur->mAdjacent)
        {
            if (neighbor == nullptr) continue;
            if (neighbor->mNum == 0)
            {
                neighbor->mNum = cur->mNum + 1;
                q.push(neighbor);

                answer = neighbor->mNum - 1;
            }
        }
    }
    // 탐색 종료후에 토마토가 남았다면 -1 반환
    if (numTomato > 0)
        answer = -1;
    return answer;
}
Tomato::~Tomato()
{
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            if (map[n][m] == nullptr) continue;
            // 동적할당한 노드 삭제
            delete map[n][m];
        }
    }
}

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // M: 가로 (2 ~ 1000)
    // N: 세로 (2 ~ 1000)
    int M, N;

    cin >> M >> N;

    Tomato tomato(M, N);
    tomato.InputData();
    tomato.ConnectAdjacent();

    int answer;
    answer = tomato.BFS();

    cout << answer;

    return 0;
}