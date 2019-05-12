/*
*	author : mike2ox
*	BOJ : 17141
*	descript :https://www.acmicpc.net/problem/17141
*	type :
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int m, n;
int min_t = 10000000;
int map[50][50];
int copymap[50][50];
bool visit[50][50];

vector<pair<int, int>> v;	//바이러스 목록

void printall() {

	cout << '\n';
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 1)
				cout << "-" << " ";
			else
				cout << copymap[y][x] << " ";
		}
		cout << '\n';
	}
}
void init() {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (map[y][x] == 2) {
				copymap[y][x] = 0;
				continue;
			}
			copymap[y][x] = map[y][x];
			visit[y][x] = false;
		}
	}
}
bool ck() {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (copymap[y][x] != 0)	continue;
			if (map[y][x] == 0 || map[y][x] == 2)
				return true;
		}
	}
	return false;
}
int bfs() {
	queue<pair<int, int>> q;	//bfs용 바이러스

	const int dy[] = { 0,0,-1,1 };
	const int dx[] = { 1,-1,0,0 };

	int ck_n = 1;

	for (vector<pair<int, int>>::iterator itr = v.begin(); itr != v.end(); ++itr)
		q.push(*itr);
	//퍼지는 타이밍을 확인하기 위해
	int q_s = q.size();

	while (!q.empty()) {
		if (q_s == 0) {
			q_s = q.size();
			ck_n++;
		}
		int cy = q.front().first;
		int cx = q.front().second;

		visit[cy][cx] = true;

		q.pop();

		q_s--;

		for (int d = 0; d < 4; d++) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (nx < 0 || ny < 0 || ny >= n || nx >= n)	continue;
			if (visit[ny][nx])	continue;
			if (map[ny][nx] == 1)	continue;

			q.push({ ny, nx });
			copymap[ny][nx] = ck_n;
		}
	}

	return ck_n;
}
//cnt = 뽑힌 바이러스 수
void dfs(int cnt) {
	if (cnt == 3) {
		int ret = bfs();
		//확산 안된 곳이 있다면
		if (ck())
			ret = -1;
		else
			min_t = min(ret, min_t);
		printall();
		init();
		return;
	}
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (map[y][x] == 2) {
				v.push_back({ y,x });
				visit[y][x] = true;
				dfs(cnt + 1);
				visit[y][x] = false;
				v.pop_back();
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> map[y][x];

		}
	}

	dfs(0);

	if (min_t == 10000000)
		cout << -1 << '\n';
	else
		cout << min_t << '\n';

	return 0;
}

