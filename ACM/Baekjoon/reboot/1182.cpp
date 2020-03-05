// BJO no.1182 부분수열의 합 , mike2ox(2020)
#include<iostream>
using namespace std;

int n, s, cnt;
int* arr;

void go(int idx, int sum) {
	if (sum == s) {
		cnt++;
	}
	if (idx == n)
		return;

	for (int i = idx; i < n; ++i) {
		go(i + 1, sum + arr[i]);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for(int i=0;i<n;++i)
		go(i+1, arr[i]);

	cout << cnt << '\n';

	return 0;
}