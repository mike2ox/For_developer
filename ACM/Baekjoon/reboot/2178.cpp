// BOJ no. 2178, mike2ox(2020)
// using bfs algorithm
#include<iostream>
#include<queue>
using namespace std;

int n, m;
int cnt=1;
char maze[103][102];
bool visit[101][101];

void bfs() {
	const int dy[] = { 0,0,-1,1 };
	const int dx[] = { 1,-1,0,0 };

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visit[1][1] = true;
	int q_size = q.size();

	while (!q.empty()) {
		if (q_size<1) {
			q_size = q.size();
			cnt++;
		}

		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		--q_size;

		for (int d = 0; d < 4; ++d) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny<1 || nx<1 || ny>n || nx>m)
				continue;
			if (visit[ny][nx]||maze[ny][nx]=='0')
				continue;
			if (ny == n && nx == m) {
				cout << cnt+1 << '\n';
				return;
			}

			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> m;

	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= m; ++x) {
			cin >> maze[y][x];
		}
	}

	bfs();

	return 0;
}