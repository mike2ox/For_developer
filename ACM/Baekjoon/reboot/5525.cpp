// BJO no. 5525 IOIOI, mike2ox(2020)
#include<iostream>
#include<string>
using namespace std;
int n;
int sSize;
string m,pn="I";

void checkS() {
	int ret = 0;

	for (int i = 0; i < m.size()-n*2; ++i) {
		if (m[i] == 'I') {
			int cCnt = n;
			for (int j = i; j < m.size(); j += 2) {
				i = j;

				if (m[j + 1] == 'O' && m[j + 2] == 'I') {
					cCnt--;
				}
				else
					break;

				if (cCnt <= 0) {
					ret++;
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