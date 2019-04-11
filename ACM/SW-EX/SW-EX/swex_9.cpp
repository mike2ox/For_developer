/*
*	author : mike2ox
*	swex : ���� �Ҹ� �ùķ��̼�
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : BFS + �ùķ��̼�
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

		//������ ���� ��ġ���� ���� ����
		for (int i = 0; i < size; i++) {

			map[atoms[i].y][atoms[i].x] = 0;
			
			// ����
			int dir = atoms[i].dir;
			int nx = atoms[i].x + dx[dir];
			int ny = atoms[i].y + dy[dir];
			
			// �������϶�
			if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
				atoms[i].energy = 0;
				continue;
			}
			atoms[i].x = nx;
			atoms[i].y = ny;
			map[ny][nx] += atoms[i].energy;
		}
		//�浹�� ���� Ȯ��.
		for (int i = 0; i < size; i++) {
			if (atoms[i].energy == 0)
				continue;

			int x = atoms[i].x;
			int y = atoms[i].y;

			// �浹
			if (map[y][x] != atoms[i].energy) {
				totalEnergy += map[y][x];
				map[y][x] = 0;
				atoms[i].energy = 0;
			}
		}
		
		//���� ����Ʈ�� ����(vector�� ����)
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

			// ��ġ ����
			atom.x += 1000;
			atom.y += 1000;
			// 0.5�ʿ� ������ ���ڵ� ����� 4000*4000���� �ٲ�
			atom.x *= 2;
			atom.y *= 2;

			atoms.push_back(atom);
		}
		cout << "#" << t << " " << calcTotalEnergy() << "\n";
	}
	return 0;
}
/*
�� �� �̻��� ���ڰ� �浹 �� ��� �浹�� ���ڵ��� ���� ������ �������� ��� �����ϰ� �Ҹ�.

������ ������
1. ������ ���� ��ġ�� 2���� ������ [x, y]
2. ���ڴ� ���� ������ �����̴� ������ ������ �ִ�. (�����¿� 4����)
 - ��: y �� �����ϴ� ����
 - ��: y �� �����ϴ� ����
 - ��: x �� �����ϴ� ����
 - ��: x �� �����ϴ� ����

3. ��� ���ڵ��� �̵��ӵ��� �����ϴ�. ��, 1�ʿ� 1��ŭ�� �Ÿ��� �̵��Ѵ�.
4. ��� ���ڵ��� ���� ��ġ���� ���ÿ� �̵��� �����Ѵ�.
5. �� �� �̻��� ���ڰ� ���ÿ� �浹 �� ��� �浹�� ���ڵ��� ��� ������ �������� �����ϰ� �Ҹ�ȴ�.

output : ���ڵ��� �Ҹ�Ǹ鼭 �����ϴ� �������� ����
*/