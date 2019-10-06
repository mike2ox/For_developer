/*
*	author : mike2ox
*	BOJ : 15683
*	descript : https://www.acmicpc.net/problem/15683
*	type : 삼성 기출 : dfs(모든경우)
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ret;
int map[8][8];
int c_size;
//1번부터 5번까지 각 경우의 수
const int rot[] = { 4, 2, 4, 4, 1 };

struct cctv {
	int y, x, type;
};

cctv camera[8];


void update(int dir, cctv tv) {

	//4방향중에 하나로 선정
	switch (dir%=4)	{
	case 0:
		for (int x = tv.x + 1; x < m; ++x) {
			if (map[tv.y][x] == 6)    
				break;
			map[tv.y][x] = -1;
		}
		break;
	case 1:
		for (int y = tv.y - 1; y >= 0; --y) {
			if (map[y][tv.x] == 6)   
				break;
			map[y][tv.x] = -1;
		}
		break;
	case 2:
		for (int x = tv.x - 1; x >= 0; --x) {
			if (map[tv.y][x] == 6)   
				break;
			map[tv.y][x] = -1;
		}
		break;
	case 3:
		for (int y = tv.y + 1; y < n; ++y) {
			if (map[y][tv.x] == 6)   
				break;
			map[y][tv.x] = -1;
		}
	}
}


void cp_map(int desc[8][8], int src[8][8]) {
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			desc[i][j] = src[i][j];
}

void dfs(int c_idx) {
	if (c_idx == c_size) {
		int temp = 0;

		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < m; ++x) {
				if (map[y][x] == 0) {
					++temp;
				}
			}
		}
		if (ret > temp) {
			ret = temp;
		}
		return;
	}

	int backup[8][8];
	int type = camera[c_idx].type;
	for (int dir = 0; dir < rot[type]; ++dir) {
		cp_map(backup, map);
		if (type == 0) {
			update(dir, camera[c_idx]);
		}
		if (type == 1) {
			update(dir, camera[c_idx]);
			update(dir + 2, camera[c_idx]);
		}
		if (type == 2) {
			update(dir, camera[c_idx]);
			update(dir + 1, camera[c_idx]);
		}
		if (type == 3) {
			update(dir, camera[c_idx]);
			update(dir + 1, camera[c_idx]);
			update(dir + 2, camera[c_idx]);
		}
		if (type == 4) {
			update(dir, camera[c_idx]);
			update(dir + 1, camera[c_idx]);
			update(dir + 2, camera[c_idx]);
			update(dir + 3, camera[c_idx]);
		}
		dfs(c_idx + 1);
		cp_map(map, backup);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			//
			if (map[i][j] != 6 && map[i][j] != 0) {
				camera[c_size].y = i;
				camera[c_size].x= j;
				camera[c_size].type = map[i][j]-1;
				c_size++;
			}
		}
	}

	ret = 100;
	dfs(0);
	cout << ret << '\n';
	return 0;
}