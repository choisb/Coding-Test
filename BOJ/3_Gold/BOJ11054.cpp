// 문제 : 가장 긴 바이토닉 부분 수열 (Gold 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/11054)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <algorithm>
#include <array>
#define endl '\n'
using namespace std;

int N;  //수열 A의 크기 N (1 ≤ N ≤ 1,000)
const int MAX = 1'001;

array<int, MAX> a{};
array<array<int, 2>, MAX> cache{};
int f_down(int index)
{
    if (cache[index][1] != 0)
        return cache[index][1];

    int maxVal = 1;

    for (int next = index + 1; next <= N; ++next)
    {
        if (a[next] < a[index])
        {
            maxVal = max(f_down(next) + 1, maxVal);
        }
    }
    return cache[index][1] = maxVal;
}
int f_up(int index)
{
    if (cache[index][0] != 0)
        return cache[index][0];

    int maxVal = 1;

    for (int next = index + 1; next <= N; ++next)
    {
        if (a[next] > a[index])
        {
            maxVal = max(f_up(next) + 1, maxVal);
        }
        else if(a[next] < a[index])
        {
            maxVal = max(f_down(next) + 1, maxVal);
        }
    }

    return cache[index][0] = maxVal;
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

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        answer = max(f_up(i), answer);
    }

    cout << answer;

    return 0;
}

