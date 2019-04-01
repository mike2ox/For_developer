/*
*	author : mike2ox
*	swex : �ٱ⼼�� ���
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : ���� Ž��
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define p pair<int,int>
using namespace std;

// ��������
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int map[700][700];

int n, m, k;
int ans;

struct Node {
	int x;
	int y;
	int time;
	Node(int a, int b, int c) : x(a), y(b), time(c) {};
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		memset(map, 0, sizeof(map));
		ans = 0;
		cin >> n >> m >> k;

		/*
		 ������� �������� ó���� ���̱⿡ ť�� 11 ������� ��´�.
		 (1 ~ 10 ������ ������� ���´ٴ� ����)
		 */
		queue<Node> q[11];

		for (int i = 350; i < n + 350; i++) {
			for (int j = 350; j < m + 350; j++) {
				cin >> map[i][j];
				if (map[i][j])
					// �ʱ� ���¿��� ���� ������ �� �ɸ��� �ð��� [ �־��� �ð� * 2 ] �ð��̴�.
					q[map[i][j]].push(Node(i, j, map[i][j] * 2));
			}
		}

		while (k--) {
			for (int i = 10; i >= 1; i--) {
				int size = (int)q[i].size();
				
				// i = 8 �� �� 8��ŭ�� ������� ���� �ִ� �ٱ� �������� ���� �ִ� ť�� ���ؼ� �۾�.
				for (int j = 0; j < size; j++) {
					int x = q[i].front().x;
					int y = q[i].front().y;
					int time = q[i].front().time;
					q[i].pop();

					time--;
					/*
					 i = 8 �� �� map[x][y] = 8
					 time�� 16���� ���������� �پ���.
					 
					 map[x][y] > time�� �ȴٸ� [ ��Ȱ��ȭ -> Ȱ�� ] ���°� �Ǵ� �� �������� ����.
					 �� ���ķδ� map[nx][ny]���� 0�� �ƴϱ� ������ �������� �۾��� �̷����� �ʴ´�.
					 */
					if (map[x][y] > time) {
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (map[nx][ny] == 0) {
								map[nx][ny] = map[x][y];
								q[i].push(Node(nx, ny, map[nx][ny] * 2));
							}
						} // end of for k
					} // end of if

					/*
					 i = 8 �� �� map[x][y] = 8�� ������ �Ǿ� �ְ� time ���� ���������� ����.
					 8���� ũ�� ��Ȱ��ȭ, 8���� ������ Ȱ��ȭ.
					 �׸��� time�� 0�� �ȴٸ� ���� ����.
					 */
					if (time > 0) {
						q[i].push(Node(x, y, time));
					}
				} 
			}
		}

		/*
		 i�� ������̰� q[i]�� �����ִ� Node���� Ȱ��ȭ / ��Ȱ��ȭ.
		 ���� ���´� ť�� �ٽ� push ������.
		 */
		for (int i = 1; i < 11; i++)
			ans += q[i].size();

		cout << "#" << tc << " " << ans << endl;
	}

	return 0;
}