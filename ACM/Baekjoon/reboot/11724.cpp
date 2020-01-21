// BOJ no. 1707, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int cnt;
vector<vector<int>> graph(1001, vector<int>(1001,0));
bool visit[1001];

void dfs(int k) {
	visit[k] = true;
	for (int i = 1; i <= n; ++i) {
		if (!visit[i] && graph[k][i]==1)
			dfs(i);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int start, end;
		cin >> start >> end;
		graph[start][end]= graph[end][start] =1;
	}

	for (int j = 1; j <= n; ++j) {
		if (!visit[j]) {
			dfs(j);
			++cnt;
		}
	}
	cout << cnt << '\n';
	system("pause");
	return 0;
}