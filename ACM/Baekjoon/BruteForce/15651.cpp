/*
	No	: 15651(BJO)
	Type	: BruteForce
	Desc	: 중복 고려, 무한 루프 check
*/
#include<iostream>
using namespace std;
bool visit[8];
int var[8];
void go(int n, int m, int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << var[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		visit[i] = true;
		var[idx] = i + 1;
		go(n, m, idx + 1);
		var[idx] = 0;
		visit[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	go(n, m, 0);

	return 0;
}

