// BJO no. 16197 두 동전, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n, m;
char board[20][21];
bool visit[21][21][21][21];
struct coin {
	int coinY, coinX;
};
struct coins {
	coin a, b;
};
queue<coins> q;
int bfs() {
	// 우측, 좌측, 위, 아래
	const int dy[] = { 0,0,-1,1 };
	const int dx[] = { 1,-1,0,0 };
	int qSize = q.size();
	int minimum = 0;
	bool nonpass = false;

	// 버튼 10번 초과, 동전 못떨어뜨림 --> -1 출력
	while (minimum < 10) {
		if (qSize == 0) {
			if (q.size() == 0)
				return -1;
			qSize = q.size();
			++minimum;
		}
		coins sCoins = q.front();
		q.pop();
		--qSize;

		for (int d = 0; d < 4; ++d) {
			int naY = sCoins.a.coinY + dy[d];
			int naX = sCoins.a.coinX + dx[d];
			int nbY = sCoins.b.coinY + dy[d];
			int nbX = sCoins.b.coinX + dx[d];

			//방문했던 곳이면 pass
			if (visit[naY][naX][nbY][nbX])
				continue;

			if (naY<0 || naX<0 || naY >=n || naX >=m) {
				if (nbY<0 || nbX<0 || nbY >=n || nbX >=m) {//둘다 탈출
					continue;
				}
				else { // a는 탈출
					return minimum+1;
				}
			}
			else {
				if (nbY<0 || nbX<0 || nbY >=n || nbX >=m) {//b는 탈출
					return minimum+1;
				}
			}

			// 둘다 못 탈출
			if (board[naY][naX] == '#') {
				if (board[nbY][nbX] == '#')	// 둘다 벽일 경우
					continue;
				else { // a만 벽
					
					visit[sCoins.a.coinY][sCoins.a.coinX][nbY][nbX] = true;
					q.push({ sCoins.a.coinY, sCoins.a.coinX, nbY, nbX });
				}
			}
			else {
				if (board[nbY][nbX] == '#') {//b만 벽
					visit[naY][naX][sCoins.b.coinY][sCoins.b.coinX] = true;
					q.push({ naY, naX, sCoins.b.coinY, sCoins.b.coinX });
				}
				else { // 둘다 벽 아님
					visit[naY][naX][nbY][nbX] = true;
					q.push({ naY, naX, nbY, nbX });
				}
			}
		}
	}

	if (!nonpass)
		return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool flag = false;
	//bool check = false;
	coin a = { 0,0 };
	coin b = { 0,0 };
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				if (!flag) {
					flag = true;
					a = { i,j };
				}
				else
					b = { i,j};
			}
		}
	}

	q.push({ a,b });
	visit[a.coinY][a.coinX][b.coinY][b.coinX] = true;
	cout << bfs() << '\n';
	return 0;
}