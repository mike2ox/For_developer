// BJO no.10816 숫자카드2, mike2ox(2020)
// 1. 이분탐색 2. 정렬 후 비교
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> numCards;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int inputData = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> inputData;
		numCards.push_back(inputData);
	}
	sort(numCards.begin(), numCards.end());

	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> inputData;
		int head = 0;
		int rear = numCards.size()-1;
		int mid = head + rear / 2;

		while (mid!= head) {
			if (numCards[mid] < inputData) {
				head = mid;
				mid = (head + rear + 1) / 2;
			}
			else if (numCards[mid] > inputData) {
				rear = mid;
				mid = (head + rear) / 2;
			}
			else {
				while (numCards[mid] > numCards[head]) {
					head = (head + mid+1) / 2;
				}
				while (numCards[mid] < numCards[rear]) {
					rear = (rear + mid) / 2;
				}
				break;
			}
		}

		int cnt = rear - head + 1;

		if (mid == head && numCards[mid] != inputData)
			v.push_back(0);
		else
			v.push_back(cnt);
	}

	for (auto au : v)
		cout << au << ' ';
	cout << '\n';
	return 0;
}