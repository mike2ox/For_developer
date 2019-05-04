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

	//정점, 간선, 출발 위치
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
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 

정점 번호는 1번부터 N번까지이다.

정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다
*/