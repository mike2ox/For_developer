// BJO no.2206 벽 부수고 이동하기 , mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

char maze[1001][1002];
bool visit[1001][1002];

int n, m;
int depth= 123456789;
struct coord {
	int y,  x;
	int cnt;
};

void bfs() {
	const int dy[] = { 0,0,1,-1 };
	const int dx[] = { 1,-1,0,0 };
	
	int qSize = 1; int tmpDepth = 1;

	queue<coord> q;
	q.push({ 1,1,0 });
	visit[1][1] = true;

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
			tmpDepth++;
		}
		coord now = q.front();
		q.pop();
		qSize--;

		for (int i = 0; i < 4; ++i) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int nCnt = now.cnt;
			if (ny < 1 || nx < 1 || ny > n || nx > m || visit[ny][nx])
				continue;
			if (maze[ny][nx] == '1') {
				if (now.cnt == 0) {
					q.push({ ny, nx, nCnt+1 });
					visit[ny][nx] = true;
				}
				continue;
			}
			if(ny==n&&nx==m){
				tmpDepth+1 < depth ? depth = tmpDepth + 1 : false;
				return;
			}

			q.push({ ny, nx, nCnt });
			visit[ny][nx] = true;
		}
	}
}
void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			visit[i][j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> maze[i][j];
		}
	}

	bfs();
	init();

	if (depth < 123456789)
		cout << depth << '\n';
	else
		cout << -1 << '\n';
	return 0;
}