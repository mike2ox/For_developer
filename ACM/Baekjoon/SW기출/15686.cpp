/*
*	author : mike2ox
*	BOJ : 15686
*	descript : https://www.acmicpc.net/problem/15686
*	type : 삼성 기출 : bfs
*/
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

int map[52][52] = { 0, };
int n, m, home=0;	//맵 크기, 최대 치킨집

int dist=1;	
int result = 0;//정답

//상하좌우
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void bfs(queue<pair<int, int>>& chick) {

	int ck_size = chick.size();

	while (!chick.empty()) {
		
		pair<int, int> xy = chick.front();
		
		chick.pop();

		ck_size--;

		for (int i = 0; i < 4; ++i) {
			int ny = xy.first + dy[i];
			int nx = xy.second + dx[i];

			//경계 밖일 경우
			if (ny > n || ny < 1 || nx < 1 || nx>n)
				continue;
			//치킨일 경우
			if (map[ny][nx] == 2)
				continue;
			//집일 경우
			if (map[ny][nx] == 1) {

				result += dist;
				home--;
				if (!home)//집이 0개 일 경우
					return;
			}
			//추가
			chick.push(make_pair(ny, nx));
		}
		if (!ck_size) {
			ck_size = chick.size();
			dist++;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	queue<pair<int, int>> chik;	//치킨집 리스트

	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 1)
				home++;
			else if (map[y][x] == 2) {
				chik.push(make_pair(y, x));
			}

		}
	}

	bfs(chik);
	
	cout << result << '\n';

	return 0;
}
/*
크기가 N×N. 도시는 1×1크기

도시의 각 칸은 빈 칸, 치킨집, 집 중 하나
도시의 칸은 (r, c), r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. 
r과 c는 1부터 시작한다.

치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 
즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 
도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

0은 빈 칸, 1은 집, 2는 치킨집이다.

치킨집의 개수는 최대 M개
도시의 치킨 거리가 가장 작게 될지 구하는 프로그램
*/