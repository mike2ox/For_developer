/*
*	author : mike2ox
*	BOJ : 15684
*	descript : https://www.acmicpc.net/problem/15684
*	type : �Ｚ ���� :dfs
*/

#include<iostream>
#include<vector>
using namespace std;

int n, m, h;
int map[31][11];
int cnt;

bool check() {
	bool ret = true;

	for (int i = 1; i <= n; ++i) {
		int pos = i;

		for (int j = 0; j <= h; ++j) {
			if (map[j][pos] == 1) {
				++pos;
			}else if (map[j][pos - 1] == 1) {
				--pos;
			}
		}

		if (pos != i) {
			ret = false;
			return ret;
		}
	}

	return ret;
}

void dfs(int ret, int y, int x) {
	if (ret <= cnt || cnt == 3)
		return;
	if (check()) {
		cnt = ret;
		return;
	}
	for (int i = y; i <= h; ++i) {
		for (int j = x; j < n; ++j) {
			if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				dfs(ret + 1, i, j);
				map[i][j] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}

	cnt = 4;
	dfs(0, 1, 1);
	if (cnt == 4)
		cnt = -1;
	cout << cnt << '\n';

	system("pause");
	return 0;
}
//�ʷϼ��� ���μ��� ��Ÿ����, �ʷϼ��� ������ �����ϴ� ���� ���μ��� ���� �� �ִ� ���̴�.
//���μ��� ������ �� ���μ��� �����ؾ� �Ѵ�. 
//��, �� ���μ��� �����ϰų� ���� ���ϸ� �ȵȴ�. ��, ���μ��� ���� ���� �־�� �Ѵ�.
//���μ��� ������ �� ���� a�� b�� ��Ÿ����. (1 �� a �� H, 1 �� b �� N-1) b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� ����
//i�� ���μ��� ����� i���� �������� ��ٸ� ������ �����Ϸ���, �߰��ؾ� �ϴ� ���μ� ������ �ּڰ��� ���.
//���� 3���� ū ���̸� -1�� ����Ѵ�. ��, �Ұ����� ��쿡�� -1�� ����Ѵ�.