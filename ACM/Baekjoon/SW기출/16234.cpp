/*
*	author : mike2ox
*	BOJ : 16234
*	descript : https://www.acmicpc.net/problem/16234
*	type : 삼성 기출 : 시뮬레이션 + 완전탐색
*/
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

int map[51][51];
int ck[51][51];
int n, y, x;
//인구수 경계
int l, r;
int cnt = 0;//인구이동

//상하좌우
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void go() {
	int n_area;

	for (int i = 0; i < 4; ++i) {
		//int ny = 
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> map[row][col];
		}
	}

	go();

	return 0;
}
/*
인구 이동은 다음과 같이 진행되고, 더 이상 인구 이동이 없을 때까지 지속된다.

1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
2. 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
3. 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
4. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
5. 연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 몇 번 발생하는지 구하는 프로그램

인구 이동이 발생하는 횟수가 2,000번 보다 작거나 같은 입력만 주어진다.(?)
*/