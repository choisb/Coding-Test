// 문제 : 미로 탐색 (Silver 1)
// 출처 : 백준 (https://www.acmicpc.net/problem/2178)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <string>
#include <queue>

#define endl '\n'

using namespace std;

struct Node {
    Node() : depth(0), isVisited(false), isTarget(false), adjacent{} {}
    int depth;
    bool isVisited;
    bool isTarget;
    array<Node*, 4> adjacent;
};

using NodeMap = array<array < Node*, 100>, 100>;

class Maze {
public:
    Maze(int _N, int _M) : N(_N), M(_M), map{}
    {}
    ~Maze();
    
    void InputData();
    void ConnectAdjacent();
    int Search();
private:
    NodeMap map;
    int N, M;
};

int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    Maze maze(N,M);

    maze.InputData();   // 데이터 입력
    maze.ConnectAdjacent(); // 인접노드 설정
    cout << maze.Search();  // BFS로 이동거리 탐색

    // ~Maze() 호출 동적할당한 노드 삭제
    return 0;
}

Maze::~Maze()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == nullptr) continue;
            delete map[i][j];
        }
    }
}
void Maze::InputData()
{
    for (int i = 0; i < N; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j)
        {
            if (row[j] == '1')
                map[i][j] = new Node();
        }
    }
    map[N - 1][M - 1]->isTarget = true;
}
void Maze::ConnectAdjacent()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == nullptr) continue;

            if (i > 0)
            {
                if (map[i - 1][j])
                    map[i][j]->adjacent[0] = map[i - 1][j];
            }
            if (i < N - 1)
            {
                if (map[i + 1][j])
                    map[i][j]->adjacent[1] = map[i + 1][j];
            }
            if (j > 0)
            {
                if (map[i][j - 1])
                    map[i][j]->adjacent[2] = map[i][j - 1];
            }
            if (j < M - 1)
            {
                if (map[i][j + 1])
                    map[i][j]->adjacent[3] = map[i][j + 1];
            }
        }
    }
}
int Maze::Search()
{
    queue<Node*> q;
    map[0][0]->isVisited = true;
    map[0][0]->depth = 1;
    q.push(map[0][0]);

    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        for (Node* nextNode : cur->adjacent)
        {
            if (nextNode == nullptr) continue;
            if (nextNode->isVisited) continue;
            nextNode->depth = cur->depth + 1;
            nextNode->isVisited = true;

            // 목표에 도달했을 때 깊이값 반환
            if (nextNode->isTarget)
            {
                return nextNode->depth;
            }

            q.push(nextNode);
        }
    }
    // 탐색에 실패한 경우
    return -1;
}
