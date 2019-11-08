/*
*	author : mike2ox
*	SWEX : ����Ʈ ī��
*	descript : https://www.swexpertacademy.com/main/learn/course/subjectList.do?courseId=AVvlSPbKAAHw5UPa&subjectId=AV7HzGNaDUADFAXB
*	type : dfs + �ùķ��̼�
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//��ǥ, ����Ʈ ��ȣ
struct desert {
	int y, x;
	int n_d;
};

int map[21][21];
bool visit[21][21];
vector<desert> v;
//11��, 1��, 4��, 7�� ����
const int dy[] = { -1,-1,1,1 };
const int dx[] = { -1, 1, 1, -1};

int n, t, n_des;
void printall() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << map[i][j];
			// cout << visit[i][j];
		}
	}
}
void init() {
	
	for (int i = 1; i <= n; ++i) {
		for (int j =1; j <= n; ++j) {
			map[i][j]=0;
			visit[i][j] = false;
		}
	}
}
bool comp(const desert& a, const desert& b) {
	return a.n_d < b.n_d;	
}

//����Ʈ�� ��ġ�°� �ִ��� ������
bool check() {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 1; j < v.size(); ++j) {
			if (v[i].n_d == v[j].n_d)
				return true;
		}
	}
	//��ġ�°� ����
	return false;
}

//y, x, ������ ����, ���� Ƚ��
void dfs(int ty, int tx, int pd, int cnt) {
	//��������
	//4�� ������ + ó�� ��ġ�� ������ ���
	if (cnt == 4 && (v.front().x == tx && v.front().y == ty)) {
		//�ߺ��ֳ� Ȯ��
		n_des = max(n_des, (int)v.size());
		return;
	}
	// �������� �ִ� ���
	if ((ty == 1 && tx == 1) || (ty == 1 && tx == n) || (ty == n && tx == 1) || (ty == n && tx == n))	return;

	//�湮 ���� ī��� ���� ����
	if (!visit[ty][tx]) {

		visit[ty][tx] = true;
		for (int i = 0; i < 4; ++i) {
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			//���� ��
			if (ny<1 || ny>n || nx<1 || nx>n)
				continue;
			//
			if (check()) {
				n_des = max(n_des, -1);
				return;
			}

			//������ ������ ����� ���� ������ ������ ������ --> ������ ����
			if (pd == i) {
				v.push_back({ ny,nx,map[ny][nx] });
				dfs(ny, nx, i, cnt);
				v.pop_back();
			}
				
			else {
				v.push_back({ ny,nx,map[ny][nx] });
				dfs(ny, nx, i, cnt + 1);
				v.pop_back();
			}
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		n_des = -2;
		init();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				v.push_back({ i,j ,map[i][j]});
				dfs(i,j, 0, 0);
				v.pop_back();
			}
		}
		
		cout << "#" << tc << " " << n_des << '\n';
		//printall();
	}

	system("pause");
	return 0;
}
/*
 �밢�� �������� �����̰� �簢�� ����� �׸��� ����� ī��� ���ƿ;� �Ѵ�. : ����Ŭ
 ī�� ���� �߿� ���� ������ ����Ʈ�� �Ȱ� �ִ� ī�䰡 ������ �� �ȴ�. : check
 �ϳ��� ī�信�� ����Ʈ�� �Դ� �͵� �� �ȴ� :  
 ���� �Դ� ���� �ٽ� ���ư��� �͵� �� �ȴ� : check
 ģ����� ����Ʈ�� �ǵ��� ���� �������� �Ѵ�. : ���� ���� depth

���� �ٸ� ����Ʈ�� �����鼭 �簢�� ����� �׸��� �ٽ� ��������� ���ƿ��� ���,

����Ʈ�� ���� ���� ���� �� �ִ� ��θ� ã��, �� ���� ����Ʈ ���� �������� ����ϴ� ���α׷��� �ۼ�
*/