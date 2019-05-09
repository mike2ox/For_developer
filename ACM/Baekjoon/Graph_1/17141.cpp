/*
*	author : mike2ox
*	BOJ : 17141
*	descript :https://www.acmicpc.net/problem/17141
*	type :
*/
#include<iostream>
#include<queue>
using namespace std;

int map[50][50];
int copymap[50][50];
bool visit[50][50];

queue<pair<int, int>> q;

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

void printall(int n) {

	cout << '\n';
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if(map[y][x]==1)
				cout << "-" << " ";
			else
				cout << copymap[y][x] << " ";
		}
		cout << '\n';
	}
}
void bfs(int n) {
	int l_q = q.size();
	int cnt = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		if (!l_q) {
			cnt++;
			l_q = q.size();
		}
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || nx >= n || ny >= n)	continue;
			if (visit[ny][nx])	continue;
			if (copymap[ny][nx] == 1) continue;
			copymap[ny][nx] = cnt;
			visit[ny][nx] = true;
			q.push({ ny, nx });
		}

		l_q--;
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> map[y][x];
			copymap[y][x] = map[y][x];
			visit[y][x] = false;

			if (map[y][x] == 2) {
				q.push({ y, x });
				visit[y][x] = true;
				copymap[y][x] = 0;
			}
		}
	}
	bfs(n);
	printall(n);
	return 0;
}
/*
바이러스 확산 최소 시간
바이러스 m개,  연구소 nxn
빈칸 0, 벽1, 바이러스2

접근
1. 맵 입력 -> 출력 ok
2. 그냥 BFS 탐색 -> 출력 되도록
3. 갯수 지정해서 탐색 -> 출력되도록
4. 최소값
*/

