/*
*	author : mike2ox
*	swex : ���� �Ļ�ð�
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : dfs+���� Ž��
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define p pair<int,int>
using namespace std;

int map[10][10] = { 0, };
int dir[10] = { 0, };
int n, ans;

vector<p> pos_stairs; // position of stairs
vector<int> time_stairs;
vector<p> pos_people; // position of people



void solve() {
	int time = 0;
	int size = (int)pos_people.size();
	int to_exit_people = size;

	vector<int> people;
	queue<int> stairs[2];

	// �� ������� ��ǥ ��ܱ����� �Ÿ� ���ϱ�
	for (int i = 0; i < size; i++) {
		int _x, _y;
		_x = abs(pos_people[i].first - pos_stairs[dir[i]].first);
		_y = abs(pos_people[i].second - pos_stairs[dir[i]].second);
		people.push_back(_x + _y + 1); // ���� �� 1���� ������ ������ �� �ֱ� ������ +1
	}

	while (to_exit_people) {
		time++;

		for (int i = 0; i < size; i++) {
			// [1]
			if (people[i] == -1)
				continue;
			// people[i] - 1 == 0 �� 1�� �� ������� ������ �� �ִ� ���
			// people[i] == 0 �� �ٷ� ������ �� �ִµ� ����� Full�̶� ���������� ���
			else if (people[i] - 1 == 0 || people[i] == 0) {
				if (stairs[dir[i]].size() < 3) {
					stairs[dir[i]].push(time_stairs[dir[i]]);
					people[i] = -1;
				}
			}
			else {
				people[i] --;
			}
		}

		int queue_size = (int)stairs[0].size();
		while (queue_size--) {
			int top = stairs[0].front();
			stairs[0].pop();
			top--;
			if (top == 0)
				to_exit_people--;
			else {
				stairs[0].push(top);
			}
		}

		queue_size = (int)stairs[1].size();
		while (queue_size--) {
			int top = stairs[1].front();
			stairs[1].pop();
			top--;
			if (top == 0)
				to_exit_people--;
			else {
				stairs[1].push(top);
			}
		}

	} 
	
	if (ans > time)
		ans = time;
}

void dfs(int idx) {
	if (idx == pos_people.size()) {
		solve();
	}
	else {
		for (int i = 0; i < 2; i++) {
			dir[idx] = i;
			dfs(idx + 1);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> n;
		ans = 2e9;

		//�ʱ�ȭ
		pos_stairs.clear();
		time_stairs.clear();
		pos_people.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					pos_people.push_back({ i,j });
				else if (map[i][j] > 1) {
					pos_stairs.push_back({ i,j });
					time_stairs.push_back(map[i][j]);
				}
			}
		}
		dfs(0);

		cout << "#" << tc << " " << ans + 1 << '\n';
	}

	return 0;
}