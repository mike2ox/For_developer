#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	int h[1000001];
	int max_l = 0;//밧줄의 길이
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}

	//dfs(1);


	system("pause");
	return 0;

}
/*dfs문제
	가장 긴 밧줄
*/
