/*
*	author : mike2ox
*	swex : 무선 충전
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : 시뮬레이션
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define abs(x) (x > 0 ? (x) : -(x))
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
	return a > b;
}
// 
typedef struct AP {
	int x, y, c, p;
};

//충전기
AP ap[8];

const int dx[] = { 0,-1,0,1,0 };
const int dy[] = { 0,0,1,0,-1 };

int M, A, move_A[100], move_B[100];

int x, y, c, p;
int map[11][11] = { 0 };
int eng = 0;
int ax = 1, ay = 1;
int bx = 10, by = 10;

vector<pair<int, int>> v1, v2;

void check(int ax, int ay, int bx, int by) {
	//A,B에 대해 모든 충전기 검사
	for (int i = 0; i < A; i++) {
		int dist_A = abs(ax - ap[i].x) + abs(ay - ap[i].y);
		int dist_B = abs(bx - ap[i].x) + abs(by - ap[i].y);

		if (dist_A <= ap[i].c) {
			v1.push_back(make_pair(ap[i].p, i));
		}
		if (dist_B <= ap[i].c) {
			v2.push_back(make_pair(ap[i].p, i));
		}
	}
	sort(v1.begin(), v1.end(), desc);
	sort(v2.begin(), v2.end(), desc);

	if (v1.empty() && v2.empty())
		return;//둘 다 0개
	else if (v1.empty()) {
		eng += v2.front().first;
		return;
	}//A가 0개 B가 1개 이상

	else if (v2.empty()) {
		eng += v1.front().first;
		return;
	}//A가 1개 이상 B가 0개

	else {
		//최댓값이 같을 때
		if (v1.front() == v2.front()) {
			// A가 1개, B가 1개
			if (v1.size() == 1 && v2.size() == 1) {
				if (v1.front().second == v2.front().second)
					//나눠서 충전
					eng += v1.front().first;
				else {
					eng += v1.front().first;
					eng += v2.front().first;
				}
			}
			//A가 1개, B가 2개 이상
			else if (v1.size() == 1) {
				if (v1.front().second == v2.front().second) {
					eng += v1[0].first;
					eng += v2[1].first;
				}
				else {
					eng += v1.front().first;
					eng += v2.front().first;
				}
			}
			//B가 1개, A가 2개 이상
			else if (v2.size() == 1) {
				if (v1.front().second == v2.front().second) {
					eng += v1[1].first;
					eng += v2[0].first;
				}
				else {
					eng += v1.front().first;
					eng += v2.front().first;
				}
			}
			else {
				if (v1.front().second == v2.front().second) {
					eng += v1.front().first;
					eng += max(v1[1].first, v2[1].first);
				}
			}
		}
		//최댓값이 다를 때
		else {
			eng += v1.front().first;
			eng += v2.front().first;
		}
	}
}

void move(int za, int zb) {
	ax += dx[za];
	ay += dy[za];
	bx += dx[zb];
	by += dy[zb];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc){
		ax = 1, ay = 1, bx = 10, by = 10;
		eng = 0;
		//이동시간, 충전기갯수
		cin >> M >> A;

		//이동정보
		for (int i = 0; i < M; i++) {
			cin >> move_A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> move_B[i];
		}

		//충전기 정보
		for (int j = 0; j < A; j++) {
			cin >> x >> y >> c >> p;
			ap[j] = { y,x,c,p };
		}
		for (int i = 0; i <= M; i++) {
			check(ax, ay, bx, by);
			v1.clear();
			v2.clear();
			move(move_A[i], move_B[i]);
		}
		cout << "#" << tc << ' ' << eng << '\n';
	}
	return 0;
}
/*
BC의 정보와 사용자의 이동 궤적이 주어졌을 때, 모든 사용자가 충전한 양의 합의 최댓값?

매초마다 특정 BC의 충전 범위에 안에 들어오면 해당 BC에 접속이 가능하다. 
따라서 T=5에 사용자 A는 BC 3에, 사용자 B는 BC 2에 접속할 수 있다. 
이때, 접속한 BC의 성능(P)만큼 배터리를 충전 할 수 있다. 
만약 한 BC에 두 명의 사용자가 접속한 경우, 접속한 사용자의 수만큼 충전 양을 균등하게 분배한다

1. 지도의 가로, 세로 크기는 10이다.
2. 사용자는 총 2명이며, 사용자A는 지도의 (1, 1) 지점에서, 사용자B는 지도의 (10, 10) 지점에서 출발한다.
3. 총 이동 시간 M은 20이상 100이하의 정수이다. (20 ≤ M ≤ 100)
4. BC의 개수 A는 1이상 8이하의 정수이다. (1 ≤ A ≤ 8)
5. BC의 충전 범위 C는 1이상 4이하의 정수이다. (1 ≤ C ≤ 4)
6. BC의 성능 P는 10이상 500이하의 짝수이다. (10 ≤ P ≤ 500)
7. 사용자의 초기 위치(0초)부터 충전을 할 수 있다.
8. 같은 위치에 2개 이상의 BC가 설치된 경우는 없다. 그러나 사용자A, B가 동시에 같은 위치로 이동할 수는 있다. 사용자가 지도 밖으로 이동하는 경우는 없다

*/