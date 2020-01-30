// BOJ no. 16929, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n, m;
bool visit[51][51];
char board[51][51];

const int dy[] = {0, 0,0,-1,1 };
const int dx[] = {0, 1,-1,0,0 };

struct node {
	int y, x;
	int dir;
};

bool bfs(int y, int x) {
	queue<node> q;
	// 초기값
	q.push({ y, x, 0});

	while (!q.empty()) {
		node curPoint = q.front();
		visit[curPoint.y][curPoint.x] = true;
		q.pop();

		for (int d = 1; d <= 4; ++d) {
			int cy = curPoint.y + dy[d];
			int cx = curPoint.x + dx[d];

			//out boundary
			if (cy<0 || cx<0 || cy>n - 1 || cx>m - 1)
				continue;

			//이전 자리로 가는거 방지
			if (curPoint.dir == 1 && d == 2)
				continue;
			else if (curPoint.dir == 2 && d == 1)
				continue;
			else if (curPoint.dir == 3 && d == 4)
				continue;
			else if (curPoint.dir == 4 && d == 3)
				continue;

			//문자 불일치 -> 방문했던 곳(종료) -> 다시 탐색
			if (board[cy][cx] != board[y][x])
				continue;
			else if (visit[cy][cx])
				return true;
			else {
				q.push({ cy, cx,d });
			}
		}

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
			if (!visit[y][x]) {
				// 탐색하지 않은 곳
				if (bfs(y, x)) {
					cout << "Yes" << '\n';
					return 0;
				}
			}
		}
	}

	cout << "No" << '\n';
	return 0;

}