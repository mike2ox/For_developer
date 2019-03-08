/*
*	author : mike2ox
*	BOJ : 4963
*	descript : https://www.acmicpc.net/problem/4963
*	type : �˰��� ���� : dfs
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

const int dy[] = {0,0,-1,1,1,-1,1,-1};
const int dx[] = {-1,1,0,0,1,1,-1,-1};

int map[51][51] = { 0, };
int h, w, cnt;

void dfs(int y, int x) {
	
	map[y][x] = 0;

	//
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (nx < 0 || nx >= w || ny < 0 || ny >= h) 
			continue;
		if (map[ny][nx])
			dfs(ny, nx);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		cnt = 0;
		cin >> w >> h;

		//end 
		if (w == 0 && h == 0)
			break;

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> map[y][x];
			}
		}
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[y][x]) {
					dfs(y, x);
					cnt++;
				}
			}
		}


		cout << cnt << '\n';

	}

	system("pause");
	return 0;
}
//����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.
//�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� ��ΰ� �־�� �Ѵ�.
//������ �ٴٷ� �ѷ��׿� ������, ���� ������ ���� �� ����.
//�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �ʺ� w�� ���� h�� �־�����.
//w�� h�� 50���� �۰ų� ���� ���� �����̴�.
//��° �ٺ��� h�� �ٿ��� ������ �־�����. 1�� ��, 0�� �ٴ�
//�Է��� ������ �ٿ��� 0�� �� �� �־�����.
//�� �׽�Ʈ ���̽��� ���ؼ�, ���� ������ ����Ѵ�.