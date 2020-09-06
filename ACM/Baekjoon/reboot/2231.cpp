// BJO no. 2231 mike2ox(2020)
// 분해합
// BF
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n;

	for (int num = 1; num < 1000000; num++) {
		int decomposition = 0;
		int copy_num = num;

		while (copy_num % 10) {
			decomposition += copy_num % 10;
			copy_num /= 10;
		}

		if (num + decomposition == n) {
			cout << num;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
