// BJO no. 3085 mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n;
char board[50][51];	//c, p, z, y
const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int maximum = 0;
void swap(int starty, int startx, int ny, int nx) {
	char temp = board[starty][startx];
	board[starty][startx] = board[ny][nx];
	board[ny][nx]=temp;
}
void go2(int starty, int startx, int ny, int nx) {
	// swap
	swap(starty, startx, ny, nx);
	int vertical = 1; int horizontal = 1;

	for (int d = 0; d < 4; ++d) {
		int ctnY = starty + dy[d];
		int ctnX = startx + dx[d];

		while (board[ctnY][ctnX] == board[starty][startx]) {
			ctnY += dy[d]; ctnX += dx[d];
			if (d / 2 == 0)	++horizontal;
			else ++vertical;
		}

		if (horizontal > maximum)
			maximum = horizontal;
		if (vertical > maximum)
			maximum = vertical;
	}
	/*
	for (int d = 0; d < 4; ++d) {
		int ctnY1 = starty + dy[d];
		int ctnY2 = ny + dy[d];
		int ctnX1 = startx + dx[d];
		int ctnX2 = nx + dx[d];
		int length = 0;

		if (ctnY1 < 0 || ctnY2<0 || ctnY1>n - 1 || ctnY2 >n - 1
			|| ctnX1 < 0 || ctnX2<0 || ctnX1>n - 1 || ctnX2 >n - 1)
			continue;

		while (board[ctnY1][ctnX1] == board[starty][startx]) {
			ctnY1 += dy[d]; ctnX1 += dx[d];
			++length;
		}

		if (maximum < length+1)
			maximum = length+1;
		length = 0;

		while (board[ctnY2][ctnX2] == board[ny][nx]) {
			ctnY2 += dy[d]; ctnX2 += dx[d];
			++length;
		}

		if (maximum < length+1)
			maximum = length+1;
		length = 0;
	}*/

	// swap
	swap(starty, startx, ny, nx);
}
void go(int y, int x) {
	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx<0 || nx>n - 1 || ny>n - 1)
			continue;
		if (board[ny][nx] == board[y][x])
			continue;

		go2(y, x, ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	// 선택
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			go(i, j);
		}
	}

	cout << maximum << '\n';
	// 상하좌우 변환
	// 값 추산

	return 0;
}