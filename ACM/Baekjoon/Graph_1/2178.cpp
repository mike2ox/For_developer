/*
*	author : mike2ox
*	BOJ : 2178
*	descript : https://www.acmicpc.net/problem/2178
*	type : 
*/
#include<iostream>
#include<queue>
using namespace std;

char map[101][102];
int n, m;

struct node {
	int y, x;
};

int go() {
	int ret = 1;
	const int dy[] = { 0,0,-1,1 }; const int dx[] = { 1,-1,0,0 };
	bool visit[101][101] = { false, };
	queue<node> q;

	q.push({ 1,1 });
	visit[1][1] = true;
	int q_s = q.size();

	while (!q.empty()) {
		if (q_s == 0) {
			q_s = q.size();
			ret++;
		}

		int cy = q.front().y;
		int cx = q.front().x;
		
		q.pop();
		q_s--;

		for (int d = 0; d < 4; d++) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (nx < 1 || ny < 1 || nx > m || ny > n)	continue;
			if (map[ny][nx] == '0')	continue;
			if (visit[ny][nx])	continue;
			if (ny == n && nx == m)	return ret+1;
			visit[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> map[y][x];//입력이 붙어서 와서 int -> char로 변경
		}
	}

	int ret = go();

	cout << ret << '\n';

	return 0;
}
/*
(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 
지나야 하는 최소의 칸 수를 구하는 프로그램을 작성
*/