/*
*	author : mike2ox
*	BOJ : 14500
*	descript : https://www.acmicpc.net/problem/14500
*	type : 삼성기출 : dfs
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
int mino[501][501];
bool visit[501][501];

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
//TODO : 왜 dfs가 모든 block의 형태를 커버한다고 생각하나(ex. ㄴ회전체는 block에 없음)
// --> 문제 잘못 읽음...dfs로 해결 가능

int go(int ty, int tx, int n_block) {

	if (n_block == 4) {
		return mino[ty][tx];
	}

	int sum = 0;

	for (int i = 0; i < 4; ++i) {
		int ny = ty + dy[i];
		int nx = tx + dx[i];

		//현 위치가 범위 밖일 경우 + 방문 유무
		if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && !visit[ny][nx]) {
			visit[ny][nx] = true;
			sum = max(sum, mino[ty][tx] + go(ny, nx, n_block + 1));
			visit[ny][nx] = false;
		}
	}

	return sum;
}
int go2(int ty, int tx) {

	int result = 0;

	//ㅗ (현재 좌표 ㅡ의 가운데)
	if (ty > 1 && ty <= n && tx > 1 && tx < m)
		result = max(result, mino[ty][tx - 1] + mino[ty][tx] + mino[ty - 1][tx] + mino[ty][tx + 1]);

	//ㅏ (현재 좌표 ㅣ의 가운데)
	if (ty > 1 && ty < n && tx < m && tx >= 1)
		result = max(result, mino[ty - 1][tx] + mino[ty][tx] + mino[ty][tx + 1] + mino[ty + 1][tx]);

	//ㅜ (현재 좌표 ㅡ의 가운데)
	if (ty >= 1 && ty < n && tx < m && tx>1)
		result = max(result, mino[ty][tx - 1] + mino[ty][tx] + mino[ty + 1][tx] + mino[ty][tx + 1]);
	//ㅓ (현재 좌표 ㅣ의 가운데)
	if (ty > 1 && ty < n && tx > 1 && tx <= m)
		result = max(result, mino[ty - 1][tx] + mino[ty][tx] + mino[ty][tx - 1] + mino[ty + 1][tx]);

	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> mino[i][j];

	int result = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			visit[i][j] = true;
			result = max(result, go(i, j, 1));
			result = max(result, go2(i, j));
			visit[i][j] = false;
		}
	}

	cout << result << '\n';

	system("pause");
	return 0;
}
/*
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다.
i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다.
입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/