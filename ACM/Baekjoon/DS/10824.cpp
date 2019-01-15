/*
*	author : mike2ox
*	BOJ : 10824
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	
	string NNum[4];

	for (int i = 0; i < 4; i++)
		cin >> NNum[i];

	NNum[0] += NNum[1];
	NNum[2] += NNum[3];
	
	long long ab = stoll(NNum[0]);
	long long cd = stoll(NNum[2]);

	cout << ab + cd << '\n';

	system("pause");
	return 0;
}
/*
	�Է����� ������ a,b,c,d�� ũ�⸦ �����
	���� ũ�� �����ؾ���.
*/