/*
*	author : mike2ox
*	BOJ : 1260
*	descript : https://www.acmicpc.net/problem/
*	type : graph 1
*	hint :
*/
#include<iostream>
#include<queue>
using namespace std;

int N, M, V;         // 정점, 간선의 수와 탐색 시작 정점 번호
int p, q;     // 간선이 연결될 두 정점
bool graph[1001][1001];
bool ckpt[1001] = { false, };
void DFS(int v) {
	ckpt[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (!ckpt[i] && graph[v][i] == true)
			//1. 탐색하지 않은 node인지 
			//2. 연결되어있지만 탐색을 하지 않은 node들 중 그다음으로 가장 작은 node
			DFS(i);
	}

}
// NOTE: 이론은 이해하나 구현 미숙
void BFS(int v) {

	queue<int> que;
	que.push(v);
	ckpt[v] = true;

	while (!que.empty()) {
		int head = que.front();
		que.pop();
		cout << head << " ";

		for (int i = 1; i <= N; ++i) {
			if (!ckpt[i] && graph[head][i]) {
				que.push(i);
				ckpt[i] = true;
			}
		}
	}

}

int main() {

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> p >> q;
		graph[p][q] = graph[q][p] = true;
	}

	DFS(V);
	cout << "\n";
	for (int j = 0; j < 1001; j++) {
		ckpt[j] = false;
	}
	BFS(V);
	cout << "\n";


	return 0;
}