// 문제 : 다리를 지나는 트럭 (Level 2)
// 출처 : 프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/42583)
// 풀이 : https://dev-sbee.tistory.com/ 참고

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, total_weight = 0, time = 0, index = 0;

    queue<int> q;

    // 큐를 다리의 크기 만큼 0으로 채운다
    for(int i = 0; i < bridge_length; i++)
    {
        q.push(0);
    }

    // 마지막 트럭이 다리에 올라갈때 까지 시뮬레이션 반복
    while( index < truck_weights.size()) 
    {
        time++;

        // 다리를 지난 요소를 큐에서 제거
        total_weight -= q.front();
        q.pop();    

        // 다리에 트럭이 더 올라 갈 수 있다면 트럭을 push
        if(weight - total_weight >= truck_weights[index])
        {
            // next에 트럭의 무게 입력, 트럭 인덱스(index)++
            q.push(truck_weights[index]);
            total_weight += truck_weights[index];
            index++;
        }
        // 다리에 트럭이 더 올라 갈 수 없다면 0을 push
        else
        {
            q.push(0);
        }
    }

    // 마지막 트럭이 지나는데 필요한 시간을 더해준다.
    time += bridge_length;

    return time;
}