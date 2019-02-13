/*
*	author : mike2ox
*	BOJ : 11724
*	descript : https://www.acmicpc.net/problem/
*	type : Graph 1
*	hint :
*/
#include<iostream>
using namespace std;
bool graph[1001][1001] = { false, };
bool ckpt[1001] = { false, };

int N, M, u, v;
int cnt = 0;
void DFS(int n) {

	ckpt[n] = true;
	for (int i = 1; i <= N; ++i) {
		// ckpt도 index 변화해야함.
		if (!ckpt[i] && graph[n][i])
			DFS(i);
	}
}
int main() {

	cin >> N >> M;

	// 그래프 생성
	for (int i = 1; i <= M; ++i) {
		cin >> u >> v;
		graph[u][v] = graph[v][u] = true;
	}

	for (int j = 1; j <= N; ++j)
		if (!ckpt[j]) {
			DFS(j);
			++cnt;
		}
	cout << cnt;
	return 0;
}