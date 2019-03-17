/*
*	author : mike2ox
*	BOJ : 4963
*	descript : https://www.acmicpc.net/problem/4963
*	type : 알고리즘 기초 : dfs
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

const int dy[] = {0,0,-1,1,1,-1,1,-1};
const int dx[] = {-1,1,0,0,1,1,-1,-1};

int map[51][51] = { 0, };
int h, w, cnt;

void dfs(int y, int x) {
	
	map[y][x] = 0;

	//
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (nx < 0 || nx >= w || ny < 0 || ny >= h) 
			continue;
		if (map[ny][nx])
			dfs(ny, nx);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		cnt = 0;
		cin >> w >> h;

		//end 
		if (w == 0 && h == 0)
			break;

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> map[y][x];
			}
		}
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[y][x]) {
					dfs(y, x);
					cnt++;
				}
			}
		}


		cout << cnt << '\n';

	}

	system("pause");
	return 0;
}
//가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.
//두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다.
//지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다.
//각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다.
//w와 h는 50보다 작거나 같은 양의 정수이다.
//둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다
//입력의 마지막 줄에는 0이 두 개 주어진다.
//각 테스트 케이스에 대해서, 섬의 개수를 출력한다.