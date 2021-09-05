// 문제 : 최단 경로 (Gold 5)
// 출처 : 백준 (https://www.acmicpc.net/problem/1753)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX_VTX = 20'001;
const int INF = MAX_VTX * 10;

struct Edge {
    Edge(struct Node* _target, int _weight) : target(_target), weight(_weight) {}
    Node* target;
    int weight;
};
struct Node {
    vector<Edge> adjacent;
    int dist{ INF };
};

struct Compare {
    bool operator()(Node* lhs, Node* rhs)
    {
        return lhs->dist > rhs->dist;
    }
};
int main() {
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    int V, E, start; // (1≤V≤20,000, 1≤E≤300,000) 

    array<Node, MAX_VTX> graph;

    cin >> V >> E >> start;

    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].adjacent.emplace_back(&graph[v], w);
    }

    // 다익스트라
    priority_queue<Node*, vector<Node*>, Compare> pq;
    graph[start].dist = 0;

    pq.push(&graph[start]);
    while (!pq.empty())
    {
        Node* cur = pq.top();
        pq.pop();

        for (Edge edge : cur->adjacent)
        {
            if (edge.target->dist > cur->dist + edge.weight)
            {
                edge.target->dist = cur->dist + edge.weight;
                pq.push(edge.target);
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (graph[i].dist == INF)
            cout << "INF" << endl;
        else
            cout << graph[i].dist << endl;
    }
    
    return 0;
}