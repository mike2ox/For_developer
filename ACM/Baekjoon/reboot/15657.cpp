// BJO no. 15657, mike2ox(2020)
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int seqInput[9];
int seqOutput[9];

void go(int cur, int cnt) {
	if (m == cnt) {
		for (int j = 0; j < m; ++j)
			cout << seqOutput[j] << ' ';
		cout << '\n';
		return;
	}
	for (int j = cur; j < n; ++j) {
		if (seqInput[j] >= seqOutput[cur]) {
			seqOutput[cnt] = seqInput[j];
			go(j, cnt+1);
			seqOutput[cnt] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> seqInput[i];

	sort(seqInput, seqInput+n);

	for (int i = 0; i < n; ++i) {
		seqOutput[0] = seqInput[i];
		go(0,1);
		seqOutput[0] = 0;
	}

	return 0;
}