/*
*	author : mike2ox
*	BOJ :������ȣ ���̱�
*	descript : https://www.acmicpc.net/problem/2667
*	type : dfs
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[26][26];
bool ck[26][26];

const int dy[] = { 0,0,-1,1 };
const int dx[] = {1, -1, 0, 0};

int n;
int cnt;	//�� ������ �� ��
vector<int> v; // �������� ���� �� ��

//��ǥ, ���� ��
void dfs(int _i, int _j) {
	cnt++;
	ck[_i][_j] = true;

	for (int i = 0; i < 4; ++i) {
		int ny = _i + dy[i];
		int nx = _j + dx[i];

		//���� �� + ������ �湮�� ����� �ִ� ���
		if (ny>=0&&nx>=0&& ny<n&&nx<n){
			if (map[ny][nx]==1&&ck[ny][nx]==false) {
				dfs(ny, nx);
			}
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// ���� Ž��, 1�̰� �湮���� ���
			if (map[i][j]==1 && !ck[i][j]) {
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';

	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << '\n';

	system("pause");
	return 0;
}