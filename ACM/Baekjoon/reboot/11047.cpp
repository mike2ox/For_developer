// BJO no. 11047 µ¿Àü0, mike2ox(2020)
#include<iostream>
using namespace std;
int n, k;
int * values;
bool flag;
int minimum=100000000;

void go(int start, int cnt) {
	if (cnt > minimum)
		return;
	else if (k==0) {
		minimum = cnt;
		//flag = true;
		return;
	}

	for (int i = start; i >= 0; --i) {
		if (values[i] <= k) {
			int tmp = k / values[i];
			k %= values[i];
			go(i, cnt + tmp);
		}
	}

}

int main() {
	cin >> n >> k;
	values = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> values[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		if (values[i] <= k){
			int tmp = k / values[i];
			k %= values[i];
			go(i,tmp);
		}
		else if (flag)
			break;
	}
	cout << minimum << '\n';

	return 0;
}