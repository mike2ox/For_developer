// BJO no.16236 �Ʊ���, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int space[20][20];
bool visit[20][20];
int helptime;

struct xy2 {
	int y, x;
	int size;
	int eatCnt;
};
xy2 jaws;
vector<pair<int, int>> fishes;


void go() {
	int dy[] = { 0, 0, -1, 1 };
	int dx[] = { 1,-1,0,0 };
	queue<xy2> q;
	q.push(jaws);
	visit[jaws.y][jaws.x] = true;
	int qSize = q.size();
	int tmptime = 0;

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
			tmptime++;
		}
		xy2 cur = q.front();
		q.pop();
		qSize--;

		for (int i = 0; i < 4; ++i) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			
			if (ny <0 || nx<0 || ny>n - 1 || nx>n - 1|| visit[ny][nx])
				continue;
			else if (space[ny][nx]>cur.size)	// ����Ⱑ �� ū���
				continue;
			//����Ⱑ ���� �������� �湮 ������ ���
			else if (space[ny][nx] == 0 || space[ny][nx] == cur.size) {
				q.push({ ny, nx, cur.size });
				visit[ny][nx] = true;
			}
			else if (space[ny][nx] < cur.size) {// ����Ⱑ ���� ���
				helptime += (tmptime + 1);		// ���� �ð� �����ְ�
				jaws.y = ny, jaws.x = nx;
				jaws.eatCnt++;
				if (jaws.eatCnt == jaws.size) {
					//jaws.eatCnt=0;	//TODO �ʱ�ȭ�� �Ǵ��� Ȯ���� ��
					jaws.size++;
				}
				space[ny][nx] = 0;
				return;
			}
		}
	}
}
bool check() {
	for (auto au : fishes) {
		if (space[au.first][au.second] < jaws.size&& space[au.first][au.second]!=0)
			return true;
	}
	return false;
}
void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visit[i][j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> space[i][j];
			if (space[i][j] >= 1 && space[i][j] <= 6)
				fishes.push_back({ i,j });
			else if (space[i][j] == 9) {
				jaws.y = i; jaws.x = j;
				jaws.size = 2, jaws.eatCnt = 0;
				space[i][j] = 0;
			}
		}
	}

	// ������ �ִ� ����Ⱑ ������ ��� �ݺ�
	while (check()) {
		init();	//�ʱ�ȭ
		go();	//�ִܰŸ��� ã�ư���
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << space[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n'<<'\n';
	}

	cout << helptime << '\n';

	return 0;
}