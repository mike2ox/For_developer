/*
*	author : mike2ox
*	BOJ : 10950
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio("false");

	int T;
	int a, b;

	cin >> T;

	int* c = new int[T];

	for (int i = 0;i<T;i++) {
		cin >> a >> b;
		c[i] = a + b;
		cout << c[i] << '\n';
	}
	
	delete [] c;
	return 0;
}