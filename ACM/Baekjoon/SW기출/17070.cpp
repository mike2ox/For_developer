/*
	Author	: mike2ox
	BOJ		: ������ �ű��1
	No.		: 17070
	Type	: 
*/
#include<iostream>
using namespace std;

int n, ret;
int earth[17][17];
bool visit[17][17];

//	�Ʒ�, ��, �밢��
const int dy[] = { 1,0,1 };
const int dx[] = { 0, 1, 1 };

struct pipe {
	int tail_y, tail_x, head_y, head_x;
};

void dfs(pipe node, int n, int* ret) {
	//���ʳ��� n,n����
	if (node.head_y == n && node.head_x == n) {
		++(*ret);
		return;
	}
	
	int pre_status;
	
	//������ ���¸� ����(����, ����, �밢��)
	if (node.head_y != node.tail_y&&node.head_x == node.tail_x)
		pre_status = 0;
	else if (node.head_y == node.tail_y&&node.head_x != node.tail_x)
		pre_status = 1;
	else if (node.head_y != node.tail_y&&node.head_x != node.tail_x)
		pre_status = 2;
		

	for (int nd = 0; nd < 3; nd++) {
		//���������� �������� �ϸ�
		if (node.head_y + dy[nd]<1 || node.head_y + dy[nd] > n || node.head_x + dx[nd]<1 || node.head_x + dx[nd] >n)
			continue;

		//������ �̸� ����
		node.tail_y = node.head_y;
		node.tail_x = node.head_x;

		//�ٷ� �����¿� ����
		switch (pre_status){
		case 0:
			if (nd != 1) {//������ �ƴϰ�
				if ((nd == 0 && earth[node.head_y + 1][node.head_x] != 1) ||
					(nd == 2 && earth[node.head_y + 1][node.head_x + 1] != 1
						&& earth[node.head_y + 1][node.head_x] != 1
						&& earth[node.head_y][node.head_x + 1] != 1)) {

					node.head_y += dy[nd];
					node.head_x += dx[nd];
					dfs(node, n, ret);
					node.head_y -= dy[nd];
					node.head_x -= dx[nd];
				}
			}
			break;
		case 1:
			if (nd != 0) {
				if ((nd == 1 && earth[node.head_y][node.head_x + 1] != 1) ||
					(nd == 2 && earth[node.head_y + 1][node.head_x + 1] != 1
						&& earth[node.head_y + 1][node.head_x] != 1
						&& earth[node.head_y][node.head_x + 1] != 1)) {

					node.head_y += dy[nd];
					node.head_x += dx[nd];
					dfs(node, n, ret);
					node.head_y -= dy[nd];
					node.head_x -= dx[nd];
				}
			}
			break;
		case 2:
			if ((nd == 0 && earth[node.head_y + 1][node.head_x] != 1) || 
				(nd == 1 && earth[node.head_y][node.head_x + 1] != 1) ||
				(nd == 2 && earth[node.head_y + 1][node.head_x + 1] != 1
					&& earth[node.head_y + 1][node.head_x] != 1
					&& earth[node.head_y][node.head_x + 1] != 1)) {
				node.head_y += dy[nd];
				node.head_x += dx[nd];
				dfs(node, n, ret);
				node.head_y -= dy[nd];
				node.head_x -= dx[nd];
			}
			break;
		}

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pipe node = { 1, 1, 1, 2 };

	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> earth[y][x];
		}
	}
	ret = 0;
	//start h
	dfs(node,n,&ret);

	//�̵���Ű�� ���ϸ� 0���� ���
	cout << ret << '\n';

	return 0;
}
/*
	ó���� �������� (1, 1)�� (1, 2)�� ����
	�������� ���� ���� (N, N)�� �̵���Ű�� ��� ��(ret) --> ���� Ž��
*/