// BOJ no. 16929, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n, m;

bool visit[51][51];
char board[51][52];
int flag = false;

const int dy[] = {0,0,-1,1 };
const int dx[] = {1,-1,0,0 };

void dfs(int pY, int pX, int cY, int cX, int cnt) {
	if (cnt >=4 && visit[cY][cX]) {
		flag = true;
		return;
	}
	visit[cY][cX] = true;

	for (int d = 0; d < 4; ++d) {
		int nY = cY + dy[d];
		int nX = cX + dx[d];

		if (nY<0 || nX<0 || nY>n - 1 || nX>m - 1)
			continue;
		if (board[nY][nX] != board[cY][cX])
			continue;
		if (nY == pY && nX == pX)
			continue;

		// 범위안이고 문자가 같고 이전 위치로 안가는 경우
		dfs(cY, cX, nY, nX, cnt+1);
		if (flag)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; ++y) 
		for (int x = 0; x < m; ++x) 
			cin >> board[y][x];

	
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (!visit[y][x])
				dfs(y, x, y, x,0);
			if (flag) {	//하나라도 cycle있을시 종료
				cout << "Yes\n";
				return 0;
			}
		}
	}

	cout << "No\n";
	return 0;

}