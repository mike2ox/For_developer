// BJO no. 1107 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n, m;
int minimum;
bool broken[10];

void go(int value) {
	vector<int> v;
	int ret=0;
	int numClick = 0;

	// 1
	int hundredDiff = abs(100 - value);

	// 2
	while (value > 0) {
		int diff = 9;
		for (int i = 0; i < 9; ++i) {
			if (!broken[i])
				diff = (diff < abs(i - value % 10)) ? diff : abs(i - value % 10);
			
		}
		value /= 10;
		++numClick;
		v.push_back(diff);
	}
	
	for (vector<int>::reverse_iterator rIter = v.rbegin();rIter != v.rend(); ++rIter) {
		ret *= 10;
		ret += *rIter;
	}
	ret += numClick;

	if (hundredDiff < ret)
		cout << hundredDiff << '\n';
	else
		cout << ret <<'\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	minimum = abs(n - 100);

	for (int i = 0; i < m; ++i) {
		int btn;
		cin >> btn;
		broken[btn] = true;
	}

	go(n);

	return 0;
}