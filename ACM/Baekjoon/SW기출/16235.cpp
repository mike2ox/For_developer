/*
*	author : mike2ox
*	BOJ : 16236
*	descript : https://www.acmicpc.net/problem/16236
*	type : 시뮬레이션 + 탐색(BFS)
*/
#include<iostream>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(0);


	system("pause");
	return 0;
}
/*
아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

1. 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
2. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
3. 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
	- 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최소값이다.
	- 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

상어가 물고기를 먹은 시간
*/