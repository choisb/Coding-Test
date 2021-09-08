// 문제 : 가장 긴 증가하는 부분 수열 (Silver 2)
// 출처 : 백준 (https://www.acmicpc.net/problem/11053)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <array>
#include <algorithm>

#define endl '\n'
using namespace std;

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    array<int, 1'001> cache{};
    array<int, 1'001> arr{};
    array<int, 1'001> list{};

    int N; //N (1 ≤ N ≤ 1,000)
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    int len{}; // list의 길이 
    for (int i = 1; i <= N; ++i)
    {
        auto lowerPos = lower_bound(list.begin(), list.begin() + len, arr[i]);

        if (*lowerPos == 0)
            len++;

        *lowerPos = arr[i];
    }

    cout << len;
    return 0;
}