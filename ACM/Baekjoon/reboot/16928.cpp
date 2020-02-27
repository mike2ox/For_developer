// BJO no.16982 뱀과 사다리 게임, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;

bool visit[101];

struct info {
	int now;
	int next;
};
vector<info> v;

bool checkShortcut(int * nextPoint) {
	for (auto au : v) {
		if (au.now == *nextPoint) {
			if (!visit[au.next]) {
				*nextPoint = au.next;
				return true;
			}
			else {
				*nextPoint = -1;
				return false;
			}
		}
	}
	return true;
}
void bfs() {
	const int dison[] = { 1,2,3,4,5,6 };
	queue<int> q;
	q.push(1);
	int disonCnt = 0;
	int qSize = q.size();
	visit[1] = true;

	while (!q.empty()) {
		if (qSize == 0) {
			qSize = q.size();
			disonCnt++;
		}
		int cur = q.front();
		q.pop();
		--qSize;

		for (int i = 0; i < 6; ++i) {
			int nextPoint = cur + dison[i];

			if (nextPoint == 100) {
				cout << disonCnt + 1 << '\n';
				return;
			}
			else if (nextPoint > 100)
				continue;
			else if (visit[nextPoint])
				continue;
			else if(checkShortcut(&nextPoint)) {
				if(nextPoint!=-1)
					q.push(nextPoint);
				visit[nextPoint] = true;
			}
		}
	}

}

bool compare(const info a, const info b) {
	return a.now < b.now;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n+m; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	};

	sort(v.begin(), v.end(), compare);

	bfs();

	return 0;
}