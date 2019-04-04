/*
*	author : mike2ox
*	swex : �������� ��й�ȣ
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : ���� Ž��
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

���ڿ��� �����ָ� ���� �ذ�(��Ϲ���)

�ԷµǴ� ���ڿ��� N/4��ŭ�� �߶� �˻�
map���� ���ڿ��� �����ϸ� �ϳ��� ���ڿ��� �ε���ó�� ����� �� �ֱ� ����
�� �ε����� �ش��ϴ� ���ڿ��� �����Ѵٸ� dab�迭�� ���� �ʰ�, ���ٸ� �߶��� ���ڿ��� 16���� -> 10������ �ٲپ� dab �迭�� ����ش�.
dab�迭�� �������� ����
K-1��° ���ڸ� ���
*/