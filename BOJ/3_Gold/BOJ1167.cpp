// 문제 : 트리의 지름 (Gold 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/1167)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <vector>
#include <stack>

#define endl '\n'
using namespace std;

struct Edge {
    Edge(struct Node* _next, int _weight) : next(_next), weight(_weight) {}
    Node* next;
    int weight;
};
struct Node {
    vector<Edge> child;
    int depth{ -1 };    // -1인 경우 방문하지 않은 노드
};

Node* DFS(Node* start, int& maxDist)
{
    Node* endNode{};

    stack<Node*> s;
    start->depth = 0;
    s.push(start);

    while (!s.empty())
    {
        Node* cur = s.top();
        s.pop();

        for (Edge edge : cur->child)
        {
            // 방문한적 없는 노드라면, 깊이 갱신 후 stack에 push
            if (edge.next->depth == -1)
            {
                edge.next->depth = cur->depth + edge.weight;
                s.push(edge.next);
                if (maxDist < edge.next->depth)
                {
                    maxDist = edge.next->depth;
                    endNode = edge.next;
                }
            }
        }
    }
    return endNode;
}

int main() {
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    const int MAX = 100'001;
    array<Node, MAX> tree;
    int V; //  (2 ≤ V ≤ 100,000)

    cin >> V;

    for (int i = 1; i <= V; ++i)
    {
        int cur;
        cin >> cur;
        while (1)
        {
            int vertex, weight;
            cin >> vertex;
            if (vertex == -1) break;
            cin >> weight;

            tree[cur].child.push_back(Edge(&tree[vertex], weight));
        }
    }


    int maxDist{};
    Node* endNode{};

    endNode = DFS(&tree[1], maxDist);

    // 깊이정보 초기화 (방문하지 않은 경우: -1)
    for (int i = 1; i <= V; ++i)
    {
        tree[i].depth = -1;
    }

    DFS(endNode, maxDist);

    cout << maxDist;

    return 0;
}