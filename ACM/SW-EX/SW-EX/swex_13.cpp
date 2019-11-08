/*
*	author : mike2ox
*	SWEX : 디저트 카페
*	descript : https://www.swexpertacademy.com/main/learn/course/subjectList.do?courseId=AVvlSPbKAAHw5UPa&subjectId=AV7HzGNaDUADFAXB
*	type : dfs + 시뮬레이션
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//좌표, 디저트 번호
struct desert {
	int y, x;
	int n_d;
};

int map[21][21];
bool visit[21][21];
vector<desert> v;
//11시, 1시, 4시, 7시 방향
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

//리스트에 겹치는게 있느지 없는지
bool check() {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 1; j < v.size(); ++j) {
			if (v[i].n_d == v[j].n_d)
				return true;
		}
	}
	//겹치는게 없음
	return false;
}

//y, x, 접근한 방향, 꺽은 횟수
void dfs(int ty, int tx, int pd, int cnt) {
	//종료조건
	//4개 꼭지점 + 처음 위치와 동일한 경우
	if (cnt == 4 && (v.front().x == tx && v.front().y == ty)) {
		//중복있나 확인
		n_des = max(n_des, (int)v.size());
		return;
	}
	// 꼭지점에 있는 경우
	if ((ty == 1 && tx == 1) || (ty == 1 && tx == n) || (ty == n && tx == 1) || (ty == n && tx == n))	return;

	//방문 안한 카페야 접근 가능
	if (!visit[ty][tx]) {

		visit[ty][tx] = true;
		for (int i = 0; i < 4; ++i) {
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			//범위 밖
			if (ny<1 || ny>n || nx<1 || nx>n)
				continue;
			//
			if (check()) {
				n_des = max(n_des, -1);
				return;
			}

			//이전에 접근한 방향과 지금 가야할 방향이 같으면 --> 꺾이지 않음
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
 대각선 방향으로 움직이고 사각형 모양을 그리며 출발한 카페로 돌아와야 한다. : 싸이클
 카페 투어 중에 같은 숫자의 디저트를 팔고 있는 카페가 있으면 안 된다. : check
 하나의 카페에서 디저트를 먹는 것도 안 된다 :  
 같이 왔던 길을 다시 돌아가는 것도 안 된다 : check
 친구들과 디저트를 되도록 많이 먹으려고 한다. : 가장 깊은 depth

서로 다른 디저트를 먹으면서 사각형 모양을 그리며 다시 출발점으로 돌아오는 경우,

디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력하는 프로그램을 작성
*/