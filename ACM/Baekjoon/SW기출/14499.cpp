/*
*	author : mike2ox
*	BOJ : 14499
*	descript : https://www.acmicpc.net/problem/14499
*	type : �Ｚ���� : �ù�
*/

#include<iostream>
#include<algorithm>
using namespace std;

int map[20][20];
int dice[6];

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
//���� ����
int n, m;
int sy, sx, k;
int dir;

//����
void move(int t_dir) {
	int t_dice[6];
	

	//5. ��������(1, 2, 3, 4)���� ��ĭ��
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

		//7. �̵��� ĭ�� ������ ���� 0�̸� �ֻ��� -> ĭ���� ����
		if (map[ny][nx] == 0)
			map[ny][nx] = dice[3];
		//8. 0�� �ƴ� ��� ĭ->�ֻ��� �ٴڸ����� ����, ĭ�� 0�� ��
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
1. �ִ� 20*20 �����ȿ��� �̵�
2. �ִ� 1000���� ���
3. r,c = ����, �������� ������ ��ġ
4. ĭ���� 10������ �ڿ���
5. ��������(1,2,3,4)���� ��ĭ��
6. ó���� �ֻ������� ��� �鿡 0�� ��������
7. �̵��� ĭ�� ������ ���� 0�̸� �ֻ��� -> ĭ���� ����
8. 0�� �ƴ� ��� ĭ -> �ֻ��� �ٴڸ����� ����, ĭ�� 0�� ��
*/