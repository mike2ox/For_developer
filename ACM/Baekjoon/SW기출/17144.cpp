/*
*	author : mike2ox
*	BOJ : 17144
*	descript : https://www.acmicpc.net/problem/17144
*	type : 삼성 기출
*/
#include <iostream>
using namespace std;

struct AIR {
	int x, y, dust;
};

AIR air[2];
AIR dust_[52 * 52];

int map[52][52];

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };

int N, M, T, dab;

int dfs(int d, int x, int y, int dir, int air_num) {
	//종료 조건
	if (d != 0 && map[y][x] == -1) 
		return 0;
	if (air_num == 0) {
		if (y == 0 && dir == 0) { 
			dir = 3; 
		}
		else if (x == M - 1 && dir == 3) { 
			dir = 1;
		}
		else if (y == air[air_num].y && dir == 1) {
			dir = 2;
		}
	}
	if (air_num == 1) {
		if (y == N - 1 && dir == 1) { 
			dir = 3;
		}
		else if (x == M - 1 && dir == 3) { 
			dir = 0;
		}
		else if (y == air[air_num].y && dir == 0) { 
			dir = 2; 
		}
	}
	// 다음 pos
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int ret = map[y][x];

	map[y][x] = dfs(d + 1, nx, ny, dir, air_num);
	
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> T;

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) { 
				air[cnt].x = j;
				air[cnt].y = i;
				cnt++;
			}
		}
	}
	for (int t = 1; t <= T; t++) {

		int dust_cnt = 0;
		// 뿌려질 먼지가 있는 곳을 탐색
		for (int i = 0; i < N; i++) { 
			for (int j = 0; j < M; j++) {
				if (map[i][j] && (map[i][j] / 5 >= 1)) {
					dust_[dust_cnt].x = j;
					dust_[dust_cnt].y = i; 
					dust_[dust_cnt].dust = map[i][j];
					dust_cnt++;
				}
			}
		}
		//먼지 퍼트리기
		for (int i = 0; i < dust_cnt; i++) { 
			int ix = dust_[i].x;
			int iy = dust_[i].y;
			int d_dust = dust_[i].dust / 5;

			for (int d = 0; d < 4; d++) {
				int nx = ix + dx[d];
				int ny = iy + dy[d];
				//경계바R
				if (nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] == -1) 
					continue;
				map[ny][nx] += d_dust;    map[iy][ix] -= d_dust;
			}
		}
		map[air[0].y][air[0].x] = dfs(0, air[0].x, air[0].y, 0, 0);
		map[air[1].y][air[1].x] = dfs(0, air[1].x, air[1].y, 1, 1);
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			dab += map[y][x];

	cout << dab + 2 << '\n';

	return 0;
}