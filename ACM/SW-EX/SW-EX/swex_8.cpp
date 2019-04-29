/*
*	author : mike2ox
*	swex : 미생물 격리
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : 시뮬레이션
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int x;int y;
	int num;int dir;
};
// 테스트 케이스, 셀수, 격리시간, 갯수
int t, n, m, k;

const int dx[] = { 0,-1,1,0,0 };
const int dy[] = { 0,0,0,-1,1 };
vector<int> map[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;

		vector<Node> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
			//v[i].dir;
			map[v[i].x][v[i].y].push_back(i);
		}

		while (m--) {

			// 군집 삭제
			for (int i = 0; i < k; i++) {
				if (v[i].num == 0) //미생물 수가 0이면
					continue;
				map[v[i].x][v[i].y].clear(); //해당 셀 삭제
			}

			// 군집 이동
			for (int i = 0; i < k; i++) {
				if (v[i].num == 0) //미생물 수 == 0?
					continue;
				v[i].x += dx[v[i].dir];
				v[i].y += dy[v[i].dir];
				map[v[i].x][v[i].y].push_back(i);
			}

			//부딪히는 경우
			for (int i = 0; i < k; i++) {
				if (v[i].num == 0) 
					continue;

				//1. 가장자리에 닿은 경우
				if (v[i].x == 0 || v[i].y == 0 || v[i].x == n - 1 || v[i].y == n - 1) {
					v[i].num = v[i].num / 2; //미생물 1/2감소
					//방향전환
					if (v[i].dir == 1) 
						v[i].dir = 2;
					else if (v[i].dir == 2) 
						v[i].dir = 1;
					else if (v[i].dir == 3)
						v[i].dir = 4;
					else v[i].dir = 3;
				}
				//2. 여러 군집이 뭉친 경우
				else if (map[v[i].x][v[i].y].size() > 1) {
					int x = v[i].x;
					int y = v[i].y;
					int max_num = 0;
					int max_cnt = 0;
					int max_dir = 0;
					int sum = 0;

					for (int i = 0; i < map[x][y].size(); i++) {
						sum += v[map[x][y][i]].num; // 미생물 수 합
						// 최대 미생물을 가진 군집 찾기 --> 방향 확정
						if (max_num < v[map[x][y][i]].num) {
							max_num = v[map[x][y][i]].num;
							max_dir = v[map[x][y][i]].dir;
							max_cnt = map[x][y][i];
						}
						v[map[x][y][i]].num = 0;
					}
					v[max_cnt].num = sum;
					v[max_cnt].dir = max_dir;
				}
			}
		}

		//남은 미생물 계산
		int res = 0;
		for (int i = 0; i < k; i++) {
			res += v[i].num;
		}

		//맵초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].clear();
			}
		}

		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}
/*
M 시간 동안 이 미생물 군집들을 격리하였다. M시간 후 남아 있는 미생물 수의 총합?

   ① 최초 각 미생물 군집의 위치와 군집 내 미생물의 수, 이동 방향이 주어진다. 약품이 칠해진 부분에는 미생물이 배치되어 있지 않다. 이동방향은 상, 하, 좌, 우 네 방향 중 하나.

   ② 각 군집들은 1시간마다 이동방향에 있는 다음 셀로 이동.

   ③ 미생물 군집이 이동 후 약품이 칠해진 셀에 도착하면 군집 내 미생물의 절반이 죽고, 이동방향이 반대로 바뀐다.
	   미생물 수가 홀수인 경우 반으로 나누어 떨어지지 않으므로, 다음과 같이 정의한다.
	   (중요)살아남은 미생물 수 = 원래 미생물 수를 2로 나눈 후 소수점 이하를 버림 한 값
	   따라서 군집에 미생물이 한 마리 있는 경우 살아남은 미생물 수가 0이 되기 때문에, 군집이 사라지게 된다,

   ④ 이동 후 두 개 이상의 군집이 한 셀에 모이는 경우 군집들이 합쳐지게 된다.
	   합쳐 진 군집의 미생물 수는 군집들의 미생물 수의 합이며, 이동 방향은 군집들 중 미생물 수가 가장 많은 군집의 이동방향이 된다.
	   합쳐지는 군집의 미생물 수가 같은 경우는 주어지지 않으므로 고려하지 않아도 된다.

*/