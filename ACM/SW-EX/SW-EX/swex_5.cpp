/*
*	author : mike2ox
*	swex : 보물상자 비밀번호
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : 완전 탐색
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

char arr[30];
int dab[30*30*30];
int T, N, K, pos;

void rotate(){
	char tmp = arr[0];

	for (int i = 1; i < N; i++)
		arr[i - 1] = arr[i];

	arr[N - 1] = tmp;
}

bool compare(const int i, const int j){
	return i > j;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K;
		cin >> arr;

		int len = N / 4;

		pos = -1;
		map <string, int> check;

		for (int t = 0; t < len; t++){
			for (int i = 0; i < N; i += len){

				char tmp[8] = { 0 };
				int st = -1;

				for (int j = i; j < i + len; j++) 
					tmp[++st] = arr[j];
				
				if (!check[tmp]){
					int s = 0;
					for (int j = 0; j < len; j++){
						if ('A' <= tmp[j] && tmp[j] <= 'F')
							s += (tmp[j] - 'A' + 10) * pow(16, len - j - 1);
						else 
							s += (tmp[j] - '0') * pow(16, len - j - 1);
					}
					check[tmp] = 1;
					dab[++pos] = s;
				}
			}
			rotate();
		}
		sort(dab, dab + (pos + 1), compare);

		cout << "#" << tc << " " << dab[K - 1] << '\n';
	}

	return 0;
}
/*

문자열을 돌려주면 쉽게 해결(톱니바퀴)

입력되는 문자열을 N/4만큼씩 잘라서 검사
map으로 문자열을 저장하면 하나의 문자열을 인덱스처럼 사용할 수 있기 때문
이 인덱스에 해당하는 문자열이 존재한다면 dab배열에 담지 않고, 없다면 잘라준 문자열을 16진수 -> 10진수로 바꾸어 dab 배열에 담아준다.
dab배열을 내림차순 정렬
K-1번째 숫자를 출력
*/