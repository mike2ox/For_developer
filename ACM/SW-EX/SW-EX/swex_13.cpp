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
//리스트에 겹치는게 있느지 없는지
bool check() {
	
	for (vector<desert>::iterator itr = v.begin(); itr != v.end(); ++itr) {
		
	}
	//겹치는게 없음
	return false;
}
//전체 계산
int cal(vector<desert>& d) {
	int ret = 0;

	for (vector<desert>::iterator itr = d.begin(); itr != d.end(); ++itr){}
	return ret;
}
//y, x, 접근한 방향, 꺽은 횟수
int dfs(int ty, int tx, int pd, int cnt) {
	//map의 꼭지점
	if ((ty==1&&tx==1)|| (ty == 1 && tx == n)|| (ty == n && tx == 1)|| (ty == n && tx == n))
		return -1;
	if (!check())
		return -1;
	//방문 여부 
	if (visit[ty][tx]) {
		//출발점과 현재 도착한 위치의 좌표가 같을 경우
		if (ty == v.front().y && tx == v.front().x ) {
			return (int)v.size();
		}
		else //방문한 곳이지만 좌표가 다른 경우 --> 교차 / 유턴 이라서 X
			return -1;
	}
	visit[ty][tx] == true;
	
	for (int i = 0; i < 4; ++i) {
		int ny = ty + dy[i];
		int nx = tx + dx[i];

		n_des = max(n_des, dfs(ny, nx, i, cnt + 1));//더 큰 것으로
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
 대각선 방향으로 움직이고 사각형 모양을 그리며 출발한 카페로 돌아와야 한다. : 싸이클
 카페 투어 중에 같은 숫자의 디저트를 팔고 있는 카페가 있으면 안 된다. : check
 하나의 카페에서 디저트를 먹는 것도 안 된다 :  
 같이 왔던 길을 다시 돌아가는 것도 안 된다 : check
 친구들과 디저트를 되도록 많이 먹으려고 한다. : 가장 깊은 depth

서로 다른 디저트를 먹으면서 사각형 모양을 그리며 다시 출발점으로 돌아오는 경우,

디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력하는 프로그램을 작성
*/