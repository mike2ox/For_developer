/*
*	author : mike2ox
*	swea : 9663
*	descript : https://www.acmicpc.net/problem/9663
*	type : 경우의 수
*/
#include<iostream>
using namespace std;


int col[16];
int ret;

bool solve(int i) {
	for (int j = 0; j < i; j++) {
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}
void go(int i, int _n) {
	//갯수 도달하면
	if (i == _n)
		ret += 1;
	else {
		for (int j = 0; j < _n; ++j) {
			col[i] = j;
			if (solve(i))
				go(i + 1, _n);
		}
	}


}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	go(0, n);

	cout << ret << '\n';

	return 0;
}
/*

*/

