// BJO no. 1759 mike2ox(2020)
// type : using dfs, Blute force
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L, C;
vector<char> result;
vector<char> password;
int flag_a, flag_b;

void dfs(int idx, int cnt) {
	if (cnt == L) {
		string ret="";
		for (int i = 0; i < result.size(); ++i)
			ret += result[i];
		if(flag_a>0&&flag_b>1)
			cout << ret << '\n';
		return;
	}

	if (idx == C - 1)
		return;

	for (int j = idx+1; j < password.size(); ++j) {

			result.push_back( password[j]);
			if (password[j] == 'a' || password[j] == 'e' || password[j] == 'i' || password[j] == 'o' || password[j] == 'u')
				flag_a++;
			else
				flag_b++;
			dfs(j, cnt + 1);
			result.pop_back();
			if (password[j] == 'a' || password[j] == 'e' || password[j] == 'i' || password[j] == 'o' || password[j] == 'u')
				flag_a--;
			else
				flag_b--;

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	string str;

	for (int i = 0; i < C; ++i) {
		char data;
		cin >> data;
		password.push_back(data);
	}

	// Á¤·Ä ÈÄ »Ì±â(pick) / »Ì°í ºñ±³
	sort(password.begin(), password.end());

	for (int i = 0;i<password.size();++i) {
		result.push_back(password[i]);
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
			flag_a++;
		else
			flag_b++;
		dfs(i, 1);
		result.pop_back();
		flag_a = flag_b = 0;
	}

	return 0;
}