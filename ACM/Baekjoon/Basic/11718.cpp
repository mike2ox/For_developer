/*
*	author : mike2ox
*	BOJ : 11718
*	descript : https://www.acmicpc.net/problem/
*	type : I/O
*/
#include<iostream>
#include<string>
using namespace std;

string str;

int main() {

	ios_base::sync_with_stdio("false");

	while (getline(cin, str)) {
		// 제일 앞 문자가 space일 때도 나가도록 함
		if (str.front() == ' ' || str == "")
			break;
		cout << str << '\n';
	}

	system("pause");
	return 0;
}