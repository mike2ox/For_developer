/*
*	author : mike2ox
*	BOJ : 토마토
*	descript : https://www.acmicpc.net/problem/7576
*	type : bfs
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, ret;
int map[1001][1001];
queue< pair<int, int>> q;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
void printall() {

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}
int bfs() {
	int cycle = 1;
	int q_s = q.size();

	while (!q.empty()) {
		int ty = q.front().first;
		int tx = q.front().second;

		if (!q_s) {
			//printall();
			cycle++;
			q_s = q.size();
		}

		q.pop();


		for (int i = 0; i < 4; ++i) {
			int ny = ty + dy[i];
			int nx = tx + dx[i];
			// 범위 설정 + 벽
			if (ny < 0 || ny >= m || nx < 0 || nx >= n || map[ny][nx] == -1)
				continue;
			// 
			if (map[ny][nx] == 0) {
				map[ny][nx] = cycle;
				q.push({ ny, nx });
			}
		}

		q_s--;
	}

	return cycle - 1;
}
bool check() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 0)
				return true;
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	ret = bfs();

	if (check())
		cout << -1 << '\n';
	else
		cout << ret << '\n';

	system("pause");
	return 0;
}