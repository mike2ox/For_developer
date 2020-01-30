// BOJ no. 4963, mike2ox(2020)
#include<iostream>
using namespace std;

const int dy[] = {1,-1,0,0,1,1,-1,-1};
const int dx[] = {0,0,1,-1,1,-1,1,-1};
int island[51][51];
bool visit[51][51];
int w, h;

void dfs(int y, int x) {
	
	visit[y][x] = true;

	for (int d = 0; d < 8; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny<1 || nx<1 || ny>h || nx>w)
			continue;
		if (visit[ny][nx]||island[ny][nx]!=1)
			continue;

		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	while (1) {
		int cnt=0;
		
		cin >> w >> h;

		//terminal condition
		if (w == 0 && h == 0)
			return 0;

		// insert data
		for (int y = 1; y <= h; ++y) {
			for (int x = 1; x <= w; ++x) {
				cin >> island[y][x];
			}
		}
		// search
		for (int y = 1; y <= h; ++y) {
			for (int x = 1; x <= w; ++x) {
				if (!visit[y][x]&&island[y][x]==1) {
					dfs(y, x);
					cnt++;
				}
			}
		}
		// init visit array
		for (int y = 1; y <= h; ++y) {
			for (int x = 1; x <= w; ++x) {
				visit[y][x] = false;
			}
		}

		cout << cnt << '\n';
	}
}