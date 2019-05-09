/*
*	author : mike2ox
*	swea : 1227
*	descript : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD
*	type : 1. bfs, 2. dfs
*/
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int tc;
bool pass;
char map[100][100];
bool visit[100][100];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1, -1,0,0 };

bool bfs(pair<int, int> start) {

	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		visit[cy][cx] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;
			if (map[ny][nx] == '1')	continue;
			if (visit[ny][nx])	continue;

			if (map[ny][nx] == '3') return true;

			visit[ny][nx] == true;
			q.push({ ny, nx });

		}
	}

	return false;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> tc) {

		pair<int, int> start, goal;

		//입력 + 시작점 골인점 확인 + visit 초기화
		for (int y = 0; y < 100; ++y) {
			for (int x = 0; x < 100; ++x) {
				cin >> map[y][x];
				if (map[y][x] == '2') {
					start = make_pair(y, x);
				}
				else if (map[y][x] == '3')
					goal = make_pair(y, x);
				visit[y][x] = false;
			}
		}

		if (bfs(start))
			cout << "#" << tc << " " << 1 << '\n';
		else
			cout << "#" << tc << " " << 0 << '\n';

	}

	return 0;
}
/*
가장 좌상단에 있는 칸을 (0, 0), 가로방향을 x 방향, 세로방향을 y 방향

미로의 시작점은 (1, 1)이고 도착점은 (13, 13)이다.

주어진 미로의 출발점으로부터 도착지점까지 갈 수 있는 길이 있는지 판단

input

각 테스트 케이스의 첫 번째 줄에는 테스트케이스의 번호가 주어지며, 바로 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

테스트 케이스에서 1은 벽을 나타내며 0은 길, 2는 출발점, 3은 도착점을 나타낸다.
output
#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 도달 가능 여부를 1 또는 0으로 표시한다 (1 - 가능함, 0 - 가능하지 않음).

*/

