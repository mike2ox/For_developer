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
	// �Է� �Ķ���� ���� ����
	sort(&sub_str[0], &sub_str[str_l]);

	for (int i = 0; i < str_l; i++) {
		cout << sub_str[i] << '\n';
	}
	

	system("pause");
	return 0;
}
/*
	�Է¹��� ���ڿ��� ��� ��츦
	sub ���ڿ���� ���� ������ sort
*/