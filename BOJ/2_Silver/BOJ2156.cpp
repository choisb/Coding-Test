// 문제 : 포도주 시식 (Silver 1)
// 출처 : 백준 (https://www.acmicpc.net/problem/2156)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    unsigned int n;
    cin >> n;
    vector<int> w(n+1);  // n개의 포도주 (1 ~ n개 사용)
    vector<int> d(n+1);  // 계산결과 저장할 배열 (1 ~ n개 사용)

    for (size_t i = 1; i < n+1; ++i)
    {
        cin >> w[i];
    }

    // 초기값 설정
    d[0] = 0;
    d[1] = w[1];
    d[2] = w[1] + w[2];

    for (size_t i = 3; i < n+1; i++)
    {
        const int a = d[i - 1];
        const int b = d[i - 2] + w[i];
        const int c = d[i - 3] + w[i - 1] + w[i];

        d[i] = max(a, max(b,c));
    }

    cout << d[n];

    return 0;
}