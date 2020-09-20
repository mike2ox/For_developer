// 연구소 3(90m)
// BFS + 시뮬레이션
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;

int n, m;

enum CONTENTS
{
	EMPTY_ROOM,
	WALL,
	VIRUS
};

struct virus_info
{
	int y;
	int x;
	int time;
};

int min_time = INT_MAX;

vector<vector<int>> lab;
vector<vector<int>> candi_lab;
vector<vector<bool>> visit;
vector<virus_info> viruses;

int bfs(vector<int> &comb)
{
	queue<virus_info> q;
	int ret = 0;
	visit.clear();
	candi_lab.clear();
	candi_lab.resize(n, vector<int>(n, -1));
	visit.resize(n, vector<bool>(n));

	const int dy[] = {0, 0, -1, 1};
	const int dx[] = {1, -1, 0, 0};

	for (int i = 0; i < comb.size(); i++)
	{
		if (comb[i])
			q.push(viruses[i]);
		else
			candi_lab[viruses[i].y][viruses[i].x] = -2; //비활성화 바이러스 위치
	}

	while (!q.empty())
	{
		virus_info qf = q.front();
		q.pop();

		if (visit[qf.y][qf.x])
			continue;
		candi_lab[qf.y][qf.x] = qf.time;
		visit[qf.y][qf.x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = qf.y + dy[i];
			int nx = qf.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (visit[ny][nx])
				continue;
			if (lab[ny][nx] == 1)
				continue;

			q.push({ny, nx, qf.time + 1});
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (candi_lab[i][j] == -1)
			{
				if (lab[i][j] != WALL)
					return -1;
				else
					continue;
			}
			if (candi_lab[i][j] > ret && lab[i][j] != VIRUS)
				ret = candi_lab[i][j];
		}
	}

	return ret;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	lab.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == VIRUS)
				viruses.push_back({i, j, 0});
		}
	}

	vector<int> comb(viruses.size(), 0);
	for (int i = 0; i < m; i++)
		comb[i] = 1;

	do
	{
		int candi_time = bfs(comb);
		if (candi_time == -1)
			continue;
		else if (candi_time < min_time)
			min_time = candi_time;

	} while (prev_permutation(comb.begin(), comb.end()));

	if (min_time == INT_MAX)
		min_time = -1;
	cout << min_time << '\n';
	system("pause");
	return 0;
}
