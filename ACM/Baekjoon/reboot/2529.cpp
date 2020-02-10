// BJO no. 2529 mike2ox(2020)
// type : using dfs, brute force
#include<iostream>
#include<vector>
using namespace std;

int k;
double maximum;
double minimum = 1000000000;
string strmax, strmin;

bool visit[10];	//사용했는지 안했는지 확인
vector<int> values;	// 부등호 성립시 숫자를 입력되는 저장소
char inequaliy[9];	//부등호 정보

void dfs(int cnt) {
	if (cnt == k +1) {
		int tempValue=0;
		
		for (int i = 0; i < values.size() ; ++i) {
			tempValue += values[i];
			
		}
		//비교 저장
		if (tempValue > maximum) {
			maximum = tempValue;
		}
		if (tempValue < minimum) {
			minimum = tempValue;
		}
		
		return;
	}

	for (int j = 0; j < 9; ++j) {
		if (!visit[j]) {
			if ((inequaliy[cnt - 1] == '<' && values.back() < j) ||
				(inequaliy[cnt - 1] == '>' && values.back() > j)) {
				visit[j] = true;
				values.push_back(j);
				dfs(cnt + 1);
				values.pop_back();
				visit[j] = false;
			}
			else
				continue;
		}
		else
			continue;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;

	for (int i = 0; i < k; ++i)
		cin >> inequaliy[i];

	for (int j = 0; j <= k; ++j) {
		visit[j] = true;
		values.push_back(j);
		dfs(1);
		values.pop_back();
		visit[j] = false;
	}


	cout << strmax << '\n' << strmin << '\n';

	return 0;
}