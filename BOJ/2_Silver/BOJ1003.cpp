// 문제 : 피보나치 함수 (Silver 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/1003)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
using namespace std;

int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;

    int dp[42] = {};

    dp[0] = 1;
    dp[1] = 0;

    cin >> T;
    for (int i = 2; i < 42; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while (T--)
    {
        int N;
        cin >> N;
        cout << dp[N] << " " << dp[N+1] << endl;
    }

    return 0;
}