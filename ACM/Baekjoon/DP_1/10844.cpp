/*
*	author : mike2ox
*	BOJ : 10844
*	descript : https://www.acmicpc.net/problem/
*	type : DP 1
*	hint :
*/
#include <iostream>
using namespace std;

int DIV = 1000000000;					//
int arr[10][101] = { 0, };		// array of stair
int n;
int sum = 0;

int main() {

	cin >> n;

	for (int i = 0; i < 10; i++)
		arr[i][1] = 1;			//init

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				arr[j][i] = arr[j + 1][i - 1];
			else if (j == 9)
				arr[j][i] = arr[j - 1][i - 1];
			else
				arr[j][i] = (arr[j - 1][i - 1] + arr[j + 1][i - 1]) % DIV;
		}
	}

	for (int i = 0; i < 9; i++)
		sum = (sum + arr[i][n]) % DIV;

	cout << sum;

	return 0;
}