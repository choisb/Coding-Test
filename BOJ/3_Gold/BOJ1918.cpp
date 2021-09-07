// 문제 : 후위 표기식 (Gold 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/1918)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <stdio.h>
#include <stack>

#define endl '\n'
using namespace std;

int priority(char ch)
{
    if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else if (ch == '(') return 0;

}

int main() {

    stack<char>s;

    char ch;

    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case '(':
            s.push(ch);
            break;

        case ')':
            while (s.top() != '(')
            {
                printf("%c", s.top());
                s.pop();              
            }
            s.pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!s.empty() && priority(s.top()) >= priority(ch))
            {
                printf("%c", s.top());
                s.pop();
            }
            s.push(ch);
            break;

        default:
            printf("%c", ch);
            break;
        }
    }
    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }

    return 0;
}