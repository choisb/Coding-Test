// 문제 : 계단 오르기 (Silver 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/2579)
// 풀이 : https://dev-sbee.tistory.com/ 참고
#include <iostream>
#include <algorithm>
#include <array>
#define endl '\n'

using namespace std;
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    const int MAX = 301;

    array<int, MAX> cache{};
    array<int, MAX> num{};
    int N; //N은 300이하의 자연수
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> num[i];
    }

    cache[1] = num[1];
    cache[2] = num[1] + num[2];

    for (int i = 3; i <= N; ++i)
    {
        cache[i] = max( cache[i - 3] + num[i - 1] + num[i], cache[i - 2] + num[i]);
    }

    cout << cache[N];
    return 0;
}

