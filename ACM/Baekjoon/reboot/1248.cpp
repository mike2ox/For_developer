// BJO no. 1248, mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

char isEqual[56];
vector<int> v;
int n;
bool flag;
// 이전 값까지의 합, 입력된 값, 입력된 위치
void go(int preSum, int value, int cnt) {
	if (v.size() == n) {
		for (auto au : v)
			cout << au << ' ';
		cout << '\n';
		flag = true;
		return;
	}

	for (int i = 0; i < n * (n + 1) / 2; ++i) {
		if (flag)
			return;
		if (isEqual[i] == '0') {
			v.push_back(-preSum);
			go(0,-preSum,cnt+1);
			v.pop_back();
		}
		else if(isEqual[i] == '+') {

		}
		else {

		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n * (n + 1) / 2; ++i) {
		cin >> isEqual[i];
	}

	for (int i = -10; i <= 10; ++i) {
		v.push_back(i);
		go(i, i, 1);
		v.pop_back();
		
	}
	
	

	return 0;
}