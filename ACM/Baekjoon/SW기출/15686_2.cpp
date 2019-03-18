/*
*	author : mike2ox
*	BOJ : 15686
*	descript : https://www.acmicpc.net/problem/15686
*	type : �Ｚ ���� : bfs
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct xy {
	int y, x;
};

int n, m, type, ret;
vector<xy> house, shop, pick;//shop = n�̰� m���� �̾Ƽ� pick�� push

// �߿�! bfs
void dfs(int pos) {
	if (pick.size() == m) {

		int temp = 0;
		for (int i = 0; i < house.size(); ++i) {
			//�ּ� �Ÿ��� �����ֱ����� ū �� ����
			int min_dist = 10000000;

			//
			for (int j = 0; j < pick.size(); ++j) 
				min_dist = min(min_dist, abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
			
			temp += min_dist;
		}

		if (ret > temp) {
			ret = temp;
		}

		return;
	}

	for (int i = pos; i < shop.size(); ++i) {
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	xy target;
	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> type;


			if (type == 1) {
				target.y = y, target.x = x;
				house.push_back(target);
			}
			if (type == 2) {
				target.y = y, target.x = x;
				shop.push_back(target);
			}
		}
	}

	ret = 0x7fffffff;

	dfs(0);
	cout << ret << '\n';

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