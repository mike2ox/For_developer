// BJO no. 10971, mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
int costW[11][11];
bool visit[11];
int costMin = 1000001;
// 최초 시작점, 바로직전 위치, 현재 위치, 현재위치까지의 비용
void dfs(int start, int pre, int cur,int curSum) {
	if (v.size() == n) {
		if (costW[cur][start] == 0)
			return;
		else if (costMin > curSum+costW[cur][start]) {
			costMin = curSum + costW[cur][start];
			/* cout << "#" << costMin << " : ";
			for (auto au : v)
				cout << au << ' ';
			cout << '\n';*/
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (visit[i]||costW[cur][i]==0)
			continue;
		if (curSum > costMin)
			continue;
		visit[i] = true;
		v.push_back(i);
		dfs(start, cur, i, curSum + costW[cur][i]);
		v.pop_back();
		visit[i] = false;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> costW[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		visit[i] = true;
		v.push_back(i);
		for (int j = 1; j <= n; ++j) {
			if (visit[j]||costW[i][j]==0)
				continue;
			visit[j] = true;
			v.push_back(j);
			dfs(i, i,j, costW[i][j]);
			v.pop_back();
			visit[j] = false;
		}
		v.pop_back();
		visit[i] = false;
	}
	cout << costMin << '\n';
	return 0;
}