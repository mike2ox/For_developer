// BOJ no. 1260, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, v;
bool graph[1001][1001];
bool visit[1001];

void initValue() {
	for (int i = 1; i <= n; ++i)
		visit[i] = false;
}
void dfs(int start) {
	visit[start] = true;
	cout << start << ' ';
	for (int i = 1; i <= n; ++i) {
		if (!visit[i] && graph[start][i]) {
			dfs(i);
		}
	}
}
void bfs(int start) {
	queue<int> q;
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		int nv = q.front();
		q.pop();

		for (int i = 1; i <= n; ++i) {
			if (!visit[i] && graph[nv][i]) {
				visit[i] = true;
				q.push(i);
			}
		}
		cout << nv << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		int preV, nextV;
		cin >> preV >> nextV;
		graph[preV][nextV] = graph[nextV][preV] = true;
	}
	dfs(v);
	initValue();
	cout << '\n';
	bfs(v);
	cout << '\n';

	system("pause");
	return 0;
}