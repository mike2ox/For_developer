/*
*	author : mike2ox
*	BOJ : 15684
*	descript : https://www.acmicpc.net/problem/15684
*	type : 삼성 기출 :dfs
*/

#include<iostream>
#include<vector>
using namespace std;

int n, m,h;

int laddle[31][11];

void go(int ty, int tx, int cnt) {
	if (cnt > 3) return;
	

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> h;

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		laddle[a][b] = 1;
	}

	int ret = 4;
	go(1,1,0);
	if (ret == 4)	return -1;
	cout << ret << '\n';

	system("pause");
	return 0;
}
/*
1. 사다리 구성 : 2차원배열에 가로줄 위치면 표기
2. 사다리 체크(i -> i를 가는지)
3. 가로선 추가

solution
1. depth가 깊으면 queue로 돌리는걸 추천.
2. 2차원 배열에 가로줄 check
*/