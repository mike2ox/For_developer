// BJO no. 10972 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n;
bool visit[10001];
vector<int> v;
vector<int> ret;
bool nextFlag;
bool exitFlag;

void dfs(int value, int cnt) {
	if (n == cnt) {
		if(!nextFlag)
			nextFlag = true;
		else if (!exitFlag && n == ret.size()) {
			exitFlag = true;
			for (auto au : ret)
				cout << au << ' ';
			cout << '\n';
		}
		return;
	}
	if (exitFlag)
		return;

	for (int j = 1; j <= n; ++j) {
		if (visit[j])
			continue;
		if (v[cnt] == j) {
			visit[j] = true;
			ret.push_back(j);
			dfs(j, cnt+1);
			ret.pop_back();
			visit[j] = false;
		}
		else if (nextFlag) {
			visit[j] = true;
			ret.push_back(j);
			dfs(j, cnt + 1);
			ret.pop_back();
			visit[j] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		v.push_back(value);
	}

	dfs(0, 0);

	if (!exitFlag)
		cout << "-1\n";

	return 0;
}