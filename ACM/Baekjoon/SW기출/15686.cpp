/*
*	author : mike2ox
*	BOJ : 15686
*	descript : https://www.acmicpc.net/problem/15686
*	type : �Ｚ ���� : bfs
*/
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

int map[52][52] = { 0, };
int n, m, home=0;	//�� ũ��, �ִ� ġŲ��

int dist=1;	
int result = 0;//����

//�����¿�
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void bfs(queue<pair<int, int>>& chick) {

	int ck_size = chick.size();

	while (!chick.empty()) {
		
		pair<int, int> xy = chick.front();
		
		chick.pop();

		ck_size--;

		for (int i = 0; i < 4; ++i) {
			int ny = xy.first + dy[i];
			int nx = xy.second + dx[i];

			//��� ���� ���
			if (ny > n || ny < 1 || nx < 1 || nx>n)
				continue;
			//ġŲ�� ���
			if (map[ny][nx] == 2)
				continue;
			//���� ���
			if (map[ny][nx] == 1) {

				result += dist;
				home--;
				if (!home)//���� 0�� �� ���
					return;
			}
			//�߰�
			chick.push(make_pair(ny, nx));
		}
		if (!ck_size) {
			ck_size = chick.size();
			dist++;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	queue<pair<int, int>> chik;	//ġŲ�� ����Ʈ

	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 1)
				home++;
			else if (map[y][x] == 2) {
				chik.push(make_pair(y, x));
			}

		}
	}

	bfs(chik);
	
	cout << result << '\n';

	return 0;
}
/*
ũ�Ⱑ N��N. ���ô� 1��1ũ��

������ �� ĭ�� �� ĭ, ġŲ��, �� �� �ϳ�
������ ĭ�� (r, c), r�� c�� �Ǵ� ���������� r��° ĭ, ���ʿ������� c��° ĭ�� �ǹ��Ѵ�. 
r�� c�� 1���� �����Ѵ�.

ġŲ �Ÿ��� ���� ���� ����� ġŲ�� ������ �Ÿ��̴�. 
��, ġŲ �Ÿ��� ���� �������� ��������, ������ ���� ġŲ �Ÿ��� ������ �ִ�. 
������ ġŲ �Ÿ��� ��� ���� ġŲ �Ÿ��� ���̴�.

������ �� ĭ (r1, c1)�� (r2, c2) ������ �Ÿ��� |r1-r2| + |c1-c2|�� ���Ѵ�.

0�� �� ĭ, 1�� ��, 2�� ġŲ���̴�.

ġŲ���� ������ �ִ� M��
������ ġŲ �Ÿ��� ���� �۰� ���� ���ϴ� ���α׷�
*/