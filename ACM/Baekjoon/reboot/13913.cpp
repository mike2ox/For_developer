// BJO no. 13913, mike2ox(2020)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
int cnt = 0;
int visit[100001];

void go(int startPoint, int endPoint) {
	queue<int> q;
	int q_size = 1;
	q.push(startPoint);
	// visit[startPoint] = -1;

	while (!q.empty()) {
		if (q_size == 0) {
			q_size = q.size();
			cnt++;
		}

		int curPoint = q.front();
		int nextPoint[3] = { curPoint - 1, curPoint + 1, 2 * curPoint };

		q.pop();
		q_size--;
		// visit[curPoint] = true;

		if (curPoint == endPoint) {
			int track = endPoint;
			vector<int> solve;
			cout << cnt << '\n';

			solve.push_back(endPoint);

			while (track != startPoint) {
				solve.push_back(visit[track]);
				track = visit[track];
			}
			for (int i = solve.size()-1; i >= 0; --i)
				cout << solve[i] << ' ';
			cout << '\n';

			return;
		}

		// 0 100000일때 무한루프
		for (int i = 0; i < 3; ++i) {
			// 다음 위치가 숨바꼭질 범위 밖
			if (nextPoint[i] < 0 || nextPoint[i]>100000)
				continue;
			// 이전에 방문한 곳일 경우
			if (visit[nextPoint[i]]!=0)
				continue;
			q.push(nextPoint[i]);
			visit[nextPoint[i]] = curPoint;
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> k;

	go(n, k);

	return 0;
}