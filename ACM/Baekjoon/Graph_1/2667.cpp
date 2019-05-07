/*
*	author : mike2ox
*	BOJ :������ȣ ���̱�
*	descript : https://www.acmicpc.net/problem/2667
*	type : dfs
*/
#include<iostream>
#include<queue>
using namespace std;

int map[25][25];
bool ck[25][25];

const int dy[] = { 0,0,-1,1 };
const int dx[] = {1, -1, 0, 0};

int n;
int cnt;	//�� ������ �� ��
queue<int> q; // �������� ���� �� ��

//��ǥ, ���� ��
void dfs(int _i, int _j, int ncnt) {
	//���� ����
	// ���� �� �� ���� ���� ���
	if () {
		q.push(cnt);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = _i + dy[i];
		int nx = _j + dx[i];

		//���� �� + ������ �湮�� ����� �ִ� ���
		if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1 || ck[ny][nx])
			continue;

		ck[ny][nx] = true;
		dfs(ny, nx, ncnt+1);
		ck[ny][nx] = false;		
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// ���� Ž��, 1�̰� �湮���� ���
			if(map[i][j]&&ck[i][j])
				dfs(i,j,0);
		}
	}



	system("pause");
	return 0;
}