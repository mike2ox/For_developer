/*
*	author : mike2ox
*	BOJ : 15685
*	descript : https://www.acmicpc.net/problem/15685
*	type : �Ｚ ���� : �ùķ��̼�
*/

#include<iostream>
#include<vector>
using namespace std;

int n;
int x, y, d, g;

int end_x; int end_y;

//ũ�Ⱑ 100��100�� ���� ���� �巡�� Ŀ�갡 N��
int map[102][102] = { 0, };

// ��,��, ��,��	
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1 , 0, -1, 0};

vector<int> dragon;

void go(vector<int>& dragon) {
	int size = (int)dragon.size();

	for (int s = size - 1; s >= 0; --s) {
		// ����� ���⿡ �°� ȸ��
		int dir = (dragon[s] + 1) % 4;
		end_y = end_y + dy[dir];
		end_x = end_x + dx[dir];

		//if (y < 0 || y >100 || x < 0 || x>100)
		//	continue;
		// 0���� ��ġ
		map[end_y][end_x] = 1;

		dragon.push_back(dir);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> x >> y >> d >> g;

		end_x = x; end_y = y;

		// �ʱ�ȭ
		dragon.clear();

		// 0���� �巡�� Ŀ��
		end_y = y + dy[d];
		end_x = x + dx[d];
		
		// 0���� ��ġ
		map[end_y][end_x] = 1;

		dragon.push_back(d);

		for (int i = 0; i < g; ++i)
			go(dragon);
	}

	//for (int i = 0; i < 50; i++) {
	//	for (int j = 0; j < 50; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	int cnt = 0;
	for (int c_y = 0; c_y <= 100; ++c_y) {
		for (int c_x = 0; c_x <= 100; ++c_x) {

			// �簢�� �ϼ�
			if (map[c_y][c_x] == 1 && map[c_y+1][c_x] == 1 && map[c_y][c_x+1] == 1 && map[c_y+1][c_x+1] == 1)
				cnt++;
		}

	}
		

	cout << cnt << '\n';

	system("pause");
	return 0;
}
//��ǥ ����� x���� �� ����, y���� �� ����
//K(K > 1)���� �巡�� Ŀ��� K - 1���� �巡�� Ŀ�긦 �� ���� �������� 90�� �ð� ���� ȸ�� ��Ų ����,
//�װ��� �� ���� ���� ���̴�.
//ũ�Ⱑ 100��100�� ���� ���� �巡�� Ŀ�갡 N��
//ũ�Ⱑ 1��1�� ���簢���� �� �������� ��� �巡�� Ŀ���� �Ϻ��� ���簢���� ������ ���ϴ� ���α׷�
//������ ��ǥ�� (x, y)�� ��Ÿ����, 0 �� x �� 100, 0 �� y �� 100�� ��ȿ�� ��ǥ
