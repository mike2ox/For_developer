// BJO no. 1261 mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n, m;
char algo[101][102];
int minimum;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
bool visit[101][102];
void printAll(int y, int x) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == y && j == x)
				cout << "@";
			else
				cout << algo[i][j];
		}
		cout << '\n';
	}
}
void dfs(int y, int x, int cnt) {
	if (y == n && x == m) {
		if (cnt < minimum)
			minimum = cnt;
		return;
	}
	else if (cnt >= minimum)
		return;
	else {
		//printAll(y, x);
		//cout << "++++++++++++++++++++++++++++" << '\n';
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny<1 || nx<1 || ny>n || nx>m)
				continue;
			if (visit[ny][nx])
				continue;

			visit[ny][nx] = true;
			if (algo[ny][nx] == '1')
				dfs(ny, nx, cnt + 1);
			else
				dfs(ny, nx, cnt);
			visit[ny][nx] = false;

		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	minimum = m+n-3;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> algo[i][j];
		}
	}
	//bfs();
	visit[1][1] = true;
	dfs(1, 1, 0);
	visit[1][1] = false;

	cout << minimum << '\n';

	return 0;
}