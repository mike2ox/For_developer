// BJO no. 1748 mike2ox(2020)
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	double n;
	int cnt;
	int ret = 0;
	int tens = 0;

	cin >> n;
	for (double i = 1; i <= n; ++i) {
		tens = i;
		cnt = 1;
		while (tens >= 10) {
			tens /= 10;
			++cnt;
		}
		ret += cnt;
	}
	cout << ret<< '\n';
	return 0;
}