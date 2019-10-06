#include <iostream>
using namespace std;

int map[51][51];
int cnt=0; // 로봇청소기가 청소하는 칸의 개수

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

const int pre_dx[] = { 1,0,-1,0 };
const int pre_dy[] = { 0,-1,0,1 };


void dfs(int x, int y, int dir){

	if (map[x][y] == 1) 
		return;

	// 빈 칸이면 청소한다.
	if (map[x][y] == 0)	{
		map[x][y] = 2;
		cnt++;
	}

	for (int k = 0; k < 4; k++)	{
		// 북(0) -> 서(3), 동(1) -> 북(0), 남(2) -> 동(1), 서(3) -> 남(2)
		int next_dir;

		if (dir - 1 < 0)
			next_dir = 3;
		else
			next_dir = dir - 1;

		int next_x = x + dx[next_dir];
		int next_y = y + dy[next_dir];

		
		if (map[next_x][next_y] == 0)		{
			dfs(next_x, next_y, next_dir);
			return;
		}
		else
			dir = next_dir;
	}
	// 검사 끝

	// 네 방향 모두 청소했거나 벽이면 방향을 유지한채로 후진한다.
	int next_x = x + pre_dx[dir], next_y = y + pre_dy[dir];

	dfs(next_x, next_y, dir);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int n, m; 
	// 좌표, 처음 바라보는 방향
	int r, c, d;

	cin >> n >> m;

	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	dfs(r, c, d);

	cout << cnt << "\n";

	return 0;
}