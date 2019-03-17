/*
*	author : mike2ox
*	BOJ : 14502
*	descript : https://www.acmicpc.net/problem/14502
*	type : 삼성기출 : DFS + 시뮬레이션
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int map[8][8];
int n, m;
int ret;


void bfs() {
	queue<int> que;
	int ck[8][8] = { 0, };
	int copy_map[8][8];
	int safe=0;
	
	// 방문확인
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {

			copy_map[y][x] = map[y][x];
			
			if (copy_map[y][x] == 2) {
				// int하나에 x, y 다 표현하기 위해
				// TODO : pair 써도 됨
				que.push(y * 10 + x);
				ck[y][x] = 1;
			}
		}
	}

	//bfs 종료조건
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		int cur_x = cur % 10;
		int cur_y = cur / 10;

		copy_map[cur_y][cur_x] = 2;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];

			// 경계 밖
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			
			// 빈칸이고 방문 안했을 경우
			if (ck[ny][nx] == 0 && copy_map[ny][nx] == 0) {
				ck[ny][nx] = 1;
				que.push(ny * 10 + nx);
			}
		}
	}


	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (copy_map[y][x] == 0)
				++safe;
		}
	}

	if (ret < safe)
		ret = safe;

}


void dfs(int cnt, int t_y, int t_x) {
	if (cnt == 3) {
		//검색
		bfs();
		return;
	}

	for (int y = t_y; y < n; ++y) {
		for (int x = t_x; x < m; ++x) {
			// 빈칸일 경우
			if (map[y][x] == 0) {
				map[y][x] = 1;
				dfs(cnt + 1, y, x);
				map[y][x] = 0;
			}
		}
		// 초기화
		t_x = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> map[y][x];
		}
	}

	// count, 시작좌표
	dfs(0,0,0);

	cout << ret << '\n';

	system("pause");
	return 0;
}
/*
1. N*M
2. 0, 1, 2 : 빈칸, 벽, 바이러스
3. 인접빈칸으로 모두 확산
4. 빈칸의 갯수는 3개 이상
5. 벽은 꼭 3개를 세워야함
6. 안전영역의 최대 크기 출력
*/