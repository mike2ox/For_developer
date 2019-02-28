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
	ASCII를 고려해 문자 범위 설정
	getline을 알아야 space공간무시하고 line별 입력을 가져올수 있음
*/