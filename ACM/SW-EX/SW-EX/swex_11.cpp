/*
*	author : mike2ox
*	swex : 핀볼 게임
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : 완전탐색
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

struct Worm {
	int x, y, data;
	Worm() { 
		x = 0, y = 0, data = 0; 
	}
	Worm(int x, int y, int d) :
		x(x), y(y), data(d) {}
};

int t, n, res;
int map[100][100];
Worm worm[10];
int wormIdx;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

//0상, 1하, 2좌, 3우
int run(int x, int y, int dir) {
	int cnt = 0;
	int sx = x;
	int sy = y;
	int ax = x + dx[dir];
	int ay = y + dy[dir];
	int d = dir;

	while (1) {
		//벽에 부딪힌 경우
		if (ax < 0 || ay < 0 || ax >= n || ay >= n) {
			int odir;
			if (d == 0)
				odir = 1;
			else if (d == 1) 
				odir = 0;
			else if (d == 2) 
				odir = 3;
			else 
				odir = 2;

			ax = ax + dx[odir];
			ay = ay + dy[odir];
			d = odir;
			cnt++;
			continue;
		}

		//종료
		if (map[ax][ay] == -1 || (ax == sx && ay == sy)) {
			return cnt;
		}

		//빈칸인 경우
		if (map[ax][ay] == 0) {
			ax = ax + dx[d];
			ay = ay + dy[d];
		}

		//블록인 경우
		else if (1 <= map[ax][ay] && map[ax][ay] <= 5) {
			int odir;
			if (map[ax][ay] == 1) {
				if (d == 0) 
					odir = 1;
				else if (d == 1)
					odir = 3;
				else if (d == 2)
					odir = 0;
				else 
					odir = 2;
			}
			else if (map[ax][ay] == 2) {
				if (d == 0) 
					odir = 3;
				else if (d == 1) 
					odir = 0;
				else if (d == 2) 
					odir = 1;
				else 
					odir = 2;
			}
			else if (map[ax][ay] == 3) {
				if (d == 0)
					odir = 2;
				else if (d == 1) 
					odir = 0;
				else if (d == 2) 
					odir = 3;
				else 
					odir = 1;
			}
			else if (map[ax][ay] == 4) {
				if (d == 0)
					odir = 1;
				else if (d == 1) 
					odir = 2;
				else if (d == 2) 
					odir = 3;
				else
					odir = 0;
			}
			else {
				if (d == 0) odir = 1;
				else if (d == 1) 
					odir = 0;
				else if (d == 2)
					odir = 3;
				else odir = 2;
			}

			ax = ax + dx[odir];
			ay = ay + dy[odir];
			d = odir;
			cnt++;
		}
		//웜홀인 경우
		else if (6 <= map[ax][ay] && map[ax][ay] <= 10) {
			for (int i = 0; i < wormIdx; i++) {
				if (map[ax][ay] == worm[i].data) {
					if (worm[i].x != ax || worm[i].y != ay) {
						ax = worm[i].x + dx[d];
						ay = worm[i].y + dy[d];
						break;
					}
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		
		cin >> n;
		
		wormIdx = 0;
		res = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];

				if (6 <= map[i][j] && map[i][j] <= 10) {
					Worm w(i, j, map[i][j]);
					worm[wormIdx++] = w;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						res = max(run(i, j, k), res);
					}
				}
			}
		}
		cout << "#" << tc << " " << res << '\n';
	}

	return 0;
}
/* 게임에서 얻을 수 있는 점수의 최댓값을 구하여라!
게임판의 크기는 정사각형으로 주어지며, 한 변의 길이 N 은 5 이상 100 이하 (5 ≤ N ≤ 100)
웜홀은 게임판 내에서 숫자 6 ~ 10.
블랙홀은 게임판 내에서 숫자 -1.
게임판에서 웜홀 또는 블랙홀이 존재하지 않는 경우도 있다.

웜홀이 있는 경우 반드시 쌍(pair)으로 존재하며, 웜홀이 주어지는 경우 최대 5쌍 존재.
웜홀을 통과한 핀볼은 동일한 숫자를 가진 반대편 웜홀로 이동하게 되며, 이때 진행방향은 그대로 유지된다.
블랙홀은 최소 1개에서 최대 5개가 주어진다.

*/