// BJO no. 6603 로또 , mike2ox(2020)
// 메모이제이션 X, 백트래킹(DFS)를 활용
#include<iostream>
#include<vector>
using namespace std;

int k, s[13];
bool visit[13];
vector<int> v;

void go(int pre, int cnt) {
	if (cnt == 6) {
		for (auto au : v)
			cout << au << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < k; ++i) {
		if (visit[i]||pre > s[i])
			continue;
		v.push_back(s[i]);
		visit[i] = true;
		go(s[i], cnt + 1);
		v.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	do {
		cin >> k;
		for (int i = 0; i < k; i++)
			cin >> s[i];

		go(0, 0);
		cout << '\n';

		for (int i = 0; i < k; i++) {
			s[i] = 0;
		}
		
	} while (k != 0);

	return 0;
}