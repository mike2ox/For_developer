// BJO no. 9019 DSLR, mike2ox(2020)
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int tc;
int a, b;
bool visit[10000];
struct node {
	int value;
	string str;
};

node go2(node cur, int select) {
	
	int nextval;
	string substr = cur.str;

	switch (select)
	{
	case 0:
		nextval = (cur.value * 2)%10000;
		substr.append("D");
		break;
	case 1:
		if (cur.value == 0) {
			nextval = 9999;
		}
		else {
			nextval = cur.value - 1;
		}
		substr.append("S");
		break;
	case 2:
		nextval = cur.value % 1000;
		nextval *= 10;
		nextval += cur.value / 1000;
		substr.append("L");
		break;
	case 3:
		nextval = cur.value / 10;
		nextval += (cur.value % 10)*1000;
		substr.append("R");
		break;
	}

	return { nextval, substr };
}
void go() {
	queue<node> q;
	q.push({ a , ""});
	visit[q.front().value] = true;

	while (!q.empty()) {
		node curValue = q.front();
		q.pop();

		//최초 시행할때 같을 경우(추가함)
		if (curValue.value == b) {
			cout << curValue.str << '\n';
			return;
		}

		for (int i = 0; i < 4; ++i) {
			// DSLR 연산처리
			node nextValue = go2(curValue, i);

			// 골인지점
			if (nextValue.value == b) {
				cout << nextValue.str << '\n';
				return;
			}
			else if (visit[nextValue.value]) {
				continue;
			}
			else {
				q.push(nextValue);
				visit[nextValue.value] = true;
			}
		}
	}
}
void init() {
	for (int i = 0; i < 10000; ++i)
		visit[i] = false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		go();	// 확인
		init();
	}

	return 0;
}