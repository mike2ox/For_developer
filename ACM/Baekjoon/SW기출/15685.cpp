/*
*	author : mike2ox
*	BOJ : 15685
*	descript : https://www.acmicpc.net/problem/15685
*	type : �Ｚ ���� : �ùķ��̼�
*/

#include<iostream>
#include<vector>
using namespace std;

bool map[101][101];
int n, x, y, d, g;
int cnt=0;
const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };

vector<int> dragon;

int getdir(int tdir) {
	switch (tdir)
	{
	case 0:
	case 1:
	case 2:
		tdir = tdir + 1;
		break;
	case 3:
		tdir = 0;
		break;
	}
	return tdir;
}

void go(int tx, int ty, int td,int tg) {
	dragon.clear();
	dragon.push_back(td);
	
	while (tg--) {
		for (int i = dragon.size() - 1; i >= 0; --i) {
			dragon.push_back(getdir(dragon[i]));
		}
	}
	map[ty][tx] = true;
	for (vector<int>::iterator itr = dragon.begin(); itr != dragon.end(); ++itr) {
		switch (*itr)
		{
		case 0:
			tx++;
			break;
		case 1:
			ty--;
			break;
		case 2:
			tx--;
			break;
		case 3:
			ty++;
			break;
		}
		if (tx >= 0 && tx <= 100 && ty >= 0 && ty <= 100)
			map[ty][tx] = true;
		else
			continue;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> d >> g;
		go(x, y, d, g);
	}
	
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			if (map[i][j]&& map[i+1][j]&& map[i][j+1]&& map[i+1][j+1])
				cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
//��ǥ ����� x���� �� ����, y���� �� ����
//K(K > 1)���� �巡�� Ŀ��� K - 1���� �巡�� Ŀ�긦 �� ���� �������� 90�� �ð� ���� ȸ�� ��Ų ����,
//�װ��� �� ���� ���� ���̴�.
//ũ�Ⱑ 100��100�� ���� ���� �巡�� Ŀ�갡 N��
//ũ�Ⱑ 1��1�� ���簢���� �� �������� ��� �巡�� Ŀ���� �Ϻ��� ���簢���� ������ ���ϴ� ���α׷�
//������ ��ǥ�� (x, y)�� ��Ÿ����, 0 �� x �� 100, 0 �� y �� 100�� ��ȿ�� ��ǥ
