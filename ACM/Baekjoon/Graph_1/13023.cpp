/*
	Author	: mike2ox
	No	: 13023(BJO)
	Type	: Graph
	Think	: DFS? visit
*/
#include<iostream>
using namespace std;

int n,m;
int result;
bool relation[2000][2000];
bool visit[2000][2000];

void dfs(int cnt, int start, int end) {
	if (cnt == 4) {
		result = 1;
		return;
	}

	for (int s = 0; s < n; ++s) {
		if (!visit[end][s] && relation[end][s]) {
			visit[end][s] = visit[s][end]= true;
			dfs(cnt + 1, end, s);
			visit[end][s] = visit[s][end] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	int idx_s = 0; int idx_e = 0;
	cin >> n >> m;
	for (int t = 0; t < m; ++t) {
		cin >> idx_s >> idx_e;
		relation[idx_s][idx_e] = relation[idx_e][idx_s] = true;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;

			else if (relation[i][j]) {
				visit[i][j] = visit[j][i] = true;
				dfs(1, i, j);
				visit[i][j] = visit[j][i] = false;
			}

			if (result) {
				cout << result << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}
