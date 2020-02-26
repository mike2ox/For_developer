// BJO no.10815 숫자카드, mike2ox(2020)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> numCard;
vector<pair<int, int>> numbers;
bool compare(const pair<int, int> a, const pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int inputData = 0;
	int* ret;

	cin >> n;
	// 소유하고 있는 숫자 카드들
	for (int i = 0; i < n; ++i) {
		cin >> inputData;
		numCard.push_back(inputData);
	}
	
	cin >> m;
	ret = new int[m];
	// 숫자 체크리스트
	for (int i = 0; i < m; ++i) {
		cin >> inputData;
		numbers.push_back({ i ,inputData });
		//ret[i] = 0;
	}

	sort(numCard.begin(), numCard.end());
	sort(numbers.begin(), numbers.end(), compare);
	
	int j = 0;// L40 참조
	for (int i = 0; i < numCard.size(); ++i) {
		// 다시 방문하지 않도록 j를 초기화지 않도록 만듬.
		for (; j < numbers.size(); ++j) {
			// 같을 경우 저장
			if (numCard[i] == numbers[j].second) {
				ret[numbers[j].first] = 1;
				++j;
				break;
			}
			// 갖고있는 숫자보다 체크리스트 숫자가 클 경우
			else if (numCard[i] < numbers[j].second) {
				break;
			}
			else {// 갖고있는 숫자보다 체크리스트 숫자가 작을경우 -> 다시 방문하지 않음
				ret[numbers[j].first] = 0;
				continue;
			}
		}
	}

	for (int i = 0; i < m; ++i)
		cout << ret[i] << ' ';
	cout << '\n';

	delete [] ret;

	return 0;
}