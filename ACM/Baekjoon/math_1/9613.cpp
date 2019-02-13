/*
*	author : mike2ox
*	BOJ : 9613
*	descript : https://www.acmicpc.net/problem/
*	type : math 1
*	hint :
*/
#include<iostream>
#include<math.h>

using namespace std;

int tc;
int n_val;
int gcd_map[101] = {};
long long big[101] = {};

int gcd(int pre, int next) {

	if (next == 0)
		return pre;
	else
		return gcd(next, pre%next);
}

int main() {

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> n_val;
		for (int j = 1; j <= n_val; j++) {
			cin >> gcd_map[j];
		}
		for (int j = 1; j <= n_val - 1; j++) {
			for (int k = j + 1; k <= n_val; k++)
				big[i] += gcd(gcd_map[j], gcd_map[k]);
		}
	}

	for (int i = 0; i < tc; i++)
		cout << big[i] << '\n';

	return 0;
}