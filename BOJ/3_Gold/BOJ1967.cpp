// 문제 : 트리의 지름 (Gold 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/1967)
// 풀이 : https://dev-sbee.tistory.com/ 참고
#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>

#define endl '\n'
using namespace std;

struct Edge {
    Edge(struct Node* _to, int _weight) : to(_to), weight(_weight) {}
    Node* to{};
    int weight{};
};
struct Node {
    vector<Edge> edges;
    int dist{ -1 };    // 방문하지 않은 노드라면 -1
};

Node* BFS(Node* start, int& maxDist)
{
    if (start == nullptr)
    {
        maxDist = 0;
        return nullptr;
    }
    Node* endNode{};

    queue<Node*> q;
    start->dist = 0;
    q.push(start);

    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        for (Edge edge : cur->edges)
        {
            // 방문하지 않은 노드라면 
            if (edge.to->dist == -1)
            {
                edge.to->dist = cur->dist + edge.weight;
                q.push(edge.to);

                if (maxDist < edge.to->dist)
                {
                    maxDist = edge.to->dist;
                    endNode = edge.to;
                }
            }
        }
    }
    return endNode;
}

int main() {

    int n; // 노드의 개수 n(1 ≤ n ≤ 10,000)
    vector<Node> nodes;

    scanf("%d ", &n);
    nodes.resize(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int s, e, w;
        scanf("%d %d %d ", &s, &e, &w);
        // 인접노드 연결 (무방향)
        nodes[s].edges.emplace_back(&nodes[e], w);
        nodes[e].edges.emplace_back(&nodes[s], w);
    }

    int maxDist{};
    Node* endNode;
    // 1차 BFS
    endNode = BFS(&nodes[1], maxDist);

    for (Node& node : nodes)
    {
        node.dist = -1;
    }

    // 2차 BFS
    int answer{};
    BFS(endNode, answer);
    printf("%d\n", answer);

    return 0;
}