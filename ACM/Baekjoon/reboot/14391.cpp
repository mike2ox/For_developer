// BJO no. 14391, mike2ox(2020)
#include<iostream>
using namespace std;

#define DIFF 48

int n, m;
bool visit[5][5];
char papers[5][5];

void go() {
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> papers[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			go();
		}
	}

	return 0;
}