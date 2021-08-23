// 문제 : 벽 부수고 이동하기 (Gold 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/2206)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <queue>
#include <string>

#define endl '\n'
using namespace std;


struct Node {
    Node(int _x, int _y, int key, int _depth)
        : x(_x)
        , y(_y)
        , key(key)
        , depth(_depth)
    {}
    int x;
    int y;
    int key;
    int depth;
};

class Maze {
public:
    Maze(int _N, int _M) : N(_N), M(_M)
    {}

    void InputData();
    int Search();
private:
    static const int MAX = 1'002;

    array<array <int, MAX>, MAX> map{};
    array<array<array<bool, 2>, MAX>, MAX> visited{};
    int N, M;
    array<int, 4> dx{ 1,-1,0,0 };
    array<int, 4> dy{ 0,0,1,-1 };
};

void Maze::InputData()
{
    for (int i = 1; i < N + 1; ++i)
    {
        string str;
        cin >> str;
        for (int j = 1; j < M + 1; ++j)
        {
            // 각 위치에 노드 생성, 벽(true) or 길(false) 로 초기화
            map[i][j] = str[j - 1] - '0';
        }
    }
    for (int i = 0; i < N + 2; i++)
    {
        visited[i][0][0] = true;
        visited[i][0][1] = true;
        visited[i][M + 1][0] = true;
        visited[i][M + 1][1] = true;
    }
    for (int i = 0; i < M + 2; i++)
    {
        visited[0][i][0] = true;
        visited[0][i][1] = true;
        visited[N + 1][i][0] = true;
        visited[N + 1][i][1] = true;
    }
}

int Maze::Search()
{
    if (N == 1 && M == 1)
        return 1;

    queue<Node> q;
    // (1,1) 에 key 1개를 가지고 시작. 
    q.emplace(1, 1, 1, 1);
    visited[1][1][1] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        // 인접노드 검사
        for (int i = 0; i < 4; ++i)
        {
            Node next(cur.x + dx[i], cur.y + dy[i], cur.key, cur.depth + 1);

            //  목표 도착
            if (next.x == N && next.y == M)
            {
                int retVal = next.depth;

                return retVal;
            }

            // 다음 위치가 벽이고 방문한적이 없다면
            if (map[next.x][next.y] == 1 && visited[next.x][next.y][0] == false && next.key == 1)
            {
                visited[next.x][next.y][0] = true;
                next.key--;

                q.emplace(next.x, next.y, next.key, next.depth);
            }
            // 다음 위치가 벽이 아니고, 방문한 적이 없다면
            else if (map[next.x][next.y] == 0 && visited[next.x][next.y][next.key] == false)
            {
                visited[next.x][next.y][next.key] = true;

                q.emplace(next.x, next.y, next.key, next.depth);
            }
        }
    }

    // 탐색에 실패한 경우
    return -1;
}

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    Maze maze(N, M);    // Maze 클래스 생성
    maze.InputData();   // 데이터 입력
    cout << maze.Search();  // 최단거리 탐색 및 결과 출력

    return 0;
}