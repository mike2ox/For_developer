// BOJ no. 1707, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int testCase;
int v, e;
vector<int> bGraph[20001];
bool visit[20001];
int check;
bool flag;


void bfs() {
	queue<int> q;
	q.push(1);
	int qSize = q.size();

	while (!q.empty()) {
		if (qSize == 0) {

			qSize = q.size();
		}
		int curIdx = q.front();
		visit[curIdx] = true;
		q.pop();

		--qSize;		
		

		for (auto au : bGraph[curIdx]) {
			if (visit[au])
				continue;
			visit[au] = true;
			q.push(au);	
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> testCase;

	while (--testCase) {
		cin >> v >> e;
		flag = false;

		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			bGraph[a].push_back(b);
			bGraph[b].push_back(a);

			bfs();

			if (flag)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
	return 0;
}