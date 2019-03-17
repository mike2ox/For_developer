#include<iostream>
#include<string>
#include<queue>
using namespace std;

int c, b;
int t = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> c >> b;
	queue<int> que;
	int q_l = 1;
	que.push(b);

	while (!que.empty()) {
		int b_point = que.front();
		que.pop();
		q_l--;
		
		//코니 이동
		++t;
		c = c + t;
		
		for (int db = 0; db < 3; db++) {
			int nb;
			switch (db)
			{
			case 0:
				nb = b_point - 1;
				break;
			case 1:
				nb = b_point +1;
				break;
			case 2:
				nb = 2* b_point;
				break;
			}

			//브라운이 코니 잡았을 시
			if (c == nb) {
				cout << t << '\n';
				system("pause");
				return 0;
			}
			//코니가 범위를 벗어갈 경우
			if (c > 200000) {
				cout << "-1" << '\n';
				system("pause");
				return 0;
			}
			que.push(nb);
			
		}
		if (q_l != 0) {
			c = c - t;
			--t;
		}
		else
			q_l = que.size();
	}


	system("pause");
	return 0;

}
//bfs문제