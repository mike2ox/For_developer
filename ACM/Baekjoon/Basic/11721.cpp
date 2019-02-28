/*
*	author : mike2ox
*	BOJ : 11721
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
#include<string>
using namespace std;

#define ASCII_NUM 48

string s;

int main() {

	ios_base::sync_with_stdio("false");
	
	cin >> s;
	int l_s = s.length();

	for (int i = 1; i <= l_s; i++) {
		if (i % 10 != 0)
			cout << s[i - 1];
		else
			cout << s[i - 1]<< '\n';
	}
	cout << '\n';
	system("pause");
	return 0;
}