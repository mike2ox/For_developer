// BOJ no. 16947, mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> subway[3001];
bool visit[3001];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n;
	int startV, endV;
	int crossV=1;

	for (int i = 0; i < n; ++i) {
		cin >> startV >> endV;
		subway[startV].push_back(endV);
		subway[endV].push_back(startV);
		
		// if (subway[startV].size() > 2 || subway[endV].size() > 2)
		//	cout << startV << "~~~" << endV <<'\n';
	}
	// cout << crossV << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << i << " : ";
		for (int j = 1; j <= subway[i].size(); ++j) {
			cout << subway[i][j] << " ";
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}