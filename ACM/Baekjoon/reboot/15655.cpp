// BJO no. 15655 mike2ox(2020)
// sort -> dfs+compare
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
bool visit[8];
vector<int> v, v2;

void dfs(int cnt) {
	if (cnt == m) {
		for (auto au : v2)
			cout << au << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < v.size(); ++i) {
		if (visit[i])
			continue;
		if (v[i] < v2.back())
			continue;
		visit[i] = true;
		v2.push_back(v[i]);
		dfs(cnt + 1);
		v2.pop_back();
		visit[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		v.push_back(value);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) {
		visit[i] = true;
		v2.push_back(v[i]);
		dfs(1);
		v2.pop_back();
		visit[i] = false;
	}

	return 0;
}