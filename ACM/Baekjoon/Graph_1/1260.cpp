/*
*	author : mike2ox
*	BOJ : 1260
*	descript : https://www.acmicpc.net/problem/
*	type : graph 1
*	hint :
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, v;
bool num[1001];
bool copy_num[1001];
bool map[1001][1001];

void dfs(int n_v) {
	if (!copy_num[n_v])
		return;
	cout << n_v << " ";
	copy_num[n_v] = false;

	for (int i = 1; i < 1001; ++i) {
		if (map[n_v][i]&& copy_num[i]) {
			map[n_v][i] = map[i][n_v] = false;
			dfs(i);
			map[n_v][i] = map[i][n_v] = true;
		}
	}

	return;
}

void bfs() {
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int tv = q.front();
		if(copy_num[tv])
			cout << tv << " ";
		copy_num[tv] = false;
		q.pop();

		for (int i = 1; i < 1001; ++i) {
			if (map[tv][i]) {
				q.push(i);
				map[tv][i] = map[i][tv] = false;
			}
		}
	}
	cout << "\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	//����, ����, ��� ��ġ
	cin >> n >> m >> v;

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		copy_num[a] = copy_num[b] = num[a]=num[b]=true;
		map[a][b] = map[b][a] = true;
	}
	dfs(v);
	cout << '\n';
	for (int i = 1; i <= 1000; ++i)
		copy_num[i] = num[i];
	bfs();

	system("pause");
	return 0;
}
/*
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. 

���� ��ȣ�� 1������ N�������̴�.

������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����
*/