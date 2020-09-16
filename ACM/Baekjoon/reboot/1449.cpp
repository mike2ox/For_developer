// BJO no. 1449 mike2ox(2020)
// 수리공 항승
// greedy
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, l;

	cin >> n >> l;

	vector<int> pipe(n, 0);

	for (int i = 0; i < n; i++)
		cin >> pipe[i];

	sort(pipe.begin(), pipe.end());

	int tape_start = pipe[0];
	int cnt_tape = 1;

	for (int i = 1; i < pipe.size(); i++)
	{
		if (pipe[i] - tape_start <= l - 1)
			continue;
		else
		{
			cnt_tape++;
			tape_start = pipe[i];
		}
	}

	cout << cnt_tape << '\n';

	return 0;
}
