/*
*	author : mike2ox
*	BOJ :단지번호 붙이기
*	descript : https://www.acmicpc.net/problem/2667
*	type : dfs
*/
#include<iostream>
#include<queue>
using namespace std;

int map[25][25];
bool ck[25][25];

const int dy[] = { 0,0,-1,1 };
const int dx[] = {1, -1, 0, 0};

int n;
int cnt;	//각 단지내 집 수
queue<int> q; // 오름차순 단지 내 수

//좌표, 단지 수
void dfs(int _i, int _j, int ncnt) {
	//종료 조건
	// 이제 더 갈 곳이 없는 경우
	if () {
		q.push(cnt);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = _i + dy[i];
		int nx = _j + dx[i];

		//범위 밖 + 이전에 방문한 기록이 있는 경우
		if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1 || ck[ny][nx])
			continue;

		ck[ny][nx] = true;
		dfs(ny, nx, ncnt+1);
		ck[ny][nx] = false;		
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// 완전 탐색, 1이고 방문안한 경우
			if(map[i][j]&&ck[i][j])
				dfs(i,j,0);
		}
	}



	system("pause");
	return 0;
}