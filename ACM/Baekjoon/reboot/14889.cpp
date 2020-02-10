// BJO no.14889 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n;
int ability[21][21];
bool visit[21];
vector<int> start; 
vector<int> link;

int minValue=1000000;

void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		int linkSum = 0;
		int startSum = 0;

		for (int i = 1; i <= n; ++i) {	//링크 위치
			if (visit[i])
				continue;
			link.push_back(i);
		}

		for (int i = 0; i < start.size(); ++i) {
			for (int j = 0; j < start.size(); ++j) {
				startSum += (ability[start[i]][start[j]] + ability[start[j]][start[i]]);
			}
		}
		for (int i = 0; i < link.size(); ++i) {
			for (int j = 0; j < link.size(); ++j) {
				linkSum += (ability[link[i]][link[j]] + ability[link[j]][link[i]]);
			}
		}
		if (abs(startSum - linkSum) < minValue)
			minValue = abs(startSum - linkSum);

		link.clear();
		return;
	}

	for (int j = idx; j <= n; ++j) {
		if (visit[j])
			continue;
		visit[j] = true;
		start.push_back(j);
		dfs(j, cnt + 1);
		start.pop_back();
		visit[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ability[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (n / 2 < i)
			break;

		visit[i] = true;
		start.push_back(i);
		dfs(i, 1);
		start.pop_back();
		visit[i] = false;
	}

	cout << minValue /2 << '\n';

	return 0;
}