/*
*	author : mike2ox
*	BOJ : 14888
*	descript : https://www.acmicpc.net/problem/14888
*	type : 삼성기출 : dfs
*/
#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> p;
int max_v = -1000000000; int min_v = 1000000000;
int n;
int num[12];
int oper[5];
int ck[5];	//operator 갯수 확인

//총 갯수,
void go(int tn, int plu, int sub, int mul, int div, int cur) {
	if (tn == n + 1) {
		min_v = min(min_v, cur);
		max_v = max(max_v, cur);
		return;
	}
	if (plu < oper[1])
		go(tn + 1, plu + 1, sub, mul, div, cur + num[tn]);
	if (sub < oper[2])
		go(tn + 1, plu, sub + 1, mul, div, cur - num[tn]);
	if (mul < oper[3])
		go(tn + 1, plu, sub, mul + 1, div, cur * num[tn]);
	if (div < oper[4])
		go(tn + 1, plu, sub, mul, div + 1, cur / num[tn]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i + 1];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i + 1];
	}

	//2,0,0,0,0,num[1] : 안됨. --> tn == n로 해놓으면 cur가 갱신이 안되고 1단계 전의 결과로 처리됨
	// 해결 --> tn == n+1로 해서 갱신
	go(2, 0, 0, 0, 0, num[1]);

	cout << max_v << '\n' << min_v << '\n';
	system("pause");
	return 0;
}
