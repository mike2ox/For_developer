// BJO no.1963, mike2ox(2020)
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int tc;
int start, goal;
bool prime[10001];
int check[10001];

int strToint(string value) {
	int ret = 0;
	for (int i = 0; i <4; ++i) {
		ret += value[i] * 10;
	}
	return ret;
}
void eratos() {
	for (int i = 2; i * i < 10001; i++) {
		for (int j = i * i; j < 10001; j += i)
			prime[j] = true;	//소수가 아닌 것들 다 true
	}
}
void init() {
	for (int i = 0;i<10001;++i){
		check[i] = -1;
	}
}
void bfs(int value) {
	queue<int> q;
	q.push(value);
	check[value] = 0;

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			string node = to_string(value);
			for (int j = 0; j < 10; ++j) {
				node[i] = j + '0';
				int nextNode = strToint(node);

				if (nextNode>=1000 && prime[nextNode] == false && check[nextNode] == -1) {
					check[nextNode] = check[node] + 1;
					q.push(nextNode);
				}
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc;
	eratos();

	while (tc--) {
		init();
		cin >> start >> goal;

		bfs(start);
	}
	return 0;
}