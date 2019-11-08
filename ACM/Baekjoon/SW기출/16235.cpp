/*
*	author : mike2ox
*	BOJ : 16235
*	descript : https://www.acmicpc.net/problem/16235
*	type : 시뮬레이션 + 탐색(BFS)
*/
#include<iostream>
#include<queue>
using namespace std;

const int dy[] = {-1,-1,-1,0,0,1,1,1};
const int dx[] = {-1,0,1,-1,1,-1,0,1};
struct namu {
	int y, x;
	int age;
	namu(int a, int b, int c) :
		y{ a }, x{ b }, age{ c } {}
};
int cnt;
int n, m, k;
int a[11][11];
int cp_a[11][11];
queue<namu> q;

//bfs
void invest() {

	while(!q.empty()||k--){
		//끝나는 시점
		if (!k)
			return;
		int cy = q.front().y;
		int cx = q.front().x;
		int cage = q.front().age;

		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			//범위밖
			if (ny<1 || ny>n || nx<1 || nx>n)
				continue;
			
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			cp_a[i][j] = a[i][j];
		}
	}
			
	
	for (int i = 1; i <= m; ++i) {
		int ty, tx, tage;
		cin >> ty >> tx >> tage;
		q.push({ ty, tx, tage });
	}
	
	invest();
	
	system("pause");
	return 0;
}
/*
//첫째 줄에 N, M, K가 주어진다.

//둘째 줄부터 N개의 줄에 A배열의 값이 주어진다. r번째 줄의 c번째 값은 A[r][c]이다.

//다음 M개의 줄에는 상도가 심은 나무의 정보를 나타내는 세 정수 x, y, z가 주어진다. 
//처음 두 개의 정수는 나무의 위치 (x, y)를 의미하고, 마지막 정수는 그 나무의 나이를 의미한다.
--> x < r, y < c(인지 중요)

봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 
하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.

여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 
각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 
소수점 아래는 버린다.

가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 
인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
//(r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 번식 
//상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.

겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.

K년이 지난 후 상도의 땅에 살아있는 나무의 개수.
*/