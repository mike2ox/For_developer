// BJO no.14502 연구소, mike2ox(2020)
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int n, m;
bool visit[8][8];
int maps[8][8];
int maxSpace;
queue<pair<int, int>> q;
void printmap(int value[][8]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << value[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void go2() {
	//cout << "go2 start\n";
	const int dy[] = { 0,0,1,-1 };
	const int dx[] = { 1,-1,0,0 };
	int cpmaps[8][8];
	int tmpSpace = 0;

	// 바이러스 찾기
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cpmaps[i][j] = maps[i][j];
			visit[i][j] = false;

			if (maps[i][j] == 2) {
				q.push({ i, j });
				visit[i][j] = true;
			}
		}
	}

	//printmap(cpmaps);


	//확산시키기
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny<0 || nx<0 || ny>n - 1 || nx>m - 1 || visit[ny][nx])
				continue;
			else if (cpmaps[ny][nx] == 1)
				continue;
			else {
				cpmaps[ny][nx] = 2;
				q.push({ ny, nx });
				visit[ny][nx] = true;
			}
		}
		// printmap(cpmaps);
	}

	//빈공간 계산
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (cpmaps[i][j] == 0)
				tmpSpace++;
		}
	}

	if (maxSpace < tmpSpace)
		maxSpace = tmpSpace;
}
void go(int y, int wallCnt) {
	if (wallCnt ==3) {
		go2();//바이러스 채우기
		return;
	}

	// 벽새우기
	for (int i = y; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (maps[i][j] == 0) {
				maps[i][j] = 1;
				go(i, wallCnt + 1);
				maps[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> maps[i][j];
		}
	}
	
	// 시작점, 세운 벽 갯수
	go(0, 0);

	cout << maxSpace << '\n';

	return 0;
}