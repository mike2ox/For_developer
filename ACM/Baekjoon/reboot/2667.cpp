// BOJ no. 2667, mike2ox(2020)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
char address[26][26];
bool visit[25][25];
vector<int> answer;
int n, ret;

void dfs(int y, int x) {
	// visited or no value
	if (address[y][x]=='0') {
		return;
	}

	visit[y][x] = true;
	++ret;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// go over
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (!visit[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n;

	// insert home info
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> address[y][x];
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			// no visit + value == 1
			if (!visit[y][x] && address[y][x] != '0') {
				ret = 0;
				dfs(y, x);
				answer.push_back(ret);
			}
		}
	}

	sort(answer.begin(), answer.end());

	// print vector 'answer'
	cout << answer.size() << '\n';
	for (vector<int>::iterator itr = answer.begin(); itr != answer.end(); ++itr)
		cout << *itr << '\n';

	system("pause");
	return 0;
}