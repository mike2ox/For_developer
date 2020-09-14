// BJO no. 1018 mike2ox(2020)
// 체스판 다시 칠하기
// BF
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; //가로, 세로
	cin >> m >> n;

	vector<vector<char>> chess(m + 1, vector<char>(n + 1));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> chess[i][j];
		}
	}

	char start = '\0';
	int min_paint = INT_MAX;

	for (int i = 0; i <= m - 8; i++)
	{
		for (int j = 0; j <= n - 8; j++)
		{
			start = chess[i][j];
			int cnt_paint = 0;

			// 체스판 확인
			for (int r = i; r < i + 8; r++)
			{
				for (int c = j; c < j + 8; c++)
				{
					if (((r - i + c - j) & 1) && start == chess[r][c])
						cnt_paint++;
					if (!((r - i + c - j) & 1) && start != chess[r][c])
						cnt_paint++;
				}
			}

			// 2가치 경우(W시작, B시작)에서 칠하는 횟수 비교
			if (cnt_paint > 64 - cnt_paint)
				cnt_paint = 64 - cnt_paint;
			if (cnt_paint < min_paint)
				min_paint = cnt_paint;
		}
	}

	cout << min_paint << '\n';

	return 0;
}
