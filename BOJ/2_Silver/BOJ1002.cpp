// 문제 : 터렛 (Silver 4)
// 출처 : 백준 (https://www.acmicpc.net/problem/1002)
// 풀이 : https://dev-sbee.tistory.com/ 참고
#include <iostream>
#include <cmath>
using namespace std;

struct Circle {
    Circle() : x(0), y(0), r(0) {}
    int x, y, r;
};

int main() {
    // 입출력 성능향상을 위한 설정 
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;

    Circle a, b;

    cin >> T;

    while (T--)
    {
        int answer = 0;

        cin >> a.x >> a.y >> a.r;
        cin >> b.x >> b.y >> b.r;

        int sqrDistance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        int sqrSumOfRadius = (a.r + b.r) * (a.r + b.r);

        if (sqrDistance == 0)  // 두 원의 중심이 같은 경우
        {
            if (a.r == b.r) // 반지름이 같으면 무한
                answer = -1;
            else            // 반지름이 다르면 교점 x
                answer = 0;
        }

        // 중심의 거리가 반지름의 합보다 크다면 안만남  
        else if (sqrDistance > sqrSumOfRadius)
            answer = 0;

        // 중심간의 거리와 반지름의 합이 같다면 한 점에서만 만남.
        else if (sqrDistance == sqrSumOfRadius)
            answer = 1;

        // 중심간의 거리가 반지름의 합보다 작다면 여러 경우가 있음.
        else if(sqrDistance < sqrSumOfRadius)
        {
            // 중심간의 거리가 두 반지름의 차 보다 크다면
            if (sqrDistance > (a.r - b.r) * (a.r - b.r))
                answer = 2;

            // 중심간의 거리가 두 반지름의 차와 같다면
            else if (sqrDistance == (a.r - b.r) * (a.r - b.r))
                answer = 1;

            // 중심간의 거리가 두 반지름의 차보다 작다면
            else if(sqrDistance < (a.r - b.r) * (a.r - b.r))
                answer = 0;
        }

        cout << answer << endl;       
    }
    return 0;
}