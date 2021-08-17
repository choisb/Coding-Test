// 문제 : 파도반 수열 (Silver 3)
// 출처 : 백준 (https://www.acmicpc.net/problem/9461)
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

    int T; // 테스트 케이스
    cin >> T;

    const int Max_N = 101; // N의 최댓값
    array<long long, Max_N> cache{0,1,1,};

    for (int i = 3; i < Max_N; ++i)
    {
        cache[i] = cache[i - 3] + cache[i - 2];
    }

    while (T--)
    {
        int N;
        cin >> N;
        cout << cache[N] << endl;
    }

    return 0;
}
