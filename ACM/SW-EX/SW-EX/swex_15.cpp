
/*
*   author : mike2ox
*   swex : Ȱ�ַ� �Ǽ�
*   descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*   type : ���� Ž��(DFS)
*	hint : ������ġ�� k��ŭ ���� �� ������ --> �ּ������� ��� ���ڿ� DFS
*/
#include<iostream>
using namespace std;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int map[8][8];
int visited[8][8];
int len;
int _max;
int n, k;
int tc;

void go(int i, int j, int cnt, bool _k) {
	visited[i][j] = 1;

	for (int x = 0; x < 4; x++) {
		// ���
		if (i + dx[x] >= 0 && i + dx[x] < n && j + dy[x] >= 0 && j + dy[x] < n && visited[i+dx[x]][j + dy[x]] == 0) {

			//���� ��
			if (map[i][j] > map[i + dx[x]][j + dy[x]]) {
				go(i + dx[x], j + dy[x], cnt + 1, _k);
			}
			else if (map[i][j] <= map[i + dx[x]][j + dy[x]] && _k) {
				//�̵������� ���� ���� ���� k���� ���� ��
				if (k > map[i + dx[x]][j + dy[x]] - map[i][j]) {
					_k = false;
					int temp = map[i + dx[x]][j + dy[x]];

					map[i + dx[x]][j + dy[x]] = map[i][j] - 1;
					go(i + dx[x], j + dy[x], cnt + 1, _k);	//��� ����
					map[i + dx[x]][j + dy[x]] = temp;
					
					_k = true;
				}
			}
		}
	}
	visited[i][j] = 0;
	if (len < cnt) {
		len = cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		len = 0;
		_max = 0;
		cin >> n >> k;

		//map ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				visited[i][j] = 0;
				if (map[i][j] > _max)
					_max = map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == _max)
					go(i, j, 1, true);
			}
		}
		cout << "#" << t << " " << len << '\n';
	}
	return 0;
}

/*
1. �ð� ���� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴ� �� C/C++/Java ��� 3��
2. ������ �� ���� ���� N�� 3 �̻� 8 ������ �����̴�. (3 �� N �� 8)
3. �ִ� ���� ���� ���� K�� 1 �̻� 5 ������ �����̴�. (1 �� K �� 5)
4. ������ ��Ÿ���� ������ ���̴� 1 �̻� 20 ������ �����̴�.
5. �������� ���� ���� ���츮�� �ִ� 5���̴�.
6. ������ ���� �����θ� ���� �� �ִ�.
7. �ʿ��� ��� ������ ��� ���̸� 1���� �۰� ����� �͵� �����ϴ�.

*/