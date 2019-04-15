/*
*	author : mike2ox
*	swex : ���� ����
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : �ùķ��̼�
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define abs(x) (x > 0 ? (x) : -(x))
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
	return a > b;
}
// 
typedef struct AP {
	int x, y, c, p;
};

//������
AP ap[8];

const int dx[] = { 0,-1,0,1,0 };
const int dy[] = { 0,0,1,0,-1 };

int M, A, move_A[100], move_B[100];

int x, y, c, p;
int map[11][11] = { 0 };
int eng = 0;
int ax = 1, ay = 1;
int bx = 10, by = 10;

vector<pair<int, int>> v1, v2;

void check(int ax, int ay, int bx, int by) {
	//A,B�� ���� ��� ������ �˻�
	for (int i = 0; i < A; i++) {
		int dist_A = abs(ax - ap[i].x) + abs(ay - ap[i].y);
		int dist_B = abs(bx - ap[i].x) + abs(by - ap[i].y);

		if (dist_A <= ap[i].c) {
			v1.push_back(make_pair(ap[i].p, i));
		}
		if (dist_B <= ap[i].c) {
			v2.push_back(make_pair(ap[i].p, i));
		}
	}
	sort(v1.begin(), v1.end(), desc);
	sort(v2.begin(), v2.end(), desc);

	if (v1.empty() && v2.empty())
		return;//�� �� 0��
	else if (v1.empty()) {
		eng += v2.front().first;
		return;
	}//A�� 0�� B�� 1�� �̻�

	else if (v2.empty()) {
		eng += v1.front().first;
		return;
	}//A�� 1�� �̻� B�� 0��

	else {
		//�ִ��� ���� ��
		if (v1.front() == v2.front()) {
			// A�� 1��, B�� 1��
			if (v1.size() == 1 && v2.size() == 1) {
				if (v1.front().second == v2.front().second)
					//������ ����
					eng += v1.front().first;
				else {
					eng += v1.front().first;
					eng += v2.front().first;
				}
			}
			//A�� 1��, B�� 2�� �̻�
			else if (v1.size() == 1) {
				if (v1.front().second == v2.front().second) {
					eng += v1[0].first;
					eng += v2[1].first;
				}
				else {
					eng += v1.front().first;
					eng += v2.front().first;
				}
			}
			//B�� 1��, A�� 2�� �̻�
			else if (v2.size() == 1) {
				if (v1.front().second == v2.front().second) {
					eng += v1[1].first;
					eng += v2[0].first;
				}
				else {
					eng += v1.front().first;
					eng += v2.front().first;
				}
			}
			else {
				if (v1.front().second == v2.front().second) {
					eng += v1.front().first;
					eng += max(v1[1].first, v2[1].first);
				}
			}
		}
		//�ִ��� �ٸ� ��
		else {
			eng += v1.front().first;
			eng += v2.front().first;
		}
	}
}

void move(int za, int zb) {
	ax += dx[za];
	ay += dy[za];
	bx += dx[zb];
	by += dy[zb];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc){
		ax = 1, ay = 1, bx = 10, by = 10;
		eng = 0;
		//�̵��ð�, �����ⰹ��
		cin >> M >> A;

		//�̵�����
		for (int i = 0; i < M; i++) {
			cin >> move_A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> move_B[i];
		}

		//������ ����
		for (int j = 0; j < A; j++) {
			cin >> x >> y >> c >> p;
			ap[j] = { y,x,c,p };
		}
		for (int i = 0; i <= M; i++) {
			check(ax, ay, bx, by);
			v1.clear();
			v2.clear();
			move(move_A[i], move_B[i]);
		}
		cout << "#" << tc << ' ' << eng << '\n';
	}
	return 0;
}
/*
BC�� ������ ������� �̵� ������ �־����� ��, ��� ����ڰ� ������ ���� ���� �ִ�?

���ʸ��� Ư�� BC�� ���� ������ �ȿ� ������ �ش� BC�� ������ �����ϴ�. 
���� T=5�� ����� A�� BC 3��, ����� B�� BC 2�� ������ �� �ִ�. 
�̶�, ������ BC�� ����(P)��ŭ ���͸��� ���� �� �� �ִ�. 
���� �� BC�� �� ���� ����ڰ� ������ ���, ������ ������� ����ŭ ���� ���� �յ��ϰ� �й��Ѵ�

1. ������ ����, ���� ũ��� 10�̴�.
2. ����ڴ� �� 2���̸�, �����A�� ������ (1, 1) ��������, �����B�� ������ (10, 10) �������� ����Ѵ�.
3. �� �̵� �ð� M�� 20�̻� 100������ �����̴�. (20 �� M �� 100)
4. BC�� ���� A�� 1�̻� 8������ �����̴�. (1 �� A �� 8)
5. BC�� ���� ���� C�� 1�̻� 4������ �����̴�. (1 �� C �� 4)
6. BC�� ���� P�� 10�̻� 500������ ¦���̴�. (10 �� P �� 500)
7. ������� �ʱ� ��ġ(0��)���� ������ �� �� �ִ�.
8. ���� ��ġ�� 2�� �̻��� BC�� ��ġ�� ���� ����. �׷��� �����A, B�� ���ÿ� ���� ��ġ�� �̵��� ���� �ִ�. ����ڰ� ���� ������ �̵��ϴ� ���� ����

*/