// BOJ no. 16947, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
bool flag;
bool visit[3001];
int dist[3001];
vector<int> subway[3001];
vector<int> xStation;

// 순환선 찾기
void dfs(int curV, int preV) {
	if (visit[curV]) {
		flag = true;
		xStation.push_back(curV);
		return;
	}
	visit[curV] = true;
	for (auto au : subway[curV]) {
		if (au== preV)
			continue;

		dfs(au, curV);

		if (flag) {
			if (curV == xStation.front()) {
				flag = false;
				return;
			}
			xStation.push_back(curV);
			return;
		} 
	}
	visit[curV] = false;
}
void bfs() {
	queue<int> q;
	int cnt = 0;

	for (auto au : xStation) {
		q.push(au);
	}
	
	int qSize = q.size();

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
			++cnt;
		}

		int curV = q.front();
		visit[curV] = true;
		dist[curV] = cnt;
		q.pop();
		--qSize;
		
		for (auto au2 : subway[curV]) {
			//방문한 곳 제외
			if (visit[au2])
				continue;
			q.push(au2);
		}

	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int preVertex, postVertex;
		cin >> preVertex >> postVertex;
		subway[preVertex].push_back(postVertex);
		subway[postVertex].push_back(preVertex);
	}

	dfs(1, 1);
	bfs();
	for (int i = 1; i <= n; ++i) {
		cout << dist[i] << " ";
	}
	
	return 0;
}