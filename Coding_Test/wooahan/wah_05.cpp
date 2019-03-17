#include<iostream>
#include<string>
#include<vector>
using namespace std;
//clear
int solution(int number) {
	
	int answer = 0;
	int num = 1;
	int ten[] = { 1,10,100,1000,10000 };
	int size_m;

	for (int i = 4; i>=0 ; i--) {
		if (number / ten[i] != 0) {
			size_m = i;
			break;
		}
	}
	for (int i = 1; i <= number; i++) {

		string a = to_string(i);
		for (int j = 0; j < a.length(); j++) {
			if ((int)a[j] % 3 == 0 ) {
				if (a[j] != '0') {
					answer++;
				}
			}				
		}
	}
	

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cry;
	cin >> cry;


	int a = solution(cry);
	cout << a;
	system("pause");
	return 0;

}