/*
*	author : mike2ox
*	BOJ : 14888
*	descript : https://www.acmicpc.net/problem/14888
*	type : ªÔº∫±‚√‚ : dfs
*/
#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> p;
int max_v = -1000000000;int min_v = 1000000000;
int n;
int num[12];
int oper[5];
int ck[5];	//operator ∞πºˆ »Æ¿Œ

//√— ∞πºˆ,
void go(int tn) {

	if (tn > n - 1)
		return;
	int result = 0;
	for (int i = 1; i < 5; ++i) {
		if (ck[i]!=oper[i]) {
			ck[i]++;
			switch (i)
			{
			case 1:
				go(tn + 1);

				break;
			case 2:
				go(tn + 1);
				break;
			case 3:
				go(tn + 1);
				break;
			case 4:
				go(tn + 1);
				break;
			}		
			ck[i]--;
		}
	}
	min_v = min(min_v, result);
	max_v = max(max_v, result);
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
	
	go(1);

	cout << max_v << '\n' << min_v << '\n';
	system("pause");
	return 0;
}
