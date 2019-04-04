/*
*	author : mike2ox
*	swex : 무선 충전
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : 시뮤ㄹ레이션
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define abs(x) (x > 0 ? (x) : -(x))
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
	return a > b;
}

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
