// BJO 9997. 폰트(65m)
// bitmask, 재귀/dfs
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int n;
int answer;
vector<int> words;
vector<bool> visit;
const int all_pass = (1 << 26) - 1;

int str_to_bitmask(string str)
{
	int ret = 0;

	for (char c : str)
		ret |= (1 << (c - 'a'));
	return ret;
}

// 블로그 참조
void go(int idx, int value)
{
	if (idx == n - 1)
	{
		if (value == all_pass)
			answer++;
		return;
	}

	go(idx + 1, value | words[idx + 1]);
	go(idx + 1, value);
}

// my code
void dfs2(int prev, int check)
{
	if (check == all_pass)
		answer++;
	if (prev == n - 1)
		return;
	for (int i = prev; i < n; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		dfs2(i, check | words[i]);
		visit[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string str;
	words.resize(n);
	visit.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		words[i] = str_to_bitmask(str);
	}

	for (int i = 0; i < n; i++)
	{
		visit[i] = true;
		dfs2(i, words[i]);
		visit[i] = false;
	}

	cout << answer << '\n';
	system("pause");
	return 0;
}
