/*
*	author : mike2ox
*	BOJ : 1463
*	descript : https://www.acmicpc.net/problem/
*	type : DP 1
*	hint : 
*/
#include <iostream>
using namespace std;

#define MIN(a,b) (a < b ? a : b)
int N;
int dp[1000001] = { 0,0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 2; i < N + 1; i++) {
		dp[i] = dp[i - 1] + 1;	// 3rd rule

		if (i % 2 == 0)	//2nd
			dp[i] = MIN(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = MIN(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];

	system("pause");

	return 0;
}