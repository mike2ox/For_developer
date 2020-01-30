// BOJ no. 1697, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n, k;
int cnt = 0;
bool visit[100001];

void go(int startPoint, int endPoint) {
	queue<int> q;
	int q_size = 1;
	q.push(startPoint);

	while (!q.empty()) {
		if (q_size == 0) {
			q_size = q.size();
			cnt++;
		}

		int curPoint = q.front();
		int nextPoint[3] = { curPoint - 1, curPoint + 1, 2 * curPoint };

		q.pop();
		q_size--;
		visit[curPoint] = true;

		if (curPoint == endPoint) {
			cout << cnt << '\n';
			return;
		}
		
		for (int i = 0; i < 3; ++i) {
			// 다음 위치가 숨바꼭질 범위 밖
			if (nextPoint[i] <0 || nextPoint[i]>100000)
				continue;
			// 이전에 방문한 곳일 경우
			if (visit[nextPoint[i]])
				continue;
			q.push(nextPoint[i]);
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