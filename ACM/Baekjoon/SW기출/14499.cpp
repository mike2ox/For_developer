/*
*	author : mike2ox
*	BOJ : 14499
*	descript : https://www.acmicpc.net/problem/14499
*	type : 삼성기출 : 시뮬
*/

#include<iostream>
#include<algorithm>
using namespace std;

int map[20][20];
int dice[6];

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
//시작 조건
int n, m;
int sy, sx, k;
int dir;

//참조
void move(int t_dir) {
	int t_dice[6];
	

	//5. 동서남북(1, 2, 3, 4)으로 한칸씩
	switch (t_dir)
	{
	case 0:
		t_dice[0] = dice[0];
		t_dice[5] = dice[1];
		t_dice[2] = dice[2];
		t_dice[4] = dice[3];
		t_dice[1] = dice[4];
		t_dice[3] = dice[5];
		break;
	case 1:
		t_dice[0] = dice[0];
		t_dice[4] = dice[1];
		t_dice[2] = dice[2];
		t_dice[5] = dice[3];
		t_dice[3] = dice[4];
		t_dice[1] = dice[5];
		break;
	case 2:
		t_dice[3] = dice[0];
		t_dice[0] = dice[1];
		t_dice[1] = dice[2];
		t_dice[2] = dice[3];
		t_dice[4] = dice[4];
		t_dice[5] = dice[5];
		break;
	case 3:
		t_dice[1] = dice[0];
		t_dice[2] = dice[1];
		t_dice[3] = dice[2];
		t_dice[0] = dice[3];
		t_dice[4] = dice[4];
		t_dice[5] = dice[5];
		break;
	default:
		break;
	}

	for (int i = 0; i < 6; i++) 
		dice[i] = t_dice[i];
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin >> n >> m >> sy >> sx >> k;

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cin >> map[y][x];

	for (int i = 0; i < k; i++) {
		cin >> dir;
		--dir;
		
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;

		move(dir);

		//7. 이동한 칸에 쓰여진 수가 0이면 주사위 -> 칸으로 복사
		if (map[ny][nx] == 0)
			map[ny][nx] = dice[3];
		//8. 0이 아닌 경우 칸->주사위 바닥면으로 복사, 칸은 0이 됨
		else {
			dice[3] = map[ny][nx];
			map[ny][nx] = 0;
		}

		sy = ny;
		sx = nx;

		cout << dice[1] << '\n';
	}
	
	system("pause");
	return 0;
}
/*
1. 최대 20*20 지도안에서 이동
2. 최대 1000개의 명령
3. r,c = 북쪽, 서쪽으로 부터의 위치
4. 칸에는 10이하의 자연수
5. 동서남북(1,2,3,4)으로 한칸씩
6. 처음에 주사위에는 모든 면에 0이 적혀있음
7. 이동한 칸에 쓰여진 수가 0이면 주사위 -> 칸으로 복사
8. 0이 아닌 경우 칸 -> 주사위 바닥면으로 복사, 칸은 0이 됨
*/