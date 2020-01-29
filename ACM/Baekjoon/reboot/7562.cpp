// BOJ no. 7562, mike2ox(2020)
#include<iostream>
// #include<vector>
#include<queue>
using namespace std;

const int dy[] = { 1,1,2,2,-1,-1,-2,-2 };
const int dx[] = { 2,-2,1,-1,2,-2,1,-1 };

bool visit[300][300];
int testCase;
int len;	//체스판 크기
int cy, cx, desY, desX;	//현재 위치, 목적지 위치

void bfs() {

	queue<pair<int, int>> night;
	int cnt = 1;
	int len_q = 1;
	night.push({ cy, cx });

	while (!night.empty()) {
		if (len_q == 0) {
			cnt++;
			len_q = night.size();
		}
		int nowY = night.front().first;
		int nowX = night.front().second;

		night.pop();
		visit[nowY][nowX] = true;
		--len_q;

		for (int i = 0; i < 8; ++i) {
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];

			if (ny<0 || nx <0 || ny>len || nx>len)
				continue;
			if (ny == desY && nx == desX) {
				cout << cnt << '\n';
				return;
			}
			if (visit[ny][nx])
				continue;

			night.push({ ny, nx });
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> testCase;

	for (int i = 0; i < testCase; ++i) {
		cin >> len;
		cin >> cy >> cx;
		cin >> desY >> desX;

		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; ++k) {
				visit[j][k] = false;
			}
		}

		if (cy == desY && cx == desX) {
			cout << 0 << '\n';
			continue;
		}

		bfs();
	}

	
	system("pause");
	return 0;
}