// 문제 : 쉬운 계단 수 (Silver 1)
// 출처 : 백준 (https://www.acmicpc.net/problem/10844)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#define endl '\n'

using namespace std;
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    const int MAX = 101;

    array<array<int, 10>, MAX> cache{};
    int N; //N은 1보다 크거나 같고, 100보다 작거나 같은 자연수
    cin >> N;

    cache[1].fill(1);
    cache[1][0] = 0;

    for (int i = 2; i <= N; ++i)
    {
        cache[i][0] = cache[i - 1][1] % 1'000'000'000;
        for (int j = 1; j < 9; j++)
        {
            cache[i][j] = cache[i - 1][j-1] + cache[i - 1][j+1];
            cache[i][j] = cache[i][j] % 1'000'000'000;
        }
        cache[i][9] = cache[i - 1][8] % 1'000'000'000;
    }

    int sum = 0;
    for (int i = 0; i <= 9; ++i)
    {
        sum += cache[N][i];
        sum %= 1'000'000'000;
    }
    cout << sum;
    return 0;
}

