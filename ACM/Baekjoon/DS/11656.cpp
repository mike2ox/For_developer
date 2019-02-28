/*
*	author : mike2ox
*	BOJ : 11656
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	string str;
	string sub_str[1000];

	cin >> str;

	int str_l = str.length();

	for (int i = 0; i < str_l; i++) {
		sub_str[i] = str.substr(i, str_l);
	}
	// 입력 파라미터 형식 주의
	sort(&sub_str[0], &sub_str[str_l]);

	for (int i = 0; i < str_l; i++) {
		cout << sub_str[i] << '\n';
	}
	

	system("pause");
	return 0;
}
/*
	입력받은 문자열의 모든 경우를
	sub 문자열들로 각각 나눠서 sort
*/