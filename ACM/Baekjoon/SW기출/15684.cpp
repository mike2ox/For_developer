/*
*	author : mike2ox
*	BOJ : 15684
*	descript : https://www.acmicpc.net/problem/15684
*	type : 삼성 기출 :dfs
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
//초록선은 세로선을 나타내고, 초록선과 점선이 교차하는 점은 가로선을 놓을 수 있는 점이다.
//가로선은 인접한 두 세로선을 연결해야 한다. 
//단, 두 가로선이 연속하거나 서로 접하면 안된다. 또, 가로선은 점선 위에 있어야 한다.
//가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결
//i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력.
//답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.