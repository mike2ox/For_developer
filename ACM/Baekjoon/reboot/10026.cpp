// BJO no.10026 적록색약 , mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n;
char colors[100][101];
bool visit[100][100];
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
struct xy {
	int i; int j;
};
queue<xy> q;

void bfs(int i, int j) {
	q.push({ i, j });
	//int qSize = q.size();

	while (!q.empty()) {
		/*if (qSize == 0) {
			qSize = q.size();
		}*/
		xy nowPoint = q.front();
		q.pop();
		//--qSize;

		for (int d = 0; d < 4; ++d) {
			int ny = nowPoint.i + dy[d];
			int nx = nowPoint.j + dx[d];

			if (ny < 0 || nx < 0 || ny > n - 1 || nx > n - 1)
				continue;
			if (visit[ny][nx])
				continue;
			if (colors[ny][nx] != colors[nowPoint.i][nowPoint.j])
				continue;

			q.push({ ny, nx });
			visit[ny][nx] = true;
		}

	}
}
void bfs2(int i, int j) {
	q.push({ i, j });
	//int qSize = q.size();

	while (!q.empty()) {
		/*if (qSize == 0) {
			qSize = q.size();
		}*/
		xy nowPoint = q.front();
		q.pop();
		//--qSize;

		for (int d = 0; d < 4; ++d) {
			int ny = nowPoint.i + dy[d];
			int nx = nowPoint.j + dx[d];

			if (ny < 0 || nx < 0 || ny > n - 1 || nx > n - 1)
				continue;
			if (visit[ny][nx])
				continue;
			if ((colors[ny][nx] == colors[nowPoint.i][nowPoint.j]) ||
				(colors[ny][nx] == 'R' && colors[nowPoint.i][nowPoint.j]=='G') ||
				(colors[ny][nx] == 'G' && colors[nowPoint.i][nowPoint.j]=='R')) {
				q.push({ ny, nx });
				visit[ny][nx] = true;
				continue;
			}
		}

	}
}
void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visit[i][j] = false;
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int yes = 0; int no = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> colors[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) {
				bfs(i, j);
				no++;
			}
		}
	}

	init();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) {
				bfs2(i, j);
				yes++;
			}
		}
	}

	cout << no << " " << yes << '\n';
	return 0;
}