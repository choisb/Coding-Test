// 문제 : 곱셈 (Silver 1)
// 출처 : 백준 (https://www.acmicpc.net/problem/1629)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <iostream>

#define endl '\n'
using namespace std;

int main() {
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // 첫째 줄에 a를 B번 곱한 수를 n로 나눈 나머지를 출력한다.
    long long a, B, n; // a, B, n는 모두 2,147,483,647 이하의 자연수

    cin >> a >> B >> n;

    int b[32]{};
    // 이진수 배열로 변환
    long long temp = B, k = 31;
    for (int i = 0; i < 32; ++i)
    {
        b[i] = temp % 2;
        temp >>= 1;

        if (temp == 0)
        {
            k = i;
            break;
        }
    }

    long long c = 0, f = 1;

    for (int i = k; i >= 0; --i)
    {
        c *= 2;
        f = (f * f) % n;

        if (b[i] == 1)
        {
            c += 1;
            f = (f * a) % n;
        }
    }
    cout << f << endl;

    return 0;
}