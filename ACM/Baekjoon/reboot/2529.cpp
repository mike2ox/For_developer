// BJO no. 2529 mike2ox(2020)
// type : using dfs, brute force
#include<iostream>
#include<vector>
using namespace std;

int k;
char minimum[11];
char maximum[11];
double ret;
bool flag;
char inequaliy[10];	//부등호 정보
bool visit[10];	//사용했는지 안했는지 확인
vector<int> values;	// 부등호 성립시 숫자를 입력되는 저장소

void maxdfs(int pre, int cnt) {
	if (cnt > k) {
		ret = 0;
		int tens = 0;
		for (int i = 0; i < values.size(); ++i) {
			ret *= 10;
			ret += values[i];
			tens++;
		}

		for (int i = 0; i < values.size(); ++i)
			cout << values[i];
		
		flag = true;
		return;
	}

	for (int i = 9; i >=0; --i) {
		if (visit[i]||flag)	//사용한 곳 제외
			continue;
		if (inequaliy[cnt-1] == '<' && pre < i) {
			visit[i] = true;
			values.push_back(i);
			maxdfs(i, cnt + 1);
			visit[i] = false;
			values.pop_back();
		}
		else if (inequaliy[cnt-1] == '>' && pre > i) {
			visit[i] = true;
			values.push_back(i);
			maxdfs(i, cnt + 1);
			visit[i] = false;
			values.pop_back();
		}
		else {
			//cout << "check input data...\n";
		}
	}

}
void mindfs(int pre, int cnt) {
	if (cnt > k) {
		ret = 0;
		for (int i = 0; i < values.size(); ++i) {
			ret *= 10;
			ret += values[i];
		}

		for (int i = 0; i < values.size(); ++i)
			cout << values[i];

		flag = true;
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (visit[i]||flag)	//사용한 곳 제외
			continue;
		if (inequaliy[cnt-1] == '<'&&pre < i) {
			visit[i] = true;
			values.push_back(i);
			mindfs(i, cnt + 1);
			visit[i] = false;
			values.pop_back();
		}
		else if(inequaliy[cnt-1] == '>'&&pre>i) {
			visit[i] = true;
			values.push_back(i);
			mindfs(i, cnt + 1);
			visit[i] = false;
			values.pop_back();
		}
		else {
			//cout << "check input data...\n";
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;

	for (int i = 0; i < k; ++i)
		cin >> inequaliy[i];

	for (int j = 9; j >= 0; --j) {
		visit[j] = true;
		values.push_back(j);
		maxdfs(j, 1);
		values.pop_back();
		visit[j] = false;
	}
	flag = false;
	cout << '\n';

	for (int j = 0; j <= 9; ++j) {
		visit[j] = true;
		values.push_back(j);
		mindfs(j, 1);
		values.pop_back();
		visit[j] = false;
	}

	cout << '\n';
	return 0;
}