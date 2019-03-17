/*
*	author : mike2ox
*	BOJ : 14502
*	descript : https://www.acmicpc.net/problem/14502
*	type : �Ｚ���� : DFS + �ùķ��̼�
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int map[8][8];
int n, m;
int ret;


void bfs() {
	queue<int> que;
	int ck[8][8] = { 0, };
	int copy_map[8][8];
	int safe=0;
	
	// �湮Ȯ��
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {

			copy_map[y][x] = map[y][x];
			
			if (copy_map[y][x] == 2) {
				// int�ϳ��� x, y �� ǥ���ϱ� ����
				// TODO : pair �ᵵ ��
				que.push(y * 10 + x);
				ck[y][x] = 1;
			}
		}
	}

	//bfs ��������
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		int cur_x = cur % 10;
		int cur_y = cur / 10;

		copy_map[cur_y][cur_x] = 2;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];

			// ��� ��
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			
			// ��ĭ�̰� �湮 ������ ���
			if (ck[ny][nx] == 0 && copy_map[ny][nx] == 0) {
				ck[ny][nx] = 1;
				que.push(ny * 10 + nx);
			}
		}
	}


	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (copy_map[y][x] == 0)
				++safe;
		}
	}

	if (ret < safe)
		ret = safe;

}


void dfs(int cnt, int t_y, int t_x) {
	if (cnt == 3) {
		//�˻�
		bfs();
		return;
	}

	for (int y = t_y; y < n; ++y) {
		for (int x = t_x; x < m; ++x) {
			// ��ĭ�� ���
			if (map[y][x] == 0) {
				map[y][x] = 1;
				dfs(cnt + 1, y, x);
				map[y][x] = 0;
			}
		}
		// �ʱ�ȭ
		t_x = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> map[y][x];
		}
	}

	// count, ������ǥ
	dfs(0,0,0);

	cout << ret << '\n';

	system("pause");
	return 0;
}
/*
1. N*M
2. 0, 1, 2 : ��ĭ, ��, ���̷���
3. ������ĭ���� ��� Ȯ��
4. ��ĭ�� ������ 3�� �̻�
5. ���� �� 3���� ��������
6. ���������� �ִ� ũ�� ���
*/