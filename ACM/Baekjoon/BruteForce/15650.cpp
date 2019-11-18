/*
	No	: 15650(BJO)
	Type	: BruteForce
	Desc	: 순서 고려, 무한루프 check
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
	}

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			if (idx == 0) {
				visit[i] = true;
				var[idx] = i + 1;
				go(n, m, idx + 1);
				var[idx] = 0;
				visit[i] = false;
			}
			else if (var[idx - 1] < i+1) {
				visit[i] = true;
				var[idx] = i + 1;
				go(n, m, idx + 1);
				var[idx] = 0;
				visit[i] = false;
			}
			else
				continue;
		}
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

