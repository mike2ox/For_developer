/*
*	author : mike2ox
*	BOJ : 10809
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
using namespace std;

#define SUBS_NUM 97

int main() {

	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;
	//a = 97 z =122
	int alpabet[26];

	for (int i = 0; i < 26; i++) {
		alpabet[i] = -1;
	}

	for (int i = 0; i < str.length(); i++) {
		// 알파벳 숫자
		int input = str[i] - SUBS_NUM;

		if (alpabet[input] == -1)
			alpabet[input] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpabet[i] << " ";
	}
	cout << '\n';

	system("pause");
	return 0;
}
/*
	1. 입력한 단어를 split -> ASCII에 맞게 숫자 변환
	2. 해당 위치에 입력했을 당시 인덱스를 전달
*/