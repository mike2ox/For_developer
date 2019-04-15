/*
*	author : mike2ox
*	swex : �ɺ� ����
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : ����Ž��
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

//0��, 1��, 2��, 3��
int run(int x, int y, int dir) {
	int cnt = 0;
	int sx = x;
	int sy = y;
	int ax = x + dx[dir];
	int ay = y + dy[dir];
	int d = dir;

	while (1) {
		//���� �ε��� ���
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

		//����
		if (map[ax][ay] == -1 || (ax == sx && ay == sy)) {
			return cnt;
		}

		//��ĭ�� ���
		if (map[ax][ay] == 0) {
			ax = ax + dx[d];
			ay = ay + dy[d];
		}

		//����� ���
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
		//��Ȧ�� ���
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
/* ���ӿ��� ���� �� �ִ� ������ �ִ��� ���Ͽ���!
�������� ũ��� ���簢������ �־�����, �� ���� ���� N �� 5 �̻� 100 ���� (5 �� N �� 100)
��Ȧ�� ������ ������ ���� 6 ~ 10.
��Ȧ�� ������ ������ ���� -1.
�����ǿ��� ��Ȧ �Ǵ� ��Ȧ�� �������� �ʴ� ��쵵 �ִ�.

��Ȧ�� �ִ� ��� �ݵ�� ��(pair)���� �����ϸ�, ��Ȧ�� �־����� ��� �ִ� 5�� ����.
��Ȧ�� ����� �ɺ��� ������ ���ڸ� ���� �ݴ��� ��Ȧ�� �̵��ϰ� �Ǹ�, �̶� ��������� �״�� �����ȴ�.
��Ȧ�� �ּ� 1������ �ִ� 5���� �־�����.

*/