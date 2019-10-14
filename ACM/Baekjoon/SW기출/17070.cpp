/*
	Author	: mike2ox
	BOJ		: 파이프 옮기기1
	No.		: 17070
	Type	: 
*/
#include<iostream>
using namespace std;

int n, ret;
int earth[17][17];
bool visit[17][17];

//	아래, 우, 대각선
const int dy[] = { 1,0,1 };
const int dx[] = { 0, 1, 1 };

struct pipe {
	int tail_y, tail_x, head_y, head_x;
};

void dfs(pipe node, int n, int* ret) {
	//한쪽끝이 n,n도착
	if (node.head_y == n && node.head_x == n) {
		++(*ret);
		return;
	}
	
	int pre_status;
	
	//파이프 상태를 나눔(세로, 가로, 대각선)
	if (node.head_y != node.tail_y&&node.head_x == node.tail_x)
		pre_status = 0;
	else if (node.head_y == node.tail_y&&node.head_x != node.tail_x)
		pre_status = 1;
	else if (node.head_y != node.tail_y&&node.head_x != node.tail_x)
		pre_status = 2;
		

	for (int nd = 0; nd < 3; nd++) {
		//범위밖으로 나가려고 하면
		if (node.head_y + dy[nd]<1 || node.head_y + dy[nd] > n || node.head_x + dx[nd]<1 || node.head_x + dx[nd] >n)
			continue;

		//파이프 미리 땡김
		node.tail_y = node.head_y;
		node.tail_x = node.head_x;

		//바로 전상태에 따라서
		switch (pre_status){
		case 0:
			if (nd != 1) {//우측이 아니고
				if ((nd == 0 && earth[node.head_y + 1][node.head_x] != 1) ||
					(nd == 2 && earth[node.head_y + 1][node.head_x + 1] != 1
						&& earth[node.head_y + 1][node.head_x] != 1
						&& earth[node.head_y][node.head_x + 1] != 1)) {

					node.head_y += dy[nd];
					node.head_x += dx[nd];
					dfs(node, n, ret);
					node.head_y -= dy[nd];
					node.head_x -= dx[nd];
				}
			}
			break;
		case 1:
			if (nd != 0) {
				if ((nd == 1 && earth[node.head_y][node.head_x + 1] != 1) ||
					(nd == 2 && earth[node.head_y + 1][node.head_x + 1] != 1
						&& earth[node.head_y + 1][node.head_x] != 1
						&& earth[node.head_y][node.head_x + 1] != 1)) {

					node.head_y += dy[nd];
					node.head_x += dx[nd];
					dfs(node, n, ret);
					node.head_y -= dy[nd];
					node.head_x -= dx[nd];
				}
			}
			break;
		case 2:
			if ((nd == 0 && earth[node.head_y + 1][node.head_x] != 1) || 
				(nd == 1 && earth[node.head_y][node.head_x + 1] != 1) ||
				(nd == 2 && earth[node.head_y + 1][node.head_x + 1] != 1
					&& earth[node.head_y + 1][node.head_x] != 1
					&& earth[node.head_y][node.head_x + 1] != 1)) {
				node.head_y += dy[nd];
				node.head_x += dx[nd];
				dfs(node, n, ret);
				node.head_y -= dy[nd];
				node.head_x -= dx[nd];
			}
			break;
		}

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pipe node = { 1, 1, 1, 2 };

	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> earth[y][x];
		}
	}
	ret = 0;
	//start h
	dfs(node,n,&ret);

	//이동시키지 못하면 0으로 출력
	cout << ret << '\n';

	return 0;
}
/*
	처음에 파이프는 (1, 1)와 (1, 2)를 차지
	파이프의 한쪽 끝을 (N, N)로 이동시키는 방법 수(ret) --> 완전 탐색
*/