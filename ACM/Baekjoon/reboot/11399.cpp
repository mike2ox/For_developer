// BJO no.11499 ATM, mike2ox(2020)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct money {
	int idx, coin;
};
int n;
vector<money> p;

bool compare(money pre, money next) {
	if (pre.coin < next.coin)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int inputData, sumMoney=0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> inputData;
		p.push_back({ i, inputData });
	}

	// 
	sort(p.begin(), p.end(), compare);

	for (int i = 0;i<p.size();++i) {
		for (int j = 0;j<=i;++j) {
			sumMoney += p[j].coin;
		}
	}
	cout << sumMoney << '\n';
	return 0;
}