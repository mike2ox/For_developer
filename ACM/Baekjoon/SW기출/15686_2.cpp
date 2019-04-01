/*
*	author : mike2ox
*	BOJ : 15686
*	descript : https://www.acmicpc.net/problem/15686
*	type : 삼성 기출 : bfs
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct xy {
	int y, x;
};

int n, m, type, ret;
vector<xy> house, shop, pick;//shop = n이고 m개를 뽑아서 pick에 push

// 중요! bfs
void dfs(int pos) {
	if (pick.size() == m) {

		int temp = 0;
		for (int i = 0; i < house.size(); ++i) {
			//최소 거리를 구해주기위해 큰 값 선언
			int min_dist = 10000000;

			//
			for (int j = 0; j < pick.size(); ++j) 
				min_dist = min(min_dist, abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
			
			temp += min_dist;
		}

		if (ret > temp) {
			ret = temp;
		}

		return;
	}

	for (int i = pos; i < shop.size(); ++i) {
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	xy target;
	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> type;


			if (type == 1) {
				target.y = y, target.x = x;
				house.push_back(target);
			}
			if (type == 2) {
				target.y = y, target.x = x;
				shop.push_back(target);
			}
		}
	}

	ret = 0x7fffffff;

	dfs(0);
	cout << ret << '\n';

	return 0;
}
/*
크기가 N×N. 도시는 1×1크기

도시의 각 칸은 빈 칸, 치킨집, 집 중 하나
도시의 칸은 (r, c), r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다.
r과 c는 1부터 시작한다.

치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다.
즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다.
도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

0은 빈 칸, 1은 집, 2는 치킨집이다.

치킨집의 개수는 최대 M개
도시의 치킨 거리가 가장 작게 될지 구하는 프로그램
*/