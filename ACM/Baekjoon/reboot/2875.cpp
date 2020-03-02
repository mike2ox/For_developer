// BJO no. 2875 대회 or 인턴, mike2ox(2020)
#include<iostream>
using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ret=0;

	cin >> n >> m >> k;

	ret = (n/2) > m ? m : n/2;
	n -= ret*2; m -= ret;

	if (m + n >= k)
		cout << ret << '\n';
	else {

		cout << ret - (k - m - n )/ 4 -1 << '\n';
	}

	return 0;
}