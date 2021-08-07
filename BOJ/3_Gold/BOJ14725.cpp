// 문제 : 개미굴 (Gold 2)
// 출처 : 백준 (https://www.acmicpc.net/problem/14725)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
struct Node {
    Node() {}
    map<string, Node*> links;
};
class Trie {
public:
    Trie() { root = new Node(); };	// root 노드를 생성을 잊지 말자.
    ~Trie() { PostorderTraverse(root); };
    void Insert(const vector<string>& words); // 하나의 로봇 개미의 신호를 매개변수로 받아 Trie를 만든다. 
    void PrintAll();	// 문제 조건에 맞게 전위 순회를 활용한 출력함수

private:
    Node* root;
    // 출력을 위한 전위 순회
    void PreorderTraverse(const string& word, Node* node, int depth);  
    // delete를 위한 후위 순회
    void PostorderTraverse(Node* node); 
};
void Trie::Insert(const vector<string>& words)
{
    Node* cur{ root };
    // 반복문 시간 복잡도: O(K * t * log N)
    for (size_t i = 0; i < words.size(); ++i)
    {
        if (cur->links.find(words[i]) == cur->links.end())
        {
            // Insert 시간 복잡도: O(t * log N)
            cur->links[words[i]] = new Node();
        }
        cur = cur->links[words[i]];   
    }
}
void Trie::PrintAll()
{
    // 반복문 시간 복잡도 O (K^2 * N)
    for (auto link : root->links)
    {
        PreorderTraverse(link.first, link.second, 0);
    }
}
void Trie::PreorderTraverse(const string& word, Node* node, int depth)
{
	// 반복문 시간 복잡도 O ( K )
    for (int i = 0; i < depth; i++)
    {
        cout << "--";
    }
    cout << word << endl;

    for (auto link : node->links)
    {
        PreorderTraverse(link.first, link.second, depth + 1);
    }
}
void Trie::PostorderTraverse(Node* node)
{
    for (auto link : node->links)
    {
        PostorderTraverse(link.second);
    }
    delete node;
}

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; // 먹이 정보 개수 (1 <= N <= 1,000)
    int K; // 로봇 개미 한 마리가 보내준 최대 먹이 정보의 개수 (트리의 깊이) (1<= K <= 15)

    vector<string> words;
    words.reserve(15);
    Trie trie;
    cin >> N;
    // 전체 데이터 입력 시간 복잡도
    // O(K * t * N * log N)
    for (int i = 0; i < N; ++i)
    {
        cin >> K;
        for (int j = 0; j < K; ++j)
        {
            string word;
            cin >> word;
            words.emplace_back(word);
        }
        // Insert의 시간 복잡도 (O(K * t * log N))
        trie.Insert(words);
        words.clear();
    }

    trie.PrintAll();

    return 0;
}
