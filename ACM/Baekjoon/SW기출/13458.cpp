/*
*	author : mike2ox
*	BOJ : 13458
*	descript : https://www.acmicpc.net/problem/13458
*	type : 삼성기출
*	hint :
*/
#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int room;
	// 총 감독은 무조건 한명, 부 감독은 여러명 가능
	// 총 감독, 부 감독이 관리할 수 있는 응시자 수
	int main_adm; int sub_adm;
	// 최소한의 감독관 수
	long long cnt = 0;
	// 최대 응시자 1000000명
	int stu[100001];

	cin >> room;
	
	// 방별 수험자 수
	for (int i = 0; i < room; ++i)
		cin >> stu[i];
	cin >> main_adm >> sub_adm;

	for (int i = 0; i < room; ++i) {
		stu[i] = stu[i] - main_adm;	//총 감독을 빼고 나머지를 부감독 관리
		cnt++;

		// 응시자 존재할 때
		if(stu[i] > 0) {
			if (stu[i] % sub_adm == 0) { // 딱 떨어질 경우
				cnt += (stu[i] / sub_adm);
			}
			else {							//1명 더 필요할 경우
				cnt += (stu[i] / sub_adm) + 1;
			}
		}
	}

	cout << cnt << '\n';
	system("pause");
	return 0;
}