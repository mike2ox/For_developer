// BJO no. 10448 mike2ox(2020)
// 유레카 이론
// BF
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tc;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> trienum(46, 0);
	vector<int> sum_trienum(3200, 0);
	for (int i = 1; i <= 45; i++)
		trienum[i] = (i * (i + 1)) / 2;

	for (int i = 1; i <= 45; i++)
		for (int j = 1; j <= 45; j++)
			for (int k = 1; k <= 45; k++)
				sum_trienum[trienum[i] + trienum[j] + trienum[k]] = 1;

	cin >> tc;

	while (tc--)
	{
		int num;
		int cnt = 0;
		cin >> num;

		if (sum_trienum[num])
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
