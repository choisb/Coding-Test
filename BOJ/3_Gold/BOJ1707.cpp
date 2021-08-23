// 문제 : 이분 그래프 (Gold 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/1707)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define endl '\n'
using namespace std;

enum class Color : uint8_t
{
    None,
    Red,
    Blue,

    MAX
};
struct Node {
    Node() : color(Color::None)
    {}

    Color color;
    // 인접노드의 인덱스
    vector<int> adjacent;
};

class Graph {
public:
    Graph() {}

    void InputData();
    bool IsBipartite();
private:

    bool BFS(int start);    // start에서 시작한 노드가 이분그래프라면 true 반환

    static const int MAX_VERTEX = 20'001;

    int V, E;   // 1 <= V <= 20'000 / 1 <= E <= 200'000
    array<Node, MAX_VERTEX> nodes{};
};


void Graph::InputData()
{
    cin >> V >> E;

    // E 개수만큼 간선 연결
    int a, b;

    for (int i = 0; i < E; ++i)
    {
        cin >> a >> b;

        nodes[a].adjacent.push_back(b);
        nodes[b].adjacent.push_back(a);
    }
}

bool Graph::IsBipartite()
{
    for (int i = 1; i <= V; ++i)
    {
        if (nodes[i].color == Color::None)
        {
            if (BFS(i) == false)
                return false;
        }
    }
    return true;
}
bool Graph::BFS(int start)
{
    queue<int> q;
    nodes[start].color = Color::Blue;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : nodes[cur].adjacent)
        {
            if (nodes[cur].color == nodes[next].color)
            {
                return false;
            }

            if (nodes[next].color == Color::None)
            {
                if (nodes[cur].color == Color::Blue)
                    nodes[next].color = Color::Red;
                else
                    nodes[next].color = Color::Blue;

                q.push(next);
            }
        }
    }

    return true;
}
int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int K;  // 테스트 케이스
    cin >> K;
    while (K--)
    {
        Graph graph;
        graph.InputData();
        if (graph.IsBipartite())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}