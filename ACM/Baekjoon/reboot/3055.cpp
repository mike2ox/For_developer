// BJO no. 3055 탈출 , mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int r, c, minResult=123456789;
char tw[51][52];
int tw2[51][51];
bool visit[51][51];

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
pair<int, int> biber;

struct node{
	int y, x;
	int cnt;
}dotch;

void maketw2() {

	queue<pair<int, int>> q;
	int qSize;
	int waterTime = 1;
	
	// 1. 물 확산 map만듦
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; ++j) {
			if (tw[i][j] == '*') {
				q.push({ i, j });
				visit[i][j] = true;
			}		
		}
	}

	qSize = q.size();

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
			waterTime++;
		}

		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		qSize--;

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny<1 || nx<1 || ny>r || nx>c || visit[ny][nx])
				continue;
			if (tw[ny][nx] == 'D' || tw[ny][nx] == 'X')
				continue;

			tw2[ny][nx] = waterTime;
			q.push({ ny, nx });
			visit[ny][nx] = true;
		}

	}
}

void init() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; ++j) {
			visit[i][j] = false;
			if (tw2[i][j] == 0)
				tw2[i][j] = r * c;
			// cout << tw2[i][j] << ' ';
		}
		// cout << '\n';
	}
}
void go() {
	// 초기화
	init();
	queue<node> q;
	int qSize = 1;
	// 2.(in tw2) 고슴도치 이동
	q.push(dotch);
	visit[dotch.y][dotch.x] = true;

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
		}

		int cy = q.front().y;
		int cx = q.front().x;
		int cCnt = q.front().cnt;

		q.pop();
		qSize--;

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			//방문한곳 + 범위 밖
			if (ny<1 || nx<1 || ny>r || nx>c || visit[ny][nx])
				continue;
			// 골인지점인데 더 짧게 도착했는지?
			if (biber.first == ny && biber.second == nx&&minResult >cCnt+1) {
				minResult = cCnt + 1;
				return;
			}
			// 물이 도착하는 시간보다 크거나 같은 경우 or 벽인 경우
			if (tw2[ny][nx] <= cCnt + 1|| tw[ny][nx] == 'X'|| tw[ny][nx] == '*')
				continue;

			q.push({ ny, nx, cCnt + 1 });
			visit[ny][nx] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; ++j) {
			cin >> tw[i][j];
			if (tw[i][j] == 'D')
				biber = { i, j };
			if (tw[i][j] == 'S')
				dotch = { i, j, 0 };
		}
	}

	maketw2();
	go();

	if (minResult == 123456789)
		cout << "KAKTUS\n";
	else
		cout << minResult << '\n';

	return 0;
}