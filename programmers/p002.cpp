// 문제 : 전화번호 목록 (Level 2)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/42577)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <array>

using namespace std;
struct Node{
    Node() : isEnd (false), links{} 
    {}
    
    bool isEnd;
    array<Node*, 10> links;
    static size_t GetIndex(char ch) {return ch - '0';}
};

class Trie{
public:
    Trie() { root = new Node(); }
    ~Trie() { DeleteAll(root); }
    bool Insert (const string& str );	// 삽입 과정에서 유효한 번호인지 판단
    
private:
    Node* root;
    void DeleteAll(Node* node);	// 모든 노드를 삭제하기 위한 함수. 재귀적으로 구현
};
bool Trie::Insert(const string& str)
{
    Node* cur = root;
    // 반복문 시간 복잡도 (O(1))
    for(size_t i = 0; i < str.length(); ++i)
    {
    	// 그림 2의 경우 (새 노드를 추가해야하는데 해당 노드가 잎 노드인 경우)
        if(cur->isEnd == true)
            return false;
        
        size_t index = Node::GetIndex(str[i]);
        if(cur->links[index] == nullptr)
        {
            cur->links[index] = new Node();
        }
        cur = cur->links[index];
    }
    cur->isEnd = true;
    
    // 그림 2의 경우 (자식 노드가 존재하는지 확인)
    for(Node* child : cur->links)
    {
        if(child != nullptr)
            return false;
    }
    
    return true;
}

void Trie::DeleteAll(Node* node)
{
    for(Node* child : node->links)
    {
        if(child != nullptr)
            DeleteAll(child);
    }
    
    delete node;
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Trie trie;
    
    for(const string& number : phone_book )
    {
        // 유효하지 않은 전화번호가 삽입되면 false를 반환하고 종료.
        if(trie.Insert(number) == false)
            return false;
    }
    // 모든 전화번호가 정상적으로 삽입되었다면 유효한 phone_book 이다.
    
    // tire의 소멸자가 자동으로 호출되면서 동적으로 할당된 노드가 삭제됨.
    return true;
}