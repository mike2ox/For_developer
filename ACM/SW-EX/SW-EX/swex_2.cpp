/*
*	author : mike2ox
*	swex : 활주로 건설
*	descript : https://www.swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*	type : 완전 탐색
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
			
			// 가로행
			int cnt = 1; // 높이가 같은 타일 수

			for (int j = 1; j < n; j++) {
				//바로 앞에꺼와 현재꺼를 비교
				int prev = arr[i][j - 1];
				int cur = arr[i][j];

				// 높이가 같으면
				if (prev == cur)
					cnt++;
				// 내리막이면
				else if (prev - cur == 1 && cnt >= 0)
					cnt = -len + 1;
				// 오르막이면
				else if (prev - cur == -1 && cnt >= len)
					cnt = 1;
				else {
					cnt = -1;
					break;
				}
			}
			if (cnt >= 0)
				result++;

			// 세로행
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