/*
*	author : mike2ox
*	BOJ : 11052
*	descript : https://www.acmicpc.net/problem/
*	type : DP 1
*	hint :
*/
#include <iostream>
using namespace std;
#define MAX(a,b) a>b ? a:b

int dp[1001] = {};
int P_n[1001] = {};
int n;

int main() {

	cin >> n;
	for (int i = 1; i < n + 1; i++)
		cin >> P_n[i];

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i <= j)
				dp[j] = MAX(dp[j], dp[j - i] + P_n[i]);
		}
	}

	cout << dp[n] << "\n";
	return 0;
}