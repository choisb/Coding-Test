// 문제 : 01타일 (Silver 3)
// 출처 : 백준 (https://www.https://www.acmicpc.net/problem/1904)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
using namespace std;

int main()
{
    int N; // 지원이가 만들 수 있는 길이 (1 <= N <= 1'000'000)
    cin >> N;

    int a = 1, b = 1, c = 1;

    for (int i = 2; i <= N; ++i)
    {
        c = a + b;
        c = c % 15746;

        a = b;
        b = c;
    }

    cout << c;

    return 0;
}