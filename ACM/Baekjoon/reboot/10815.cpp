// BJO no.10815 ����ī��, mike2ox(2020)
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
	// �����ϰ� �ִ� ���� ī���
	for (int i = 0; i < n; ++i) {
		cin >> inputData;
		numCard.push_back(inputData);
	}
	
	cin >> m;
	ret = new int[m];
	// ���� üũ����Ʈ
	for (int i = 0; i < m; ++i) {
		cin >> inputData;
		numbers.push_back({ i ,inputData });
		//ret[i] = 0;
	}

	sort(numCard.begin(), numCard.end());
	sort(numbers.begin(), numbers.end(), compare);
	
	int j = 0;// L40 ����
	for (int i = 0; i < numCard.size(); ++i) {
		// �ٽ� �湮���� �ʵ��� j�� �ʱ�ȭ�� �ʵ��� ����.
		for (; j < numbers.size(); ++j) {
			// ���� ��� ����
			if (numCard[i] == numbers[j].second) {
				ret[numbers[j].first] = 1;
				++j;
				break;
			}
			// �����ִ� ���ں��� üũ����Ʈ ���ڰ� Ŭ ���
			else if (numCard[i] < numbers[j].second) {
				break;
			}
			else {// �����ִ� ���ں��� üũ����Ʈ ���ڰ� ������� -> �ٽ� �湮���� ����
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