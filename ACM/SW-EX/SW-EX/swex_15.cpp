
/*
*   author : mike2ox
*   swex : 활주로 건설
*   descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*   type : 완전 탐색(DFS)
*	hint : 다음위치를 k만큼 깎을 수 있을때 --> 최소한으로 깎고 난뒤에 DFS
*/
#include<iostream>
using namespace std;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int map[8][8];
int visited[8][8];
int len;
int _max;
int n, k;
int tc;

void go(int i, int j, int cnt, bool _k) {
	visited[i][j] = 1;

	for (int x = 0; x < 4; x++) {
		// 경계
		if (i + dx[x] >= 0 && i + dx[x] < n && j + dy[x] >= 0 && j + dy[x] < n && visited[i+dx[x]][j + dy[x]] == 0) {

			//높이 비교
			if (map[i][j] > map[i + dx[x]][j + dy[x]]) {
				go(i + dx[x], j + dy[x], cnt + 1, _k);
			}
			else if (map[i][j] <= map[i + dx[x]][j + dy[x]] && _k) {
				//이동전후의 산의 높이 차가 k보다 작을 시
				if (k > map[i + dx[x]][j + dy[x]] - map[i][j]) {
					_k = false;
					int temp = map[i + dx[x]][j + dy[x]];

					map[i + dx[x]][j + dy[x]] = map[i][j] - 1;
					go(i + dx[x], j + dy[x], cnt + 1, _k);	//깎기 시작
					map[i + dx[x]][j + dy[x]] = temp;
					
					_k = true;
				}
			}
		}
	}
	visited[i][j] = 0;
	if (len < cnt) {
		len = cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		len = 0;
		_max = 0;
		cin >> n >> k;

		//map 갱신
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				visited[i][j] = 0;
				if (map[i][j] > _max)
					_max = map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == _max)
					go(i, j, 1, true);
			}
		}
		cout << "#" << t << " " << len << '\n';
	}
	return 0;
}

/*
1. 시간 제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초
2. 지도의 한 변의 길이 N은 3 이상 8 이하의 정수이다. (3 ≤ N ≤ 8)
3. 최대 공사 가능 깊이 K는 1 이상 5 이하의 정수이다. (1 ≤ K ≤ 5)
4. 지도에 나타나는 지형의 높이는 1 이상 20 이하의 정수이다.
5. 지도에서 가장 높은 봉우리는 최대 5개이다.
6. 지형은 정수 단위로만 깎을 수 있다.
7. 필요한 경우 지형을 깎아 높이를 1보다 작게 만드는 것도 가능하다.

*/