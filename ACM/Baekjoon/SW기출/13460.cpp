/*
*	author : mike2ox
*	BOJ : 13460
*	descript : https://www.acmicpc.net/problem/13460
*	type : 삼성기출
*	hint :
*/
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

char ck[11][11];
int N, M;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int solve;	//탈출 최소 횟수


int main() {

	ios_base::sync_with_stdio("false");

	queue<pair<int, int>> move;

	//init
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			ck[i][j] = '#';

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> ck[i][j];

	while (1) {
		
		move.push(make_pair(1,3));
	}



	system("pause");
	return 0;
}
/*
 1. N*M 상자 만들기
 2. 상하좌우 움직임 구현
*/
