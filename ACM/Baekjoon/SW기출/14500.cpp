/*
*	author : mike2ox
*	BOJ : 14500
*	descript : https://www.acmicpc.net/problem/14500
*	type : �Ｚ���� : dfs
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
//TODO : �� dfs�� ��� block�� ���¸� Ŀ���Ѵٰ� �����ϳ�(ex. ��ȸ��ü�� block�� ����)
// --> ���� �߸� ����...dfs�� �ذ� ����

int go(int ty, int tx, int n_block) {

	if (n_block == 4) {
		return mino[ty][tx];
	}

	int sum = 0;

	for (int i = 0; i < 4; ++i) {
		int ny = ty + dy[i];
		int nx = tx + dx[i];

		//�� ��ġ�� ���� ���� ��� + �湮 ����
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

	//�� (���� ��ǥ ���� ���)
	if (ty > 1 && ty <= n && tx > 1 && tx < m)
		result = max(result, mino[ty][tx - 1] + mino[ty][tx] + mino[ty - 1][tx] + mino[ty][tx + 1]);

	//�� (���� ��ǥ ���� ���)
	if (ty > 1 && ty < n && tx < m && tx >= 1)
		result = max(result, mino[ty - 1][tx] + mino[ty][tx] + mino[ty][tx + 1] + mino[ty + 1][tx]);

	//�� (���� ��ǥ ���� ���)
	if (ty >= 1 && ty < n && tx < m && tx>1)
		result = max(result, mino[ty][tx - 1] + mino[ty][tx] + mino[ty + 1][tx] + mino[ty][tx + 1]);
	//�� (���� ��ǥ ���� ���)
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
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (4 �� N, M �� 500)

��° �ٺ��� N���� �ٿ� ���̿� ���� �ִ� ���� �־�����.
i��° ���� j��° ���� ���������� i��° ĭ, ���ʿ������� j��° ĭ�� ���� �ִ� ���̴�.
�Է����� �־����� ���� 1,000�� ���� �ʴ� �ڿ����̴�.

ù° �ٿ� ��Ʈ�ι̳밡 ���� ĭ�� ���� ������ ���� �ִ��� ����Ѵ�.
*/