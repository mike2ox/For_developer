/*
*	author : mike2ox
*	BOJ : 11022
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
using namespace std;

int T;
int a, b;
int ApB;

int main() {

	ios_base::sync_with_stdio("false");

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		ApB = a + b;
		cout << "Case #" << i + 1 << ": "
			<< a << " + " << b << " = " << ApB << '\n';
	}

	system("pause");
	return 0;
}