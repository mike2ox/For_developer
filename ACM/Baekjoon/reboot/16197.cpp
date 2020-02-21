// BJO no. 16197 �� ����, mike2ox(2020)
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
	// ����, ����, ��, �Ʒ�
	const int dy[] = { 0,0,-1,1 };
	const int dx[] = { 1,-1,0,0 };
	int qSize = q.size();
	int minimum = 0;
	bool nonpass = false;

	// ��ư 10�� �ʰ�, ���� ������߸� --> -1 ���
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

			//�湮�ߴ� ���̸� pass
			if (visit[naY][naX][nbY][nbX])
				continue;

			if (naY<0 || naX<0 || naY >=n || naX >=m) {
				if (nbY<0 || nbX<0 || nbY >=n || nbX >=m) {//�Ѵ� Ż��
					continue;
				}
				else { // a�� Ż��
					return minimum+1;
				}
			}
			else {
				if (nbY<0 || nbX<0 || nbY >=n || nbX >=m) {//b�� Ż��
					return minimum+1;
				}
			}

			// �Ѵ� �� Ż��
			if (board[naY][naX] == '#') {
				if (board[nbY][nbX] == '#')	// �Ѵ� ���� ���
					continue;
				else { // a�� ��
					
					visit[sCoins.a.coinY][sCoins.a.coinX][nbY][nbX] = true;
					q.push({ sCoins.a.coinY, sCoins.a.coinX, nbY, nbX });
				}
			}
			else {
				if (board[nbY][nbX] == '#') {//b�� ��
					visit[naY][naX][sCoins.b.coinY][sCoins.b.coinX] = true;
					q.push({ naY, naX, sCoins.b.coinY, sCoins.b.coinX });
				}
				else { // �Ѵ� �� �ƴ�
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