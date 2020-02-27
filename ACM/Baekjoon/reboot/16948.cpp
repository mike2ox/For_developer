// BJO no.16948 데스나이트, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n, r1, c1, r2, c2;

void bfs() {
	int moveCnt=0;
	const int dy[] = { -2,-2,0,0,2,2 };
	const int dx[] = { -1,1,-2,2,-1,1 };
	int board[200][200] = {0,};
	bool visit[200][200] = { false, };

	queue<pair<int, int>> q;
	q.push({ r1, c1 });
	visit[r1][c1] = true;
	int qSize = q.size();
	
	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
			moveCnt++;
		}
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();
		qSize--;

		for (int i = 0; i < 6; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= 200 || nx >= 200)
				continue;
			else if (visit[ny][nx])
				continue;
			else if (ny == r2 && nx == c2) {
				cout << moveCnt + 1 << '\n';
				return;
			} 

			q.push({ ny ,nx });
			visit[ny][nx] = true;

		}
	}

	// 이동할 수 없는 경우
	cout << -1 << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs();

	return 0;
}