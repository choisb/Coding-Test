// 문제 : 휴대폰 자판 (Platinum 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/5670)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#define endl '\n'

using namespace std;

struct Node {
    Node() : isEnd(false){}

    unordered_map<char, Node*> links;
    bool isEnd;
};
class Trie {
public:
    Trie() : totalInput(0), size(0) { root = new Node(); }
    ~Trie() { DeleteLinks(root); }
    void Insert(const string& word);
    float Solution();  

private:
    void PreorderTraverse(Node* node, char key, int inputCnt);  // 노드 탐색을 위한 재귀함수
    void DeleteLinks(Node* node);   // 전체 노드 삭제를 위한 제귀함수
    Node* root;
    int totalInput; // 자동완성을 위해서 입력해야하는 총 input 수 
    int size;   // 노드의 개수
};
void Trie::Insert(const string& word)
{
    Node* cur = root;
    for (size_t i = 0; i < word.length(); ++i)
    {
        if (cur->links[word[i]] == nullptr)
        {
            cur->links[word[i]] = new Node();
        }
        cur = cur->links[word[i]];
    }
    cur->isEnd = true;
    size++;
}
float Trie::Solution()
{
    totalInput = 0;

    // root 노드의 모든 자식 노드에 대해서 탐색 진행
    for (auto child : root->links)
    {
        PreorderTraverse(child.second, child.first, 1);
    }

    // 계산된 totalInput의 평균을 구하고, 소수 둘째 자리에서 반올림
    float retVal = static_cast<float>(totalInput) / size;
    retVal = round(retVal * 100) / 100;

    return retVal;  
}

void Trie::PreorderTraverse(Node* node, char key, int inputCnt)
{
    // 현재 노드가 끝 노드일 때 다음 노드로 가기 위해서는 입력을 하나 더 받아야 한다.
    // 그리고 지금까지의 inputCnt를 totalInput에 더해야 한다.
    if (node->isEnd) {
        totalInput += inputCnt;

        inputCnt++;
    }
    // 자식 노드가 1개보다 많다면, 새로운 입력을 받아야 한다.
    else if (node->links.size() > 1)
    {
        inputCnt++;
    }
    else 
    {
        // 자식 노드가 한개 && 현재 노드가 isEnd가 아니라면 inputCnt를 증가시키지 않는다.
    }

    // 자식 노드가 있다면 탐색을 더 진행한다.
    for (auto child : node->links)
    {
        PreorderTraverse(child.second, child.first,inputCnt);
    }
}
void Trie::DeleteLinks(Node* node)
{
    for (auto child : node->links)
    {
        if (child.second != nullptr)
        {
            DeleteLinks(child.second);
        }
    }
    delete node;
}

int main()
{
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // 소수 둘째자리 까지 출력을 위한 설정
    cout.precision(2);
    cout << fixed;

    unsigned int N;  // 입력 받을 문자열 개수
    while (cin >> N) 
    {
        Trie trie;

        for(size_t i = 0; i < N; ++i)
        {
            string word;
            cin >> word;
            trie.Insert(word);
        }
        cout << trie.Solution() << endl;
    }

    return 0;
}
