// 문제 : 숨바꼭질 (Silver 1)
// 출처 : 백준 (https://www.https://www.acmicpc.net/problem/1697)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <queue>
#include <memory>

#define endl '\n'
using namespace std;

const int MAX = 100'001;
struct Node {
    Node(int _pos) : pos(_pos), depth(0), nextPos{}
    {
        // 이동할 수 없는 위치는 -1
        nextPos.fill(-1);

        // 이동할 수 있는 위치는 해당 위치의 좌표
        if (pos - 1 >= 0)
            nextPos[0] = pos - 1;
        if (pos + 1< MAX)
            nextPos[1] = pos + 1;
        if (pos * 2 < MAX)
            nextPos[2] = pos * 2;
    }

    int pos;
    int depth;
    array<int, 3> nextPos;
};
int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, K;
    array<shared_ptr<Node>, MAX> nodes{};
    cin >> N >> K;

    // 위치가 같은 경우
    if (N == K) 
    {
        cout << 0;
        return 0;
    }
    queue<shared_ptr<Node>> q;

    nodes[N] = make_shared<Node>(N);
    q.push(nodes[N]);

    // BFS
    while (!q.empty())
    {
        shared_ptr<Node> cur;
        cur = q.front();
        q.pop();

        // 다음노드 탐색
        for(int next : cur->nextPos)
        {
            if (next == K)
            {
                cout << cur->depth + 1;
                return 0;
            }

            // 이동 할 수 없는 경우
            if (next == -1) continue;
            // 방문한 적이 있는 경우
            if (nodes[next] != nullptr) continue;

            nodes[next] = make_shared<Node>(next);
            nodes[next]->depth = cur->depth + 1;
            q.push(nodes[next]);
        }
    }

    return 0;
}