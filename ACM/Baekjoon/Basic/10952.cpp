/*
*	author : mike2ox
*	BOJ : 10952
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio("false");

	int a, b;

	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		cout << a + b << '\n';
	}

	system("pause");
	return 0;
}