// BJO no.10973 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;
int n;
int* v, *ret;
bool visit[10001];
bool preFlag;
bool exitFlag;

void dfs(int cnt) {
	if (cnt==n) {
		if (!preFlag)
			preFlag = true;
		else if (!exitFlag) {
			exitFlag = true;

			for (int i = 0; i < n; ++i)
				cout << ret[i] << ' ';
			cout << '\n';
		}
		return;
	}

	// 역순으로 값을 대입하는게 중요
	for (int j = n; j >= 1; --j) {
		if (visit[j])
			continue;
		else if (exitFlag)
			return;

		if (v[cnt] == j||preFlag) {
			visit[j] = true;
			ret[cnt] = j;
			dfs(cnt + 1);
			ret[cnt] = 0;
			visit[j] = false;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int inputData;

	cin >> n;
	v =ret = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> inputData;
		v[i] = inputData;
	}

	dfs(0);

	if (!exitFlag)
		cout << "-1\n";

	delete v, ret;
	return 0;
}