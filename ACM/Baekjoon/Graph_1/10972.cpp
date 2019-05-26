/*
*	author : mike2ox
*	BOJ : 10972
*	descript : https://www.acmicpc.net/problem/10972
*/
#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];
int n, n_p;
int input;
//입력한 값보다는 크고 다른 값들보다는 작도록 구현
void go() {
	int idx = -1;

	for (int i = n - 1; i > 0; --i) {
		if (arr[i - 1] < arr[i]) {
			idx = i;
			break;
		}
	}

	if (idx == -1) {
		cout << idx << '\n';
		return;
	}

	for (int i = n - 1; i >= idx; --i) {
		if (arr[idx - 1] < arr[i]) {
			swap(arr[idx - 1], arr[i]);
			break;
		}
	}

	sort(arr + idx, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	go();

	return 0;
}
/*

*/

