// BJO no. 14226 mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

bool visit[1001][1001];
struct step {
	int curTime;
	int clipboard;
	int printValue;
};
int s;

void bfs() {
	queue<step> q;
	q.push({ 0,0,1 });
	// visit[0][1] = true;
	int qSize = 0;
	int	minimum = 100000;

	while (!q.empty()) {
		if (qSize == 0) {
			if (minimum != 100000)
				break;
			qSize = q.size();
		}
		step current = q.front();
		q.pop();
		--qSize;

		if (visit[current.clipboard][current.printValue])
			continue;
		visit[current.clipboard][current.printValue] = true;


		if (current.printValue == s && minimum > current.curTime) {
			minimum = current.curTime;
			//break;
		}
		else if (current.printValue + current.clipboard <= s) {
			//1. ȭ�麹��(Ŭ������� ������� ����)
			if (current.clipboard != current.printValue) {
				q.push({ current.curTime + 1, current.printValue, current.printValue });
				//3. ����
				q.push({ current.curTime + 1, current.clipboard, current.printValue - 1 });
			}
			//2. �ٿ��ֱ�
			if (current.clipboard != 0) {
				q.push({ current.curTime + 1, current.clipboard, current.printValue + current.clipboard });
			}
		}
	}

	cout << minimum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> s;

	bfs();

	return 0;
}