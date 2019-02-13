/*
*	author : mike2ox
*	BOJ : 9095
*	descript : https://www.acmicpc.net/problem/
*	type : DP 1
*	hint :
*/
#include <iostream>
using namespace std;

int n_T;		//number of test case
int dp[12] = { 0,1,2,4, };
int n;

int main() {

	cin >> n_T;

	int * dp_n = new int[n_T];

	for (int i = 0; i < n_T; i++)
		cin >> dp_n[i];

	for (int i = 0; i < n_T; i++)
		for (int j = 4; j < dp_n[i] + 1; j++)
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];

	for (int i = 0; i < n_T; i++)
		cout << dp[dp_n[i]] << '\n';


	return 0;
}