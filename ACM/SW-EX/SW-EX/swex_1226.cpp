/*
*	author : mike2ox
*	swea : 1226
*	descript : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14vXUqAGMCFAYD
*	type : dfs
*/
#include<iostream>
#include<vector>
using namespace std;

char map[16][16];
bool visit[16][16];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { -1,1,0,0 };
bool flag;
int tc;
struct point {
	int y, x;
};

void dfs(point p) {
	if (map[p.y][p.x] == '3') {
		flag = true;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = p.y + dy[i];
		int nx = p.x + dx[i];
		if (ny < 0 || nx < 0 || nx >= 16 || ny >= 16)	continue;
		if (visit[ny][nx])	continue;
		if (map[ny][nx] == '1') continue;

		visit[ny][nx] = true;
		dfs({ ny, nx });
		visit[ny][nx] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	point p;

	while (cin >> tc) {
		for (int y = 0; y < 16; ++y) {
			for (int x = 0; x < 16; ++x) {
				cin >> map[y][x];
				visit[y][x] = false;
				if (map[y][x] == '2') {
					p.y = y; p.x = x;
					visit[y][x] = true;
				}
			}
		}

		flag = false;
		dfs(p);
		if (flag)
			cout << "#" << tc << " " << 1 << '\n';
		else
			cout << "#" << tc << " " << 0 << '\n';

	}

	return 0;
}
/*
*/

