// 문제 : 소수 찾기 (Silver 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/1978)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    int answer = 0;

    cin >> N;

    while (N--)
    {
        int number;
        cin >> number;
        if (number == 1)
        {
            continue;
        }
        if (number == 2)
        {
            answer++;
            continue;
        }

        bool isPrime = true;
        int sqrtNum = static_cast<int>(sqrt(number));
        // 2부터 sqrtNum 까지 모두 나눠서 나머지가 0인 경우가 있으면 소수가 아님.
        for (int i = 2; i <= sqrtNum; i++)
        {
            if (number % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            answer++;
    }

    cout << answer;
    return 0;
}