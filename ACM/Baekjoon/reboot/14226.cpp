// BJO no. 14226 mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int s;
struct node {
	int value;
	int copyValue;
	int cnt;
};
bool visit[1001][1001];

int bfs() {
	queue<node> q;
	q.push({ 1 , 0,0});

	while (!q.empty()) {
		int value = q.front().value;
		int plus = q.front().copyValue;
		int cCnt = q.front().cnt;
		node newData;

		q.pop();

		// 종료 조건
		if (s == value)
			return cCnt;
		
		if (cCnt == 0) {
			newData.value = value;
			newData.copyValue = value;
			newData.cnt = cCnt + 1;
			visit[newData.value][newData.copyValue] = true;
			q.push(newData);
		}
		else if (cCnt == 1) {
			newData.value = value+plus;
			newData.copyValue = plus;
			newData.cnt = cCnt + 1;
			if (visit[newData.value][newData.copyValue])
				continue;
			visit[newData.value][newData.copyValue] = true;
			q.push(newData);
		}
		else {
			//1. 이전 클립보드 붙이기
			newData.value = value + plus;
			newData.copyValue = plus;
			newData.cnt = cCnt + 1;
			if (visit[newData.value][newData.copyValue]||newData.value>1000)
				continue;
			q.push(newData);

			//2. 클립보드 갱신하고 붙이기
			plus = value;
			newData.value = value + plus;
			newData.copyValue = plus;
			newData.cnt = cCnt + 2;
			if (visit[newData.value][newData.copyValue] || newData.value > 1000)
				continue;
			q.push(newData);
		}
		//3. 1개 삭제 삭제
		newData.value = value - 1;
		if (visit[newData.value][newData.copyValue] || newData.value > 1000)
			continue;
		newData.cnt = cCnt + 1;
		q.push(newData);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> s;

	cout << bfs();

	return 0;
}