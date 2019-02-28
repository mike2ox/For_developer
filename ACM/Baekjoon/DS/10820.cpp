/*
*	author : mike2ox
*	BOJ : 10820
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
using namespace std;

int upper, lower;
int num, blank;

int main() {

	ios_base::sync_with_stdio(false);

	string str;

	while (getline(cin, str)) {
		//init
		upper = 0; lower = 0;
		num = 0; blank = 0;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ')
				blank++;
			else if (str[i] >= 'a' && str[i] <= 'z')
				lower++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				upper++;
			else if (str[i] >= '0' && str[i] <= '9')
				num++;
		}
		
		cout << lower << ' ' << upper << ' ' << num << ' ' << blank << '\n';

	}

	system("pause");
	return 0;
}
/*
	ASCII�� ����� ���� ���� ����
	getline�� �˾ƾ� space���������ϰ� line�� �Է��� �����ü� ����
*/