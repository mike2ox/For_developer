/*
	No	: 15652(BJO)
	Type	: BruteForce
	Desc	: 중복 고려, 비내림차순, 무한 루프 check
*/
#include<iostream>
using namespace std;
int var[9];
void go(int n, int m, int idx, int start) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << var[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; ++i) {
		var[idx] = i;
		go(n, m, idx + 1, i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	go(n, m, 0,1);

	return 0;
}

