// BJO no. 2098 mike2ox(2020)
// 외판원 순회
// dp + bit masking
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define LIMIT_COST 1000000000

int n;
vector<vector<int>> tsp;
vector<vector<int>> cost;

int go(int now_pos, int route) {
	// 메모이제이션
	int &ret = cost[now_pos][route];
	if (ret != 0) return ret;

	if (route == (1 << n) - 1) {
		if (tsp[now_pos][0] != 0)
			return tsp[now_pos][0];
		return LIMIT_COST;
	}

	ret = LIMIT_COST;

	for (int next_pos = 0; next_pos < n; next_pos++) {
		if (route & (1 << next_pos) || tsp[now_pos][next_pos] == 0)
			continue;
		ret = min(ret, tsp[now_pos][next_pos] + go(next_pos, route | (1 << next_pos)));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	tsp.clear();
	cost.clear();
	tsp.resize(n, vector<int>(n, 0));
	cost.resize(n, vector<int>((1 << n), 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> tsp[i][j];
	}

	cout << go(0, 1) << '\n';
	return 0;
}
