#include<iostream>
#include<string>
#include<vector>
using namespace std;

//clear
string solution(string cryptogram) {
	string answer = "";
	vector<char> k;
	k.push_back(cryptogram[0]);
	for (int i = 1; i < cryptogram.length(); ++i) {
		if (k.back() == cryptogram[i]) {
			if (cryptogram[i] == cryptogram[i + 1])
				continue;
			k.pop_back();
		}
		else
			k.push_back(cryptogram[i]);
	}
	for (vector<char>::iterator itr = k.begin(); itr != k.end(); ++itr)
		answer += *itr;
	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string cry;
	cin >> cry;


	string a = solution(cry);
	cout << a;
	system("pause");
	return 0;

}
