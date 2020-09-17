// 삼각 달팽이(30분)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;
using pii = pair<int, int>; // 좌표

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> snail(n, vector<int>(n, 0));
	int value = 1;
	pii pos = {0 , 0};

	while (value < n * (n + 1) / 2) {
		while (pos.first + 1 < n && snail[pos.first + 1][pos.second] == 0) {
			snail[pos.first++][pos.second] = value++;
		}

		while (pos.second + 1 < n && snail[pos.first][pos.second + 1] == 0) {
			snail[pos.first][pos.second++] = value++;
		}

		while (snail[pos.first - 1][pos.second - 1] == 0) {
			snail[pos.first--][pos.second--] = value++;
		}
	}

	snail[pos.first][pos.second] = value;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			answer.push_back(snail[i][j]);
		}
	}

	return answer;
}

int main() {
	vector<int> a = solution(4);
	vector<int> b = solution(5);
	return 0;
}
