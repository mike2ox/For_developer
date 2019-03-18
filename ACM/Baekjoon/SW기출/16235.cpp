/*
*	author : mike2ox
*	BOJ : 16236
*	descript : https://www.acmicpc.net/problem/16236
*	type : 삼성 기출 : 시뮬레이션 + 탐색(BFS)
*/
#include<iostream>
#include<queue>
using namespace std;

struct shark
{
	int y, x;
	int time;
};

int map[20][20];

int sk_size; int sk_eat;
bool update=true;

//상하좌우
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	shark s;


	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];

			if (map[y][x] == 9) {
				//아기상어 초기위치
				sk_size = 2; sk_eat = 0;
				s.y = y; s.x = x; s.time = 0;

				map[y][x] = 0;
			}
		}
	}

	while (update) {
		
		
		int visit[20][20] = { 0, };
		visit[s.y][s.x] = 1;
		
		queue<shark> que;
		que.push(s);

		update = false;

		//
		shark temp;
		temp.y = 20; temp.time = -1;

		while (!que.empty()) {
			shark cur = que.front();
			que.pop();

			if (temp.time != -1 && temp.time < cur.time) 
				break;
			

			if (map[cur.y][cur.x] < sk_size && map[cur.y][cur.x] != 0) {
				update = true;
				if (temp.y > cur.y || (temp.y == cur.y && temp.x > cur.x)) {
					temp = cur;
				}
			}

			//전체 탐색
			for (int dir = 0; dir < 4; ++dir) {
				shark nsk;
				nsk.y = cur.y + dy[dir];
				nsk.x = cur.x + dx[dir];
				nsk.time = cur.time + 1;

				//경계밖
				if (nsk.y < 0 || nsk.y >= n || nsk.x < 0 || nsk.x >= n) {
					continue;
				}

				//방문 안했고 크기가 더 큰경우
				if (visit[nsk.y][nsk.x] == 0 && sk_size >= map[nsk.y][nsk.x]) {
					visit[nsk.y][nsk.x] = 1;
					que.push(nsk);
				}
			}
		}


		//방문했는지 확인
		if (update) {
			s = temp;
			++sk_eat;
			if (sk_eat == sk_size) {
				++sk_size;
				sk_eat = 0;
			}
			map[s.y][s.x] = 0;
		}
	}

	cout << s.time << '\n';

	system("pause");
	return 0;
}
/*
아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

1. 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
2. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
3. 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
	- 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최소값이다.
	- 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

상어가 물고기를 먹은 시간
*/