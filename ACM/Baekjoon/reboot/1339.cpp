// BJO no. 1339 단어수학, mike2ox(2020)
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
int strLength[10];
int maxLns;
char str[10][9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}
	cout << atoi(str[1]) << " " << atoi(str[0]);

	return 0;
}