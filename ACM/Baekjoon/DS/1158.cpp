/*
*	author : mike2ox
*	BOJ : 1158
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int n, m;
	queue<int> josephus;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		josephus.push(i+1);
	
	cout << '<';

	while (!josephus.empty()) {
		for (int i = 0; i < m - 1; i++) {
			josephus.push(josephus.front());
			josephus.pop();
		}
		cout << josephus.front();
		josephus.pop();

		if (!josephus.empty())
			cout << ", ";
	}

	cout << '>' << '\n';
	system("pause");
	return 0;
}
/*
	조세퍼스의 정의를 알고 있어야함
	circle queue 구현할 줄 알면 됨
*/