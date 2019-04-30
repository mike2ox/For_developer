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
		}
	}
}
//����Ʈ�� ��ġ�°� �ִ��� ������
bool check() {
	
	for (vector<desert>::iterator itr = v.begin(); itr != v.end(); ++itr) {
		
	}
	//��ġ�°� ����
	return false;
}
//��ü ���
int cal(vector<desert>& d) {
	int ret = 0;

	for (vector<desert>::iterator itr = d.begin(); itr != d.end(); ++itr){}
	return ret;
}
//y, x, ������ ����, ���� Ƚ��
int dfs(int ty, int tx, int pd, int cnt) {
	//map�� ������
	if ((ty==1&&tx==1)|| (ty == 1 && tx == n)|| (ty == n && tx == 1)|| (ty == n && tx == n))
		return -1;
	if (!check())
		return -1;
	//�湮 ���� 
	if (visit[ty][tx]) {
		//������� ���� ������ ��ġ�� ��ǥ�� ���� ���
		if (ty == v.front().y && tx == v.front().x ) {
			return (int)v.size();
		}
		else //�湮�� �������� ��ǥ�� �ٸ� ��� --> ���� / ���� �̶� X
			return -1;
	}
	visit[ty][tx] == true;
	
	for (int i = 0; i < 4; ++i) {
		int ny = ty + dy[i];
		int nx = tx + dx[i];

		n_des = max(n_des, dfs(ny, nx, i, cnt + 1));//�� ū ������
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		n_des = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> map[i][j];
			}
		}

		n_des = dfs(2, 1, 1,0);
		cout << "#" << tc << " " << n_des << '\n';
		//printall();
		init();
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