// BOJ 17406 배열 돌리기 (70m / non-clear)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>
using namespace std;

int n, m;
int k;

struct rot {
	int r;
	int c;
	int s;
};

vector<rot> origin_rotates;

void printarr(vector<vector<int>> candi) {
	for (auto a : candi) {
		for (int i : a) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int solution(vector<vector<int>> arr, vector<rot> rotates) {
	vector<vector<int>> candi = arr;

	for (auto rot_info : rotates) {
		for (int s = rot_info.s; s > 0; s /= 2) {
			// 상단
			for (int i = rot_info.c - s; i <= rot_info.c + s; i++) {
				if (i == rot_info.c + s)
					candi[rot_info.r - s + 1][i] = arr[rot_info.r - s][i];
				else
					candi[rot_info.r - s][i + 1] = arr[rot_info.r - s][i];
			}
			// 우측
			for (int j = rot_info.r - s; j <= rot_info.r + s; j++) {
				if (j == rot_info.r + s)
					candi[j][rot_info.c + s - 1] = arr[j][rot_info.c + s];
				else
					candi[j + 1][rot_info.c + s] = arr[j][rot_info.c + s];
			}
			// 하단
			for (int i = rot_info.c + s; i >= rot_info.c - s; i--) {
				if (i == rot_info.c - s)
					candi[rot_info.r + s - 1][i] = arr[rot_info.r + s][i];
				else
					candi[rot_info.r + s][i - 1] = arr[rot_info.r + s][i];
			}
			// 좌측
			for (int j = rot_info.r + s; j >= rot_info.r - s; j--) {
				if (j == rot_info.r - s)
					candi[j][rot_info.c - s + 1] = arr[j][rot_info.c - s];
				else
					candi[j - 1][rot_info.c - s] = arr[j][rot_info.c - s];
			}
		}
		// printarr(candi);
		arr = candi;
	}

	int ret = INT_MAX;

	// 행 합산 후 비교
	for (auto line : candi) {
		int sum = 0;
		for (int v : line)
			sum += v;
		if (sum && sum < ret)
			ret = sum;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	vector<vector<int>> arr;
	arr.resize(n + 1, vector<int>(m + 1));
	origin_rotates.resize(k);

	// 자료 입력
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < k; i++)
		cin >> origin_rotates[i].r >> origin_rotates[i].c >> origin_rotates[i].s;

	// 순서 선정 위한 배열
	vector<int> order(k, 0);
	for (int i = 0; i < 5; i++)
		order[i] = i;

	int answer = INT_MAX;

	do {
		vector<rot> tmp;
		for (int i : order)
			tmp.push_back(origin_rotates[i]);

		int ret = solution(arr, tmp);

		if (ret < answer)
			answer = ret;
	} while (next_permutation(order.begin(), order.end()));

	cout << answer << '\n';

	system("pause");
	return 0;
}
