/*
*	author : mike2ox
*	BOJ : 10216
*	descript : https://www.acmicpc.net/problem/10216
*	type :
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n;
struct node {
	int y, x, r;
};
node arr[3000];
bool visit[3000];
int link[3000][3000];
queue<int> q;

void init(int _n) {
	for (int i = 0; i < _n; i++) {
		visit[i] = false;
		for (int j = 0; j < _n; j++) {
			link[i][j] = 0;
		}
	}
}
void bfs() {
	int ret = 0;

	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;

	cin >> T;
	while (--T) {
		int tx, ty, tr;
		cin >> n;
		init(n);
		for (int i = 0; i < n; i++) {
			cin >> ty >> tx >> tr;
			arr[i] = node{ ty, tx, tr };
		}
		//��ġ�� �κ� Ȯ��
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				int min_y = arr[i].y - arr[j].y;
				int min_x = arr[i].x - arr[j].x;
				int sum_r = arr[i].r - arr[j].r;

				if ((min_x*min_x + min_y * min_y) <= (sum_r*sum_r))
					link[i][j] = link[j][i] = 1;
			}
		}
		bfs();
	}

	return 0;
}
/*
���� ������ �׷� ������ ���
(�߿�)
������ ��ſ��� Ai�� Aj�� ��ų� ��ġ�� �κ��� �ִٸ� 
���� i�� ���� j�� ���������� ����� �����ϴ�.
*/