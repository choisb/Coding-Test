// 문제 : RGB거리 (Silver 1)
// 출처 : 백준 (https://www.acmicpc.net/problem/1149)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <algorithm>

#define endl '\n'
using namespace std;

enum Color : uint8_t
{
    R, G, B, Color_MAX
};

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;  // 집의 수 2 <= N <= 1'000
    cin >> N;

    array<int, Color_MAX> cost{};
    array<int, Color_MAX> cache{};

    for (int i = 1; i <= N; ++i)
    {
        array<int, Color_MAX> Temp{};

        cin >> cost[R] >> cost[G] >> cost[B];

        Temp[R] = min(cache[G], cache[B]) + cost[R];
        Temp[G] = min(cache[R], cache[B]) + cost[G];
        Temp[B] = min(cache[R], cache[G]) + cost[B];

        cache[R] = Temp[R];
        cache[G] = Temp[G];
        cache[B] = Temp[B];
    }

    int answer = min({ cache[R], cache[G], cache[B] });

    cout << answer;

    return 0;
};