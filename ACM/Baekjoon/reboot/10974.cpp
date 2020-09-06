// BJO no.10974 mike2ox(2020)
// 모든 순열
// next_permutaion / pre_permutaion 사용법 체크
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solution(int n) {
	vector<int> all_perm(n, 0);

	for (int i = 1; i <= n; ++i)
		all_perm[i - 1] = i;

	while (true) {
		for (int nbr : all_perm)
			cout << nbr << ' ';

		if (!next_permutation(all_perm.begin(), all_perm.end()))
			break;
		else
			cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	solution(n);

	return 0;
}
