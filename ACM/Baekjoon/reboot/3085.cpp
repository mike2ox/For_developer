// BJO no. 3085 mike2ox(2020)
// 사탕 게임
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;

unsigned int cnt_max_candy;

// 스왑안한 라인 중에 더 긴라인이 있을 수 있음 -> 완탐
void check(vector<vector<char>> bomboni) {
	vector<vector<int>> col_cnt(n, vector<int>(n, 0));
	vector<vector<int>> row_cnt(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0 || bomboni[i][j - 1] != bomboni[i][j])
				col_cnt[i][j] = 1;
			else if (bomboni[i][j - 1] == bomboni[i][j])
				col_cnt[i][j] = col_cnt[i][j - 1] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || bomboni[i - 1][j] != bomboni[i][j])
				row_cnt[i][j] = 1;
			else if (bomboni[i - 1][j] == bomboni[i][j])
				row_cnt[i][j] = row_cnt[i - 1][j] + 1;
		}
	}

	int max_value = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (col_cnt[i][j] > max_value)
				max_value = col_cnt[i][j];
			if (row_cnt[i][j] > max_value)
				max_value = row_cnt[i][j];
		}
	}

	if (max_value > cnt_max_candy)
		cnt_max_candy = max_value;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n;

	vector<vector<char>> bomboni(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> bomboni[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(bomboni[i][j], bomboni[i][j + 1]);
				check(bomboni);
				swap(bomboni[i][j], bomboni[i][j + 1]);
			}

			if (i + 1 < n) {
				swap(bomboni[i][j], bomboni[i + 1][j]);
				check(bomboni);
				swap(bomboni[i][j], bomboni[i + 1][j]);
			}
		}
	}

	cout << cnt_max_candy << '\n';

	return 0;
}
