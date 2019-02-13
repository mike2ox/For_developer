/*
*	author : mike2ox
*	BOJ : 2609
*	descript : https://www.acmicpc.net/problem/
*	type : math 1
*	hint :
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a, b;
long long result;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x%y);
}

int main() {
	cin >> a >> b;
	result = gcd(a, b);

	cout << result << '\n' << (a*b * 1LL) / result << '\n';
	return 0;
}
