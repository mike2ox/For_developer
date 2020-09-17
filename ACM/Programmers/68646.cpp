// 풍선터트리기(50m)
// TLE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	vector<int> ret;
	for (int i = 0; i < a.size(); i++) {
		vector<int> local_min(2, INT_MAX);

		for (int prev = 0; prev < i; prev++) {
			local_min[0] = min(local_min[0], a[prev]);
		}
		for (int next = i + 1; next < a.size(); next++) {
			local_min[1] = min(local_min[1], a[next]);
		}
		if (a[i] > local_min[0] && a[i] > local_min[1])
			continue;
		else
			answer++;
	}

	return answer;
}
