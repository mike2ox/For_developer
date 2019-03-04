/*
*	author : mike2ox
*	BOJ : 3190
*	descript : https://www.acmicpc.net/problem/3190
*	type : 삼성기출
*	hint :
*/
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

int dir;
int N, K, L;

int map[102][102];
// 위, 오른, 아래, 좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<pair<int, int>> snake;

// 방향 전환 함수
void turning(int ti) {
	if (ti == 'L')
		dir = (dir - 1 < 0) ? 3 : dir - 1;
	else
		dir = (dir + 1 > 3) ? 0 : dir + 1;
}
int main() {

	queue<pair<int, int>> track;
	ios_base::sync_with_stdio("false");
	cin >> N >> K;

	for (int i = 0; i < K; ++i) {
		int t_x, t_y;
		cin >> t_y >> t_x;
		map[t_y][t_x] = 2;
	}
	cin >> L;
	
	while (L--) {
		int d; char c;
		cin >> d >> c;
		track.push(pair<int, int>(d, c));
	}

	map[1][1] = 1;
	snake.push_back(pair<int, int>(1, 1));
	dir = 1;		//방향

	int result_time = 0;

	while (1) {
		// 방향전환
		if (!track.empty()) {
			// 시간확인
			if (track.front().first == result_time) {
				turning(track.front().second);
				track.pop();
			}
		}
		result_time++;

		//다음 이동 지점
		int n_x = snake[snake.size() - 1].first + dx[dir];
		int n_y = snake[snake.size() - 1].second + dy[dir];

		//벽에 부딪히는 경우
		if (n_x<1 || n_y<1 || n_x>N || n_y>N)
			break;
		//몸통에 부딪히는 경우
		if (map[n_x][n_y] == 1)
			break;
		//일반 땅인 경우
		if (map[n_x][n_y] != 2) {
			map[snake[0].first][snake[0].second] = 0;	//맵에서 꼬리가 있던 부분 삭제
			snake.erase(snake.begin());					//꼬리 삭제
		}

		// 머리부분 추가
		snake.push_back(pair<int,int>(n_x, n_y));
		map[n_x][n_y] = 1;
		
	}


	cout << result_time << '\n';

	system("pause");
	return 0;
}
/*
*/