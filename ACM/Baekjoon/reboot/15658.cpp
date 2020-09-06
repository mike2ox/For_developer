// BJO no.10971 mike2ox(2020)
// 외판원 순회
// 완탐(50분) -> dp 적용해야함
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>
using namespace std;

vector<vector<int>> tsp;
vector<bool> visit;
int n;
int answer = INT_MAX;

// 완탐(dfs) O(n!) -> dp로 바꿔야함
void go(int start, int pre_idx, int cnt, int cost)
{
	if (cnt == visit.size())
	{
		if (tsp[pre_idx][start] > 0 && cost + tsp[pre_idx][start] < answer)
			answer = cost + tsp[pre_idx][start];
		return;
	}

	for (int next_idx = 0; next_idx < n; ++next_idx)
	{
		if (visit[next_idx])
			continue;
		if (tsp[pre_idx][next_idx] == 0)
			continue;
		visit[next_idx] = true;
		go(start, next_idx, cnt + 1, cost + tsp[pre_idx][next_idx]);
		visit[next_idx] = false;
	}
}

int solution(int n)
{
	for (int i = 0; i < n; ++i)
	{
		visit.clear();
		visit.resize(n, false);

		visit[i] = true;
		go(i, i, 1, 0);
		visit[i] = false;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n;
	tsp.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> tsp[i][j];
	}

	// n <= 10이라서 완탐이 가능
	cout << solution(n);
	return 0;
}
