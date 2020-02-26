// BJO no.1080 За·Д, mike2ox(2020)
#include<iostream>
using namespace std;

int n, m;
char matrixA[51][51];
char matrixB[51][51];

void flip(int row, int column) {
	for (int i=row;i<row+3;++i){
		for (int j = column; j < column + 3; ++j) {
			matrixA[i][j] = (matrixA[i][j] == '1' ? '0' : '1');
		}
	}

}
bool check() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (matrixB[i][j] != matrixA[i][j])
				return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrixA[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrixB[i][j];

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 2; ++j) {
			if (matrixA[i][j] != matrixB[i][j]) {
				++cnt;
				flip(i, j);
			}
			else
				continue;
		}
	}

	
	if (check())
		cout << cnt << '\n';
	else
		cout << -1 << '\n';
	return 0;
}