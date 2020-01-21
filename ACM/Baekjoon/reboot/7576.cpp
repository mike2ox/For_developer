// BOJ no. 7576, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

struct node {
	int y; int x;
};
queue<node> que;	//y, x
int n, m;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

int farm[1001][1001];
bool visit[1001][1001];

void printall() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << farm[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int bfs() {
	int minDay = 1;
	int sizeQueue = que.size();

	while (!que.empty()) {
		if (sizeQueue <= 0) {
			// printall();
			sizeQueue = que.size();
			++minDay;
		}

		int sy = que.front().y;
		int sx = que.front().x;

		que.pop();

		for (int d = 0; d < 4; ++d) {
			int ny = sy + dy[d];
			int nx = sx + dx[d];

			if (ny<1 || nx<1 || ny>m || nx>n)	//boundary
				continue;
			else if (farm[ny][nx] == -1)		//value == -1?
				continue;
			else if (visit[ny][nx])				//visit == true?
				continue;

			farm[ny][nx] = minDay;
			visit[ny][nx] = true;
			que.push({ ny,nx });
		}
		--sizeQueue;
	}

	return minDay-1;
}
bool checkFarm() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (farm[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> farm[i][j];
			if (farm[i][j] == 1) {
				que.push({ i, j });
				visit[i][j] = true;
			}
		}
	}
	// printall();
	int ret = bfs();

	if (checkFarm()) {
		if (ret == 1)
			cout << 0 << '\n';
		else
			cout << ret << '\n';
	}
	else
		cout << -1 << '\n';
	system("pause");
	return 0;
}