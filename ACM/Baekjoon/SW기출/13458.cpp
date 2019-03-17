/*
*	author : mike2ox
*	BOJ : 13458
*	descript : https://www.acmicpc.net/problem/13458
*	type : �Ｚ����
*	hint :
*/
#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int room;
	// �� ������ ������ �Ѹ�, �� ������ ������ ����
	// �� ����, �� ������ ������ �� �ִ� ������ ��
	int main_adm; int sub_adm;
	// �ּ����� ������ ��
	long long cnt = 0;
	// �ִ� ������ 1000000��
	int stu[100001];

	cin >> room;
	
	// �溰 ������ ��
	for (int i = 0; i < room; ++i)
		cin >> stu[i];
	cin >> main_adm >> sub_adm;

	for (int i = 0; i < room; ++i) {
		stu[i] = stu[i] - main_adm;	//�� ������ ���� �������� �ΰ��� ����
		cnt++;

		// ������ ������ ��
		if(stu[i] > 0) {
			if (stu[i] % sub_adm == 0) { // �� ������ ���
				cnt += (stu[i] / sub_adm);
			}
			else {							//1�� �� �ʿ��� ���
				cnt += (stu[i] / sub_adm) + 1;
			}
		}
	}

	cout << cnt << '\n';
	system("pause");
	return 0;
}