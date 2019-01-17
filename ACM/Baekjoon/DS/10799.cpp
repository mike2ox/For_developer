/*
*	author : mike2ox
*	BOJ : 10779
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<vector>
using namespace std;

int T;
char v[50] = { NULL, };

int main() {
	ios_base::sync_with_stdio("false");

	cin >> T;

	while (T--) {
		int open = 0;
		cin >> v;
		for (int i = 0; i < 50; i++) {
			if (v[i] == '(')
				open++;
			else if (v[i] == ')')
				open--;
			else
				break;
			//NOTE : 필수 조건
			if (open < 0)
				break;
		}
		if (open == 0)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		for (int j = 0; j < 50; j++)
			v[j] = NULL;
	}

	system("pause");
	return 0;
}