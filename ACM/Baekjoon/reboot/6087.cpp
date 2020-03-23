// BJO no. 6087 ·¹ÀÌÀú Åë½Å , mike2ox(2020)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char maze[100][101];
int visit[100][101];
int h, w;
int minMiror = 10001;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
//ÁÂÇ¥, ²©Àº È½¼ö
struct state {
	int y, x, predir, cnt;
};

state startpoint;
vector<state> v;
void go(state start) {
	queue<state> q;
	q.push(start);
	visit[start.y][start.x] = 0;
	int qSize = q.size();

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
		}
		state nowPoint = q.front();
		q.pop();
		--qSize;

		for (int i = 0; i < 4; ++i) {
			int ny = nowPoint.y + dy[i];
			int nx = nowPoint.x + dx[i];
			int nextCnt;
			if (i == nowPoint.predir || nowPoint.predir == -1) {
				nextCnt = nowPoint.cnt;
			}
			else {
				nextCnt = nowPoint.cnt+1;
			}

			if (ny < 0 || nx < 0 || ny > h - 1 || nx > w - 1)
				continue;
			if (visit[ny][nx] < nextCnt||maze[ny][nx] == '*'||minMiror < nowPoint.cnt)
				continue;
			if (maze[ny][nx] == 'C') {
				if (i != nowPoint.predir)
					nowPoint.cnt += 1;
				if (minMiror > nowPoint.cnt)
					minMiror = nowPoint.cnt;
				continue;
			}
			q.push({ ny, nx, i, nextCnt});
			visit[ny][nx] = nextCnt;
			
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> w >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> maze[i][j];
			visit[i][j] = 100000;
			if (maze[i][j] == 'C') {
				startpoint.y = i;
				startpoint.x = j;
				startpoint.predir = -1;
				startpoint.cnt = 0;
			}
		}
	}

	go(startpoint);
	cout << minMiror << '\n';

	return 0;
}