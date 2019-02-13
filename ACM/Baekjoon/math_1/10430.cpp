/*
*	author : mike2ox
*	BOJ : 10430
*	descript : https://www.acmicpc.net/problem/
*	type : math 1
*	hint :
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a, b, c;

int main() {
	cin >> a >> b >> c;
	cout << (a + b) % c << '\n';
	cout << (a%c + b % c) % c << '\n';
	cout << (a*b) % c << '\n';
	cout << (a%c*b%c) % c << '\n';

	return 0;
}
