// 문제 : 가장 긴 증가하는 부분 수열 (Silver 2)
// 출처 : 백준 (https://www.acmicpc.net/problem/11053)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <algorithm>
#include <array>
#define endl '\n'
using namespace std;

int N;  //수열 A의 크기 N (1 ≤ N ≤ 1,000)
const int MAX = 1'001;

array<int, MAX> a{};
array<int, MAX> cache{};

int f(int index)
{
    if (cache[index] != 0)
        return cache[index];

    int maxVal = 1;

    for (int next = index + 1; next <= N; ++next)
    {
        if (a[next] > a[index])
        {
            maxVal = max(f(next) + 1, maxVal);
        }
    }

    return cache[index] = maxVal;
}
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
    }

    cache[N] = 1;
    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        answer = max(f(i), answer);
    }

    cout << answer;

    return 0;
}

