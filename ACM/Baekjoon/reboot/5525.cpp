// BJO no. 5525 IOIOI, mike2ox(2020)
#include<iostream>
#include<string>
using namespace std;
int n;
int sSize;
string m,pn="I";

void checkS() {
	int ret = 0;

	for (int i = 0; i < m.size() - pn.size(); ++i) {
		if (m[i] == 'I') {
			bool flag = false;
			int nCnt = n;

			for (int j = i + 1; j <= m.size() - pn.size(); j += 2) {
				if (m[j] == 'O' && m[j + 1] == 'I') {
					--nCnt;
				}
				else {
					break;
				}
				if (nCnt == 0)
					flag = true;
				if (flag) {
					ret++;
					i = j;
				}
			}
		}
	}

	cout << ret << '\n';
}
int main() {
	
	//input data
	cin >> n >> sSize;
	cin >> m;

	// check s
	checkS();

	return 0;
}