/*
*	author : mike2ox
*	BOJ : 14502
*	descript : https://www.acmicpc.net/problem/14502
*	type : BFS + DFS
*/#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
int ret = -1;
int w;
int map[8][8];
int copymap[8][8];
bool visit[8][8];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

queue<pair<int, int>> q;
int ckpt() {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copymap[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}
void printall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << copymap[i][j] << " ";
		}
		cout << '\n';
	}
}
int bfs() {

	//copy
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copymap[i][j] = map[i][j];
			visit[i][j] = false;
			if (map[i][j] == 2) {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (copymap[ny][nx] == 0 && !visit[ny][nx]) {
				copymap[ny][nx] = 2;
				visit[ny][nx] = true;
				q.push({ ny, nx });
			}
		}

	}
	//printall();
	return ckpt();
}

// 0,1,2 : 빈칸, 벽, 바이러스
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}


	for (int y1 = 0; y1 < n; y1++) {
		for (int x1 = 0; x1 < m; x1++) {
			for (int y2 = 0; y2 < n; y2++) {
				for (int x2 = 0; x2 < m; x2++) {
					for (int y3 = 0; y3 < n; y3++) {
						for (int x3 = 0; x3 < m; x3++) {
							if ((y1 == y2 && x1 == x2) || (y3 == y2 && x3 == x2) || (y1 == y3 && x1 == x3)) continue;
							//if ((y1 == y2 == y3 && x1 == x2 == x3)) continue;
							if (map[y1][x1] == 0 && map[y2][x2] == 0 && map[y3][x3] == 0) {
								map[y1][x1] = 1;
								map[y2][x2] = 1;
								map[y3][x3] = 1;
								ret = max(bfs(), ret);
								map[y1][x1] = 0;
								map[y2][x2] = 0;
								map[y3][x3] = 0;
							}
						}
					}
				}
			}
		}
	}


	//bfs();
	//printall(n, m);
	//cout << ckpt() << '\n';
	cout << ret << '\n';
	//0이 있는곳의 크기
	return 0;
}
/*
1. 벽을 세우지말고 바이러스가 확산된 상태 출력하도록 구현
2. 벽을 세우는 방법 구현
3. 1+2 결합 형태
*/