/*
*	author : mike2ox
*	BOJ : 11021
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
using namespace std;

#define ASCII_NUM  48

int T;
int a, b;

int main() {

	ios_base::sync_with_stdio("false");


	cin >> T;

	int* ApB = new int [T];

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		ApB[i] = a + b;
	}

	for (int i = 0; i < T; i++) {
		cout << "Case #"<< i+1<< ": "<<ApB[i] << '\n';
	}

	delete[] ApB;
	system("pause");
	return 0;
}