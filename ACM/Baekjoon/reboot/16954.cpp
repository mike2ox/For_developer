// BJO no. 17954 움직이는 미로탈출, mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

char maze[8][9];
int visit[8][8];
// start : y 7, x 0 
// end : y 0, x 7

void init(int cnt) {
	if (cnt > 8)
		return;
	else {
		for (int i = 7; i > 0; --i) {
			for (int j = 0; j < 8; ++j) {
				maze[i][j] = maze[i-1][j];
			}
		}
		for (int i = 0; i < 8; ++i) {
			maze[0][i] = '.';
		}
	}
}
bool go() {
	const int dy[] = { 0,0,1,-1,1,1,-1,-1,0};
	const int dx[] = { 1,-1,0,0,1,-1,1,-1,0};

	queue<pair<int, int>> q;
	q.push({ 7, 0 });
	int qSize = q.size();
	int cnt = 1;
	while (!q.empty()) {
		if (qSize == 0) {
			init(cnt);
			qSize = q.size();
			cnt++;
		}
		pair<int, int> now = q.front();
		q.pop();
		qSize--;

		for (int i = 0; i < 9; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny > 7 || nx > 7)
				continue;
			if (maze[now.first][now.second] == '#')
				break;
			if (maze[ny][nx] == '#'||visit[ny][nx] > 8)
				continue;
			if (ny == 0 && nx == 7) {
				return true;
			}
			q.push({ ny, nx });
			visit[ny][nx] = cnt;
		}
	}
	return false;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> maze[i][j];
		}
	}
	
	if (go())
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}