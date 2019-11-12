/*
	Author	: mike2ox
	No	: 1476(BJO)
	Type	: BruteForce
	Desc	: 나머지 연산 중요
*/
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int e, s, m;
	int year = 0;
	cin >> e >> s >> m;

	while (++year) {
		// 1 ~ 15년
		if (e== year && s== year && m== year) {
			cout << year << '\n';
			break;
		}
		else if(year >= 15){ // 15년 이후
			if (year % 15 + 1 == e && year%28 +1 == s && year % 19 +1 == m) {
				cout << year+1 << '\n';
				break;
			}
		}
		if (year > 7980)
			break;
	}

	return 0;
}

