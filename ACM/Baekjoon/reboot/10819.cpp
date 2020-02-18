// BJO no. 10819, mike2ox(2020)
#include<iostream>
using namespace std;
int n;
int arr[9];
int diffArr[9];
bool visit[9];
int maximum = 0;

void dfs(int curIdx, int cnt) {
	if (cnt == n) {
		int tmpMaximun = 0;
		for (int j = 0; j < n-1; ++j) {
			tmpMaximun += abs(diffArr[j] - diffArr[j + 1]);
		}
		if (tmpMaximun > maximum)
			maximum = tmpMaximun;
		return;
	}

	for (int j = 0; j < n; ++j) {
		if (visit[j])
			continue;
		visit[j] = true;
		diffArr[cnt] = arr[j];
		dfs(j, cnt + 1);
		diffArr[cnt] = 0;
		visit[j] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		visit[i] = true;
		diffArr[0] = arr[i];
		dfs(i,1);
		diffArr[0] = 0;
		visit[i] = false;
	}

	cout << maximum << '\n';
	return 0;
}