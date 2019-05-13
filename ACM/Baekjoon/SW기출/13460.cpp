/*
*	author : mike2ox
*	BOJ : 13460
*	descript : https://www.acmicpc.net/problem/13460
*	type : 삼성기출
*	hint :
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m;
char map[10][11];
struct node {
	int ry, rx, by, bx, cnt;
};
node start;
void printall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}
int go() {
	queue<node> q;

	const int dy[] = { 0,0,-1,1 };
	const int dx[] = { 1,-1,0,0 };
	bool visit[10][10][10][10] = { 0, };
	int ret = -1;

	// 초기 위치
	q.push(start);
	visit[start.ry][start.rx][start.by][start.bx] = true;

	while (!q.empty()) {
		node cur = q.front(); q.pop();

		//1차 조건(동작 10번 초과면 종료)
		if (cur.cnt > 10)	break;
		//정상 종료
		if (map[cur.ry][cur.rx] == 'O'&&map[cur.by][cur.bx] != 'O') {
			ret = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			//기존 1칸씩만 동작하는 탐색법과 다름
			int n_ry = cur.ry;
			int n_rx = cur.rx;
			int n_by = cur.by;
			int n_bx = cur.bx;

			//빨간 구슬 동작
			while (1) {
				if (map[n_ry][n_rx] != '#' && map[n_ry][n_rx] != 'O') {
					n_ry += dy[i];
					n_rx += dx[i];
				}
				else {
					if (map[n_ry][n_rx] == '#') {
						n_ry -= dy[i], n_rx -= dx[i];
					}
					break;
				}
			}
			//파란 구슬 동작
			while (1) {
				if (map[n_by][n_bx] != '#' && map[n_by][n_bx] != 'O') {
					n_by += dy[i];
					n_bx += dx[i];
				}
				else {
					if (map[n_by][n_bx] == '#') {
						n_by -= dy[i], n_bx -= dx[i];
					}
					break;
				}
			}
			//서로 위치가 같은 경우
			if (n_ry == n_by && n_rx == n_bx) {
				if (map[n_ry][n_rx] != 'O') {
					int red_dis = abs(n_ry - cur.ry) + abs(n_rx - cur.rx);
					int blue_dis = abs(n_by - cur.by) + abs(n_bx - cur.bx);

					if (red_dis > blue_dis) {
						n_ry -= dy[i], n_rx -= dx[i];
					}
					else {
						n_by -= dy[i], n_bx -= dx[i];
					}
				}
			}

			if (!visit[n_ry][n_rx][n_by][n_bx]) {
				visit[n_ry][n_rx][n_by][n_bx] = true;
				node next;
				next.ry = n_ry; next.rx = n_rx;
				next.by = n_by; next.bx = n_bx;
				next.cnt = cur.cnt + 1;

				q.push(next);
			}
		}
	}
	
	return ret;
}
int main() {
	ios_base::sync_with_stdio("false");
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
				start.ry = i, start.rx = j;
			else if (map[i][j] == 'B')
				start.by = i, start.bx = j;
		}
	}	
	//printall();
	start.cnt = 0;
	int ret = go();
	cout << ret << '\n';

	return 0;
}
/*
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는 수 출력
1. 맵구현 + 출력
2. 동작 구현
3. 예외처리
*/
