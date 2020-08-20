// 컬러링북(1h)
// 탐색 : DFS(stack)
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<vector<bool>> visit;

void dfs(int m, int n, int y, int x, vector<vector<int>> picture, int &size_area)
{
	int dy[] = {0, 0, 1, -1};
	int dx[] = {1, -1, 0, 0};
	int area = 0;
	using pii = pair<int, int>;
	stack<pii> stk;
	stk.push({y, x});

	while (!stk.empty())
	{
		pii sf = stk.top();
		if (visit[sf.first][sf.second])
		{
			stk.pop();
			continue;
		}
		visit[sf.first][sf.second] = true;
		stk.pop();
		area++;

		for (int i = 0; i < 4; ++i)
		{
			int ny = sf.first + dy[i];
			int nx = sf.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;
			if (picture[ny][nx] != picture[sf.first][sf.second] || visit[ny][nx])
				continue;

			stk.push({ny, nx});
		}
	}

	if (area > size_area)
		size_area = area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	vector<int> answer(2, 0);
	visit.clear();
	visit.resize(100, vector<bool>(100, false));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (picture[i][j] && !visit[i][j])
			{
				dfs(m, n, i, j, picture, answer[1]);
				answer[0]++;
			}
		}
	}

	return answer;
}
