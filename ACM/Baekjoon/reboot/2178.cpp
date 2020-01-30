// BOJ no. 2178, mike2ox(2020)
// using DFS algorithm
#include<iostream>
using namespace std;

int n, m;
int cnt=1000000;
char maze[101][101];
bool visit[101][101];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

void dfs(int y, int x, int nowCnt) {
	if (y == n - 1 && x == m - 1) {
		if(cnt > nowCnt)
			cnt = nowCnt;
		return;
	}
	visit[y][x] = true;

	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny<0 || nx<0 || ny>n || nx>m)
			continue;
		if (visit[ny][nx] || maze[ny][nx] != '1')
			continue;

		dfs(ny, nx, nowCnt + 1);
	}
	visit[y][x] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> maze[y][x];
		}
	}

	dfs(0, 0, 1);

	cout << cnt << '\n';
	system("pause");
	return 0;
}