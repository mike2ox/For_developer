/*
	Author	: mike2ox
	No		: 2309(BJO)
	Type	: Bruteforce
	Desc	: 조합특징을 생각해 볼 것
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int height[9];
	int sum = 0;
	int sub1, sub2;
	for (int i = 0; i < 9; ++i) {
		cin >> height[i];
		sum += height[i];
	}
	sort(height, height + 9);

	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j){
			if (sum - height[i] - height[j] == 100) {
				sub1 = i;
				sub2 = j;
			}
		}	
	}
	for (int i = 0; i < 9; ++i) {
		if (i == sub1 || i == sub2)
			continue;
		cout << height[i] << '\n';
	}

	return 0;
}