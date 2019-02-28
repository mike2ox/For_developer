/*
*	author : mike2ox
*	BOJ : 11720
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
#include<string>
using namespace std;

#define ASCII_NUM 48

int N;
int sum = 0;
char c;

int main() {

	ios_base::sync_with_stdio("false");
	cin >> N;
	
	for (int i = 0;i<N;i++) {
		cin >> c;
		sum += c - ASCII_NUM;
	}
	cout << sum << '\n';
	system("pause");
	return 0;
}