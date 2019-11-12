/*
	No	: 6064(BJO)
	Type	: BruteForce
	Desc	: big-o, 건너뛰기
*/
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y;
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;

		bool flag = false;
		x -= 1;
		y -= 1;

		for (int k = x; k < (n*m); k += m) {
			if (k%n == y) {
				cout << k + 1 << '\n';
				flag = !flag;
				break;
			}
		}

		if (!flag) {
			cout << -1 << '\n';
		}
	}

	return 0;
}

