// 문제 : 단어 변환 (Level 3)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/43163?language=cpp)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <queue>

using namespace std;

// Node는 문자와 깊이를 가진다.
struct Node{
    Node(const string& str)
    :depth(0)
    ,word(str)
    {
    }

    string word;
    int depth = 0;
};

// 두 개의 문자가 바꿀 수 있는 관계인지 반환 
bool IsExchangeable(const string& left, const string& right)
{
    int diff = 0;
    for(int i = 0; i < left.size(); ++i)
        if(left[i] != right[i])
            diff++;

    return diff == 1;
}

// bfs 실행. 탐색 깊이를 반환
int bfs(const string& begin, const string& target, const vector<Node*>& nodes)
{  
    queue<const Node*> q;
    const Node* curNode;

    // queue에 초기값 삽입(begin 과 바로 인접한 노드들)
    for(auto node : nodes)
    {
        if(IsExchangeable(begin, node->word))
        {
            // 첫 탐색이기 때문에 깊이는 모두 1이다
            node->depth = 1;
            q.emplace(node);
        }
    }

    // 탐색 시작
    // 큐가 비었다는 것은 모든 경우의 수를 다 따져봤지만 변환할 방법이 없다는 뜻.
    while(!q.empty())
    {
        // 큐의 첫번째 노드를 꺼내서 확인한다.
        curNode = q.front();
        q.pop();

        // 목표를 찾았다면 curNode의 깊이를 반환한다.
        if(curNode->word.compare(target) == 0)
            return curNode->depth;

        // 현재 노드에서 변환가능하며 큐에 삽입된적 없는 노드를 모두 큐에 삽입한다.
        for(auto node : nodes)
        {
            if(IsExchangeable(curNode->word, node->word) && node->depth == 0)
            {
                // 새로 큐에 삽입되는 노드의 깊이는 현재 노드의 다음 노드이기 때문에
                // 현재 노드 깊이의 +1 값이다.
                node->depth = curNode->depth + 1;
                q.emplace(node);
            }
        }
    }    
    return 0;
}

int solution(string begin, string target, vector<string> words) 
{     
    int answer = 0;
    vector<Node*> nodes;

    // words를 활용해서 nodes 벡터 생성
    for(auto word : words)
    {
        Node* nNode = new Node(word);
        nodes.emplace_back(nNode);
    }

    // bfs 결과값 반환
    answer = bfs(begin, target, nodes);

    // 동적할당한 node들 삭제
    for(auto node : nodes)
    {
        delete node;
    }

    return answer;
}