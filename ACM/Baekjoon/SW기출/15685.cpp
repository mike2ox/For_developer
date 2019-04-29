/*
*	author : mike2ox
*	BOJ : 15685
*	descript : https://www.acmicpc.net/problem/15685
*	type : 삼성 기출 : 시뮬레이션
*/

#include<iostream>
#include<vector>
using namespace std;

bool map[101][101];
int n, x, y, d, g;
int cnt=0;
const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };

vector<int> dragon;

int getdir(int tdir) {
	switch (tdir)
	{
	case 0:
	case 1:
	case 2:
		tdir = tdir + 1;
		break;
	case 3:
		tdir = 0;
		break;
	}
	return tdir;
}

void go(int tx, int ty, int td,int tg) {
	dragon.clear();
	dragon.push_back(td);
	
	while (tg--) {
		for (int i = dragon.size() - 1; i >= 0; --i) {
			dragon.push_back(getdir(dragon[i]));
		}
	}
	map[ty][tx] = true;
	for (vector<int>::iterator itr = dragon.begin(); itr != dragon.end(); ++itr) {
		switch (*itr)
		{
		case 0:
			tx++;
			break;
		case 1:
			ty--;
			break;
		case 2:
			tx--;
			break;
		case 3:
			ty++;
			break;
		}
		if (tx >= 0 && tx <= 100 && ty >= 0 && ty <= 100)
			map[ty][tx] = true;
		else
			continue;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> d >> g;
		go(x, y, d, g);
	}
	
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			if (map[i][j]&& map[i+1][j]&& map[i][j+1]&& map[i+1][j+1])
				cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
//좌표 평면의 x축은 → 방향, y축은 ↓ 방향
//K(K > 1)세대 드래곤 커브는 K - 1세대 드래곤 커브를 끝 점을 기준으로 90도 시계 방향 회전 시킨 다음,
//그것을 끝 점에 붙인 것이다.
//크기가 100×100인 격자 위에 드래곤 커브가 N개
//크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수를 구하는 프로그램
//격자의 좌표는 (x, y)로 나타내며, 0 ≤ x ≤ 100, 0 ≤ y ≤ 100만 유효한 좌표
