// 문제 : 나이트의 이동 (Silver 2)
// 출처 : 백준 (https://www.acmicpc.net/problem/7562)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <queue>

#define endl '\n'
using namespace std;

struct Move {
    Move(int _x, int _y, int _depth)
        : x(_x)
        , y(_y)
        , depth(_depth)
    {}
    int x;  // 다음 위치의 x 좌표
    int y;  // 다음 위치의 y 좌표
    int depth;   // 다음 이동의 깊이(이동 횟수)
};

class Knight {
public:
    Knight() {}

    void InputData();   // 데이터 입력 및 visited 배열 초기화
    int Search();       // BFS 탐색
private:
    static const int MAX = 304;

    array<array<bool, MAX>, MAX> visited {};
    int l;  // 체스판의 크기
    int cx, cy, tx, ty; // 현재 위치, 목표의 위치
    array<int, 8> dx{ -2, -1,  1,  2,  2,  1, -1, -2 };
    array<int, 8> dy{  1,  2,  2,  1, -1, -2, -2, -1 };
};

void Knight::InputData()
{
    cin >> l;   // 체스판의 크기
    cin >> cx >> cy >> tx >> ty;    // 현재 체스말의 위치

    l += 4;
    cx += 2;
    cy += 2;
    tx += 2;
    ty += 2;

    // 체스판 밖에 해당하는 위치의 방문 기록을 true로 설정
    for (int i = 0; i < l; i++)
    {
        visited[i][0] = true;
        visited[i][1] = true;
        visited[i][l - 1] = true;
        visited[i][l - 2] = true;

        visited[0][i] = true;
        visited[1][i] = true;
        visited[l - 1][i] = true;
        visited[l - 2][i] = true;
    }
}

int Knight::Search()
{
    if (cx == tx && cy == ty)
        return 0;

    queue<Move> q;
    // (1,1) 에서 시작 
    q.emplace(cx, cy, 0);
    visited[cx][cy] = true;
    while (!q.empty())
    {
        Move cur = q.front();
        q.pop();
        // 인접노드 검사
        for (size_t i = 0; i < dx.size(); ++i)
        {
            Move next(cur.x + dx[i], cur.y + dy[i], cur.depth + 1);

            // 이미 방문한 노드이거나, 범위를 벗어나는 노드
            if (visited[next.x][next.y] == true) continue;


            //  목표 도착
            if (next.x == tx && next.y == ty)
            {
                int retVal = next.depth;

                return retVal;
            }
            // 방문하지 않은 위치라면, 방문 체크 후 해당 위치 큐에 삽입.
            else
            {
                visited[next.x][next.y] = true;

                q.emplace(next.x, next.y, next.depth);
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

    int T;  // 테스트 케이스
    cin >> T;

    while(T--)
    {
        Knight knight;    // Knight 클래스 생성

        knight.InputData();   // 데이터 입력
        cout << knight.Search() << endl;  // 최단거리 탐색 및 결과 출력
    }

    return 0;
}