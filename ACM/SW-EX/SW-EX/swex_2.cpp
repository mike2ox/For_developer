/*
*	author : mike2ox
*	swex : Ȱ�ַ� �Ǽ�
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : ���� Ž��
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int tc;
	int n, len;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		
		cin >> n >> len;
		vector<vector<int> > arr(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		int result = 0;

		for (int i = 0; i < n; i++) {
			
			// ������
			int cnt = 1; // ���̰� ���� Ÿ�� ��

			for (int j = 1; j < n; j++) {
				//�ٷ� �տ����� ���粨�� ��
				int prev = arr[i][j - 1];
				int cur = arr[i][j];

				// ���̰� ������
				if (prev == cur)
					cnt++;
				// �������̸�
				else if (prev - cur == 1 && cnt >= 0)
					cnt = -len + 1;
				// �������̸�
				else if (prev - cur == -1 && cnt >= len)
					cnt = 1;
				else {
					cnt = -1;
					break;
				}
			}
			if (cnt >= 0)
				result++;

			// ������
			cnt = 1;

			for (int j = 1; j < n; j++) {
				int prev = arr[j - 1][i];
				int cur = arr[j][i];
				if (prev == cur)
					cnt++;
				else if (prev - cur == 1 && cnt >= 0)
					cnt = -len + 1;
				else if (prev - cur == -1 && cnt >= len)
					cnt = 1;
				else {
					cnt = -1;
					break;
				}
			}
			if (cnt >= 0)
				result++;
		}

		cout << "#" << k << " " << result << "\n";
	}

	return 0;
}