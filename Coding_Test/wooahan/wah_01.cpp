#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> solution(int money) {
	vector<int> answer;
	int mm[] = { 50000,10000,5000,1000,500,100,50,10,1 };
	while (money != 0) {
		for (int i = 0; i < 9; ++i) {
			//int charge = money;
			int num = money / mm[i];
			money = money % mm[i];

			answer.push_back(num);
		}
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int money;
	cin >> money;

	system("pause");
	return 0;

}
