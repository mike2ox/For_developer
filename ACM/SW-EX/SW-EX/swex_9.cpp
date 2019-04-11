/*
*	author : mike2ox
*	swex : 원자 소멸 시뮬레이션
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : BFS + 시뮬레이션
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

struct Atom {
	int x;
	int y;
	int dir;
	int energy;
};

int N;

vector<Atom> atoms;
int map[4001][4001];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int calcTotalEnergy() {

	int totalEnergy = 0;

	while (!atoms.empty()) {

		int size = (int)atoms.size();

		//원자의 다음 위치들을 전부 갱신
		for (int i = 0; i < size; i++) {

			map[atoms[i].y][atoms[i].x] = 0;
			
			// 갱신
			int dir = atoms[i].dir;
			int nx = atoms[i].x + dx[dir];
			int ny = atoms[i].y + dy[dir];
			
			// 범위밖일때
			if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
				atoms[i].energy = 0;
				continue;
			}
			atoms[i].x = nx;
			atoms[i].y = ny;
			map[ny][nx] += atoms[i].energy;
		}
		//충돌인 지역 확인.
		for (int i = 0; i < size; i++) {
			if (atoms[i].energy == 0)
				continue;

			int x = atoms[i].x;
			int y = atoms[i].y;

			// 충돌
			if (map[y][x] != atoms[i].energy) {
				totalEnergy += map[y][x];
				map[y][x] = 0;
				atoms[i].energy = 0;
			}
		}
		
		//원자 리스트를 갱신(vector로 구현)
		vector<Atom> tempVector;
		tempVector.assign(atoms.begin(), atoms.end());
		atoms.clear();
		
		int tempVectorSize = (int)tempVector.size();

		for (int i = 0; i < tempVectorSize; i++) {
			if (tempVector[i].energy != 0) {
				atoms.push_back(tempVector[i]);
			}
		}
	}
	return totalEnergy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			Atom atom;
			cin >> atom.x >> atom.y >> atom.dir >> atom.energy;

			// 위치 조정
			atom.x += 1000;
			atom.y += 1000;
			// 0.5초에 만나는 원자들 고려해 4000*4000으로 바꿈
			atom.x *= 2;
			atom.y *= 2;

			atoms.push_back(atom);
		}
		cout << "#" << t << " " << calcTotalEnergy() << "\n";
	}
	return 0;
}
/*
두 개 이상의 원자가 충돌 할 경우 충돌한 원자들은 각자 보유한 에너지를 모두 방출하고 소멸.

원자의 움직임
1. 원자의 최초 위치는 2차원 평면상의 [x, y]
2. 원자는 각자 고유의 움직이는 방향을 가지고 있다. (상하좌우 4방향)
 - 상: y 가 증가하는 방향
 - 하: y 가 감소하는 방향
 - 좌: x 가 감소하는 방향
 - 우: x 가 증가하는 방향

3. 모든 원자들의 이동속도는 동일하다. 즉, 1초에 1만큼의 거리를 이동한다.
4. 모든 원자들은 최초 위치에서 동시에 이동을 시작한다.
5. 두 개 이상의 원자가 동시에 충돌 할 경우 충돌한 원자들은 모두 보유한 에너지를 방출하고 소멸된다.

output : 원자들이 소멸되면서 방출하는 에너지의 총합
*/