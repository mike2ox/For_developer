/*
*	author : mike2ox
*	BOJ : 16234
*	descript : https://www.acmicpc.net/problem/16234
*	type : �Ｚ ���� : �ùķ��̼� + ����Ž��
*/
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

struct xy {
	int y, x;
};

int map[50][50];
int visited[50][50] = { 0, };

int n;
//�α��� ���
int l, r;
int cnt = 0;//�α��̵�

//�����¿�
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void go(int _y, int _x, int status[][50], int idx, int& cnt, int &sum) {
	
	queue<xy> q;
	xy head;
	head.y = _y; head.x = _x;
	visited[_y][_x] = 1;

	q.push(head);

	while (!q.empty()) {
		xy cur = q.front();   q.pop();

		status[cur.y][cur.x] = idx;
		++cnt;
		sum += map[cur.y][cur.x];

		for (int dir = 0; dir < 4; ++dir) {
			xy next;
			next.y = cur.y + dy[dir];
			next.x = cur.x + dx[dir];

			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
				continue;
			}
			// �Ÿ� ���
			int delta = abs(map[cur.y][cur.x] - map[next.y][next.x]);
			if (visited[next.y][next.x] == 0 && l <= delta && delta <= r) {
				visited[next.y][next.x] = 1;
				q.push(next);
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> map[row][col];
		}
	}

	int ret = 0;
	bool update = true;

	while (update) {
		update = false;

		//�ʿ��� ���� Ȯ�ο�
		int status[50][50] = { 0, };
		int a_idx = 0;	//Ư�� ���� index
		int count[2501] = { 0, };	//����
		int sum[2501] = { 0, };		//�ջ�

		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				//
				if (status[y][x] == 0) {
					++a_idx;
					go(y, x, status, a_idx, count[a_idx], sum[a_idx]);
				}
			}
		}

		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				int  index = status[y][x];
				int avg = sum[index] / count[index];
				if (map[y][x] != avg) {
					map[y][x] = avg;
					update = true;
				}
			}
		}
		if (update) {
			++ret;
		}
	}

	cout << ret << '\n';

	return 0;
}
/*
�α� �̵��� ������ ���� ����ǰ�, �� �̻� �α� �̵��� ���� ������ ���ӵȴ�.

1. ���漱�� �����ϴ� �� ������ �α� ���̰� L�� �̻�, R�� ���϶��, �� ���� �����ϴ� ���漱�� ���� �Ϸ絿�� ����.
2. ���� ���ǿ� ���� ������ϴ� ���漱�� ��� ���ȴٸ�, �α� �̵��� �����Ѵ�.
3. ���漱�� �����־� ������ ĭ���� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ������ �����̶�� �Ѵ�.
4. ������ �̷�� �ִ� �� ĭ�� �α����� (������ �α���) / (������ �̷�� �ִ� ĭ�� ����)�� �ȴ�. ���ǻ� �Ҽ����� ������.
5. ������ ��ü�ϰ�, ��� ���漱�� �ݴ´�.
�� ������ �α����� �־����� ��, �α� �̵��� �� �� �߻��ϴ��� ���ϴ� ���α׷�

�α� �̵��� �߻��ϴ� Ƚ���� 2,000�� ���� �۰ų� ���� �Է¸� �־�����.(?)
*/