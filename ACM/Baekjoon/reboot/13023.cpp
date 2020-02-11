// BJO no. 13023 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool visit[2001];
bool rel[2001][2001];
vector<int> rel2[2001];
int being;
void dfs(int vertex, int cnt) {
	if (cnt == 5) {
		being = 1;
		return;
	}
	/*
	for (int i = 0; i < n; ++i) {
		if (being == 1)
			return;

		//방문 안했고 관계가 있는 경우
		if (!visit[i] && rel[vertex][i]) {
			visit[i] = true;
			rel[vertex][i] = false;
			dfs(i, cnt + 1);
			rel[vertex][i] = true;
			visit[i] = false;
		}
	}*/
	for (auto itr = rel2[vertex].begin(); itr != rel2[vertex].end(); ++itr) {
		if (being == 1)
			return;
		if (!visit[*itr]) {
			visit[*itr] = true;
			dfs(*itr, cnt + 1);
			visit[*itr] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		rel[a][b] = rel[b][a] = true;
		rel2[a].push_back(b);
		rel2[b].push_back(a);
	}

	//	시작정점 설정
	for (int j = 0; j < n; ++j) {
		if (being == 0) {
			visit[j] = true;
			dfs(j, 1);	
			visit[j] = false;
		}
		else
			break;
	}

	cout << being << '\n';

	return 0;
}