/*
*	author : mike2ox
*	BOJ : 11655
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
using namespace std;

#define ROT13 13

int main() {

	ios_base::sync_with_stdio(false);

	//A : 65, Z:90 a : 97 z : 122
	string str;

	getline(cin, str);
	int l_str = str.length();
	for (int i = 0; i < l_str; ++i) {
		if ('A' <= str[i] && str[i] <= 'M')
			str[i] += 13;
		else if('N' <= str[i] && str[i] <= 'Z')
			str[i] -= 13;
		else if ('a' <= str[i] && str[i] <= 'm')
			str[i] += 13;
		else if ('n' <= str[i] && str[i] <= 'z')
			str[i] -= 13;
	}
	
	cout << str << '\n';


	system("pause");
	return 0;
}
/*
	ASCII code °ª ÆÄ¾ÇÇÏ¸é µÊ
*/