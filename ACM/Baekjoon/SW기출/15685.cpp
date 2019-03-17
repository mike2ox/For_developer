/*
*	author : mike2ox
*	BOJ : 15685
*	descript : https://www.acmicpc.net/problem/15685
*	type : 삼성 기출 : 시뮬레이션
*/

#include<iostream>
#include<vector>
using namespace std;

int n;
int x, y, d, g;

int end_x; int end_y;

//크기가 100×100인 격자 위에 드래곤 커브가 N개
int map[102][102] = { 0, };

// →,↑, ←,↓	
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1 , 0, -1, 0};

vector<int> dragon;

void go(vector<int>& dragon) {
	int size = (int)dragon.size();

	for (int s = size - 1; s >= 0; --s) {
		// 저장된 방향에 맞게 회전
		int dir = (dragon[s] + 1) % 4;
		end_y = end_y + dy[dir];
		end_x = end_x + dx[dir];

		//if (y < 0 || y >100 || x < 0 || x>100)
		//	continue;
		// 0세대 위치
		map[end_y][end_x] = 1;

		dragon.push_back(dir);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> x >> y >> d >> g;

		end_x = x; end_y = y;

		// 초기화
		dragon.clear();

		// 0세대 드래곤 커브
		end_y = y + dy[d];
		end_x = x + dx[d];
		
		// 0세대 위치
		map[end_y][end_x] = 1;

		dragon.push_back(d);

		for (int i = 0; i < g; ++i)
			go(dragon);
	}

	//for (int i = 0; i < 50; i++) {
	//	for (int j = 0; j < 50; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	int cnt = 0;
	for (int c_y = 0; c_y <= 100; ++c_y) {
		for (int c_x = 0; c_x <= 100; ++c_x) {

			// 사각형 완성
			if (map[c_y][c_x] == 1 && map[c_y+1][c_x] == 1 && map[c_y][c_x+1] == 1 && map[c_y+1][c_x+1] == 1)
				cnt++;
		}

	}
		

	cout << cnt << '\n';

	system("pause");
	return 0;
}
//좌표 평면의 x축은 → 방향, y축은 ↓ 방향
//K(K > 1)세대 드래곤 커브는 K - 1세대 드래곤 커브를 끝 점을 기준으로 90도 시계 방향 회전 시킨 다음,
//그것을 끝 점에 붙인 것이다.
//크기가 100×100인 격자 위에 드래곤 커브가 N개
//크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수를 구하는 프로그램
//격자의 좌표는 (x, y)로 나타내며, 0 ≤ x ≤ 100, 0 ≤ y ≤ 100만 유효한 좌표
