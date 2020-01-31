// BOJ no. 7562, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { 1,1,2,2,-1,-1,-2,-2 };
const int dx[] = { 2,-2,1,-1,2,-2,1,-1 };

bool visit[301][301];
int testCase;
int len;	//ü���� ũ��
int cy, cx, desY, desX;	//���� ��ġ, ������ ��ġ
vector<int> ret;

struct node {
	int curY, curX;
	int cnt;
};

void bfs() {

	queue<node> night;
	int depth = 1;
	int len_q = 1;
	night.push({ cy, cx, 0});
	visit[cy][cx] = true;

	while (!night.empty()) {
		if (len_q == 0) {
			depth++;
			len_q = night.size();
		}
		int nowY = night.front().curY;
		int nowX = night.front().curX;
		int nowCnt = night.front().cnt;
		night.pop();
		--len_q;

		for (int i = 0; i < 8; ++i) {
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];

			if (ny<0 || nx <0 || ny>len || nx>len)
				continue;
			if (ny == desY && nx == desX) {
				ret.push_back(nowCnt+1);
				return;
			}
			if (visit[ny][nx])
				continue;

			night.push({ ny, nx, nowCnt+1 });
			visit[ny][nx] = true;
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

		if (cy == desY && cx == desX)
			ret.push_back(0);
		else
			bfs();

		
	}

	for (int i =0; i <ret.size(); ++i)
		cout << ret[i] << '\n';

	return 0;
}