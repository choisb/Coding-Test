// 문제 : 자동완성 (Level 4)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/17685)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <array>
using namespace std;

struct Node {
    Node() : links{}, referenceCount(0)
    {}
    array<Node*, 26> links;
    int referenceCount;
    static::size_t GetIndex(char ch) { return static_cast<size_t>(ch - 'a'); }
};

class Trie {
public:
    Trie();
    ~Trie();
    void Insert(const string& word);       // 트라이에 문자열 추가 함수 
    int AutoComplate(const string& word);  // 해당 문자열을 찾기위해 필요한 입력 수를 반환
private:
    Node* root;        // 루트 노드
    void recurDelete(Node* node);    // ~Trie()에서 사용할 재귀함수.
};

Trie::Trie() {
    root = new Node();
}
Trie::~Trie() {
    recurDelete(root);
}
void Trie::Insert(const string& word)
{
    Node* cur {root};
    for(size_t i {0}; i < word.length(); ++i)
    {
        // i번째 문자를 저장할 노드(nextNode) 인덱스 계산       
        size_t idx = Node::GetIndex(word[i]);
        if(cur->links[idx] == nullptr)
        {
            cur->links[idx] = new Node();
        }
        Node* nextNode {cur->links[idx]};

        // nextNode의 참조를 1 증가 시킨다.
        nextNode->referenceCount++;
        cur = nextNode;
    }
}
int Trie::AutoComplate(const string& word)
{
    Node* cur {root};
    int depth {0};
    for(size_t i {0}; i < word.length(); ++i)
    {
        // 참조가 1인 노드는 문자열을 완성 할 수 있다.
        if(cur->referenceCount == 1)
            break;

        size_t idx = Node::GetIndex(word[i]);
        Node* nextNode {cur->links[idx]};
        cur = nextNode;
        depth++;
    }
    return depth;
}
void Trie::recurDelete(Node* node)
{
    for (Node* node : node->links)
    {
        if (node != nullptr)
        {
            recurDelete(node);
        }
    }
    delete node;
}

int solution(vector<string> words) {
    int answer = 0;
    Trie trie;
    for (const string& word : words)
    {
        trie.Insert(word);
    }

    for (const string& word : words)
    {
        answer += trie.AutoComplate(word);
    }
    return answer;
}