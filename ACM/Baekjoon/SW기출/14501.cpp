/*
*	author : mike2ox
*	BOJ : 14501
*	descript : https://www.acmicpc.net/problem/14501
*	type : 삼성기출 : dp or dfs
*/

//1. dp
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n, ret=0;
int t[16], p[16];
int dp[15];
/*
int solve(int day) {
	if (day > n)
		return -1000000;
	else if (day == n)
		return 0;

	int temp = dp[day];
	if (temp != -1)
		return temp;

	temp = max(solve(day + 1), solve(day + t[day]) + p[day]);
	return temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
		dp[i] = -1;
	}

	ret = solve(0);

	cout << ret << '\n';

	system("pause");
	return 0;
}*/
/*
1. 최대 이익
2. 최대 15일, Ti 최대값 5, Pi의 최대값 1000
*/

// 2. dfs

void dfs(int day, int total) {
	if (day > n)
		return;
	if (day == n) {
		ret = max(ret, total);
		return;
	}
	dfs(day + 1, total);
	dfs(day + t[day], total + p[day]);
}
int main() {

	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> t[i] >> p[i];

	dfs(1, 0);
	dfs(t[0], p[0]);
	cout << ret << '\n';

	return 0;
}