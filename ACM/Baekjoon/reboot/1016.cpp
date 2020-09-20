// 제곱ㄴㄴ수(40m)
// prime
// ref : https://chanhuiseok.github.io/posts/baek-16/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;
long long min_x, max_x;
vector<bool> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> min_x >> max_x;
	result.resize(max_x - min_x + 1);

	long long base = 2;
	int cnt_ret = max_x - min_x + 1;

	while (base <= sqrt(max_x))
	{
		long long pow_base = (base * base);
		long long share_value = min_x / pow_base;

		while (share_value * pow_base < min_x)
		{
			share_value++;
		}

		while (share_value * pow_base <= max_x)
		{
			if (!result[share_value * pow_base - min_x])
			{
				result[share_value * pow_base - min_x] = true;
				cnt_ret--;
			}
			share_value++;
		}
		base++;
	}

	cout << cnt_ret << '\n';
	return 0;
}
