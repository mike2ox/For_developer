/*
*	author : mike2ox
*	swea : 1227
*	descript : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD
*	type : 1. bfs, 2. dfs
*/
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int tc;
bool flag;
char map[100][100];
bool visit[100][100];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1, -1,0,0 };

void dfs(pair<int, int> p) {
	if (map[p.first][p.second] == '3') {
		flag = true;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int ny = p.first + dy[i];
		int nx = p.second + dx[i];

		//������ //�湮�� �� //�� pass
		if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100)	continue;
		if (visit[ny][nx])	continue;
		if (map[ny][nx] == '1')	continue;

		visit[ny][nx] = true;
		dfs({ ny, nx });
		visit[ny][nx] = false;
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> tc) {

		pair<int, int> start;
		flag = false;

		//�Է� + ������ ������ Ȯ�� + visit �ʱ�ȭ
		for (int y = 0; y < 100; ++y) {
			for (int x = 0; x < 100; ++x) {
				cin >> map[y][x];
				if (map[y][x] == '2')
					start = make_pair(y, x);
				visit[y][x] = false;
			}
		}
		visit[start.first][start.second] = true;
		dfs(start);

		if (flag)
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

