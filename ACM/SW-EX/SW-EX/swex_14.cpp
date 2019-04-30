/*
*	author : mike2ox
*	SWEX : 탈주범 검거
*	descript : https://www.swexpertacademy.com/main/learn/course/subjectList.do?courseId=AVvlSPbKAAHw5UPa&subjectId=AV7HzGNaDUADFAXB
*	type :bfs
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, tc, r, c, l;
int cnt;
int map[51][51];
bool visit[51][51]; // 후보지

//좌, 우, 상,하
const int dy[] = { 0,0,-1,1 };
const int dx[] = { -1,1,0,0 };

void printall() {
	for (int j = 0; j < n; ++j) {
		for (int k = 0; k < m; ++k) {
			
			if (visit[j][k])
				cout << '@' << ' ';
			else
				cout << 'X' << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
}

bool check(int _y, int _x, int _ny, int _nx, int _d) {
	switch (_d)
	{
	case 0:
		if ((map[_y][_x] == 1 || map[_y][_x] == 3 || map[_y][_x] == 6 || map[_y][_x] == 7) &&
			(map[_ny][_nx] == 1 || map[_ny][_nx] == 3 || map[_ny][_nx] == 4 || map[_ny][_nx] == 5))
			return true;
		break;
	case 1:
		if ((map[_y][_x] == 1 || map[_y][_x] == 3 || map[_y][_x] == 4 || map[_y][_x] == 5) &&
			(map[_ny][_nx] == 1 || map[_ny][_nx] == 3 || map[_ny][_nx] == 6 || map[_ny][_nx] == 7))
			return true;
		break;
	case 2:
		if ((map[_y][_x] == 1 || map[_y][_x] == 2 || map[_y][_x] == 4 || map[_y][_x] == 7) &&
			(map[_ny][_nx] == 1 || map[_ny][_nx] == 2 || map[_ny][_nx] == 5 || map[_ny][_nx] == 6))
			return true;
		break;
	case 3:
		if ((map[_y][_x] == 1 || map[_y][_x] == 2 || map[_y][_x] == 5 || map[_y][_x] == 6) &&
			(map[_ny][_nx] == 1 || map[_ny][_nx] == 2 || map[_ny][_nx] == 4 || map[_ny][_nx] == 7))
			return true;
		break;
	}

	return false;
}

void bfs() {

	queue<pair<int, int>> q;
	q.push(make_pair(r, c));	//맨홀 뚜껑
	visit[r][c] = true;
	cnt++;
	printall();
	while (--l) {
		int q_s = q.size();
		//escape++;

		while (q_s--) {
			int ty = q.front().first;
			int tx = q.front().second;

			for (int d = 0; d < 4; ++d) {
				int ny = ty + dy[d];
				int nx = tx + dx[d];

				//연결되면
				if (check(ty, tx, ny, nx, d) && !visit[ny][nx]) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = true;
					cnt++;
				}
			}
			q.pop();
		}

		printall();
	}
}
void init() {
	cnt = 0;
	for (int j = 0; j < n; ++j)
		for (int k = 0; k < m; ++k)
			map[j][k]=0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> tc;
	
	for (int i = 1; i <= tc; i++) {
		cin >> n >> m >> r >> c >> l;
		
		//NOTE: 입력에서 tc 5번 안됨
		for (int j = 0; j < n; ++j){
			for (int k = 0; k < m; ++k) 
				cin >> map[j][k];
		}
				

		printall();
		bfs();
		cout << '#' << i << " " << cnt << '\n';
		init();
	}
	system("pause");
	return 0;
}
/*
지하 터널 지도와 맨홀 뚜껑의 위치, 경과된 시간이 주어질 때 탈주범이 위치할 수 있는 장소의 개수를 계산

숫자 1 ~ 7은 해당 위치의 터널 구조물 타입을 의미하며 숫자 0 은 터널이 없는 장소를 의미한다.
*/