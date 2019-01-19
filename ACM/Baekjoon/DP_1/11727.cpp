/*
*	author : mike2ox
*	BOJ : 11727
*	descript : https://www.acmicpc.net/problem/
*	type : DP 1
*	hint :
*/
#include <iostream>
using namespace std;
int dp[1001] = {};
int n;

int main() {
	dp[0] = 1;
	dp[1] = 1;
	cin >> n;

	for (int i = 2; i < n + 1; i++)
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;

	cout << dp[n] % 10007;
	return 0;
}