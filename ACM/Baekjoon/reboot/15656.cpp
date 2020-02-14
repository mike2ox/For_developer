// BJO no. 15656 mike2ox(2020)
// sort -> dfs, no visit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v, v2;
void dfs(int cnt) {
	if (cnt == m) {
		for (auto au : v2) {
			cout << au << ' ';
		}
		cout << '\n';
		return;
	}
	for (int j = 0; j < v.size(); ++j) {
		v2.push_back(v[j]);
		dfs(cnt + 1);
		v2.pop_back();
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
		v2.push_back(v[i]);
		dfs(1);
		v2.pop_back();
	}

	return 0;
}