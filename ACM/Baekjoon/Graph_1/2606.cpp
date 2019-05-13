/*
*	author : mike2ox
*	BOJ : 2606
*	descript : https://www.acmicpc.net/problem/2606
*	type :bfs
*/
#include<iostream>
#include<queue>
using namespace std;
int n, m;
int map[101][101];
struct edge {
	int first, second;
};
int bfs() {
	queue<int> q;
	bool visit[101] = { false ,};
	int ret = 0;
	visit[1] = true;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= n; ++i) {
			if (map[cur][i] == 0) continue;
			if (visit[i]) continue;
			q.push(i);
			visit[i] = true;
			ret++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int f, s;
		cin >> f >> s;
		map[f][s] = map[s][f] = 1;
	}

	int ret = bfs();

	cout << ret << '\n';
	return 0;
}
/* 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력
*/