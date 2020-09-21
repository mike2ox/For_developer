// 다리를 지나는 트럭(30m)
// queue 사용법 숙지 확인
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

struct truck {
	int enter_time;
	int weight;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	queue<truck> bridge_info;

	// 제일 앞의 트럭을 뽑아 내기 위해 반전
	reverse(truck_weights.begin(), truck_weights.end());
	bridge_info.push({ 1, truck_weights.back() });
	weight -= truck_weights.back();
	truck_weights.pop_back();

	if (weight < 0)
		return -1;

	// 다리에 트럭이 없을 때까지
	while (!bridge_info.empty()) {
		answer++;
		// 제일 앞 트럭이 다리를 통과 할 경우
		if (answer - bridge_info.front().enter_time == bridge_length) {
			weight += bridge_info.front().weight;
			bridge_info.pop();
		}
		// 다리를 건널 수 있는 경우
		if (!truck_weights.empty() && weight - truck_weights.back() >= 0) {
			bridge_info.push({ answer, truck_weights.back() });
			weight -= truck_weights.back();
			truck_weights.pop_back();
		}
	}

	return answer;
}
