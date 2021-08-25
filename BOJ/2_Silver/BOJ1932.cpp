// 문제 : 정수 삼각형 (Silver 1)
// 출처 : 백준 (https://www.https://www.acmicpc.net/problem/1932)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <algorithm>
#define endl '\n'

using namespace std;

const int MAX = 501;
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n; //1 <= n <= 500
    array<array<int, MAX>, MAX> cache{};

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            int input;
            cin >> input;

            cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - 1]) + input;
        }
    }

    int maxNum = 0;

    for (int i = 1; i <= n; ++i)
    {
        maxNum = max(cache[n][i], maxNum);
    }
    cout << maxNum;

    return 0;
}