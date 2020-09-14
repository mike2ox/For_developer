// BJO no. 4796 mike2ox(2020)
// 캠핑
// greedy
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int l, p, v;
	int case_num = 1;

	while (cin >> l >> p >> v)
	{
		if ((l + p + v) == 0)
			return 0;

		int result = (v / p) * l;

		if ((v % p) > l)
			result += l;
		else
			result += (v % p);

		cout << "Case " << case_num << ": " << result << '\n';
		case_num++;
	}

	return 0;
}
