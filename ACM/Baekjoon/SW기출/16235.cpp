/*
*	author : mike2ox
*	BOJ : 16236
*	descript : https://www.acmicpc.net/problem/16236
*	type : �Ｚ ���� : �ùķ��̼� + Ž��(BFS)
*/
#include<iostream>
#include<queue>
using namespace std;

struct shark
{
	int y, x;
	int time;
};

int map[20][20];

int sk_size; int sk_eat;
bool update=true;

//�����¿�
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	shark s;


	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];

			if (map[y][x] == 9) {
				//�Ʊ��� �ʱ���ġ
				sk_size = 2; sk_eat = 0;
				s.y = y; s.x = x; s.time = 0;

				map[y][x] = 0;
			}
		}
	}

	while (update) {
		
		
		int visit[20][20] = { 0, };
		visit[s.y][s.x] = 1;
		
		queue<shark> que;
		que.push(s);

		update = false;

		//
		shark temp;
		temp.y = 20; temp.time = -1;

		while (!que.empty()) {
			shark cur = que.front();
			que.pop();

			if (temp.time != -1 && temp.time < cur.time) 
				break;
			

			if (map[cur.y][cur.x] < sk_size && map[cur.y][cur.x] != 0) {
				update = true;
				if (temp.y > cur.y || (temp.y == cur.y && temp.x > cur.x)) {
					temp = cur;
				}
			}

			//��ü Ž��
			for (int dir = 0; dir < 4; ++dir) {
				shark nsk;
				nsk.y = cur.y + dy[dir];
				nsk.x = cur.x + dx[dir];
				nsk.time = cur.time + 1;

				//����
				if (nsk.y < 0 || nsk.y >= n || nsk.x < 0 || nsk.x >= n) {
					continue;
				}

				//�湮 ���߰� ũ�Ⱑ �� ū���
				if (visit[nsk.y][nsk.x] == 0 && sk_size >= map[nsk.y][nsk.x]) {
					visit[nsk.y][nsk.x] = 1;
					que.push(nsk);
				}
			}
		}


		//�湮�ߴ��� Ȯ��
		if (update) {
			s = temp;
			++sk_eat;
			if (sk_eat == sk_size) {
				++sk_size;
				sk_eat = 0;
			}
			map[s.y][s.x] = 0;
		}
	}

	cout << s.time << '\n';

	system("pause");
	return 0;
}
/*
�Ʊ� �� ���� �̵����� �����ϴ� ����� �Ʒ��� ����.

1. �� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
2. ���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
3. ���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
	- �Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּҰ��̴�.
	- �Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.

�� ����⸦ ���� �ð�
*/