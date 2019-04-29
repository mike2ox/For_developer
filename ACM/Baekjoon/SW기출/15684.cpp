/*
*	author : mike2ox
*	BOJ : 15684
*	descript : https://www.acmicpc.net/problem/15684
*	type : �Ｚ ���� :dfs
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
1. ��ٸ� ���� : 2�����迭�� ������ ��ġ�� ǥ��
2. ��ٸ� üũ(i -> i�� ������)
3. ���μ� �߰�

solution
1. depth�� ������ queue�� �����°� ��õ.
2. 2���� �迭�� ������ check
*/