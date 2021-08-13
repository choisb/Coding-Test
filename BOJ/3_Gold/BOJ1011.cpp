// 문제 : Fly me to the Alpha Centauri (Gold 5)
// 출처 : 백준 (https://www.acmicpc.net/problem/1011)
// 풀이 : https://dev-sbee.tistory.com/ 참고
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    size_t T;  // 입력 받을 문자열 개수
    cin >> T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        const int dist = y - x;

        int sqrtDist = static_cast<int>(sqrt(dist-1));
        if (dist - sqrtDist * sqrtDist <= sqrtDist)
        {
            cout << 2 * sqrtDist << endl;
        }
        else
        {
            cout << 2 * sqrtDist + 1 << endl;
        }
    }

    return 0;
}
