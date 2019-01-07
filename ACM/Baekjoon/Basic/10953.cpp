/*
*	author : mike2ox
*	BOJ : 10952
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
using namespace std;

#define ASCII_NUM  48

int T;
char ab[3];

int main() {

	ios_base::sync_with_stdio("false");


	cin >> T;

	int * ApB = new int[T];

	for (int i = 0; i < T; i++) {
		cin >> ab;
		ApB[i] = ab[0] -  ASCII_NUM + ab[2] - ASCII_NUM;
	}

	for (int i = 0; i < T; i++) {
		cout << ApB[i] << '\n';
	}

	delete[] ApB;
	return 0;
}