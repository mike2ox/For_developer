/*
*	author : mike2ox
*	swea : 1227
*	descript : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD
*	type : 1. bfs, 2. dfs
*/
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int tc;
bool pass;
char map[100][100];
bool visit[100][100];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1, -1,0,0 };

bool bfs(pair<int, int> start) {

	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		visit[cy][cx] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;
			if (map[ny][nx] == '1')	continue;
			if (visit[ny][nx])	continue;

			if (map[ny][nx] == '3') return true;

			visit[ny][nx] == true;
			q.push({ ny, nx });

		}
	}

	return false;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> tc) {

		pair<int, int> start, goal;

		//�Է� + ������ ������ Ȯ�� + visit �ʱ�ȭ
		for (int y = 0; y < 100; ++y) {
			for (int x = 0; x < 100; ++x) {
				cin >> map[y][x];
				if (map[y][x] == '2') {
					start = make_pair(y, x);
				}
				else if (map[y][x] == '3')
					goal = make_pair(y, x);
				visit[y][x] = false;
			}
		}

		if (bfs(start))
			cout << "#" << tc << " " << 1 << '\n';
		else
			cout << "#" << tc << " " << 0 << '\n';

	}

	return 0;
}
/*
���� �»�ܿ� �ִ� ĭ�� (0, 0), ���ι����� x ����, ���ι����� y ����

�̷��� �������� (1, 1)�̰� �������� (13, 13)�̴�.

�־��� �̷��� ��������κ��� ������������ �� �� �ִ� ���� �ִ��� �Ǵ�

input

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �׽�Ʈ���̽��� ��ȣ�� �־�����, �ٷ� ���� �ٿ� �׽�Ʈ ���̽��� �־�����.

�� 10���� �׽�Ʈ ���̽��� �־�����.

�׽�Ʈ ���̽����� 1�� ���� ��Ÿ���� 0�� ��, 2�� �����, 3�� �������� ��Ÿ����.
output
#��ȣ�� �Բ� �׽�Ʈ ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� ���� ���� ���θ� 1 �Ǵ� 0���� ǥ���Ѵ� (1 - ������, 0 - �������� ����).

*/

