// BJO no. 15663, mike2ox(2020)
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int dataInput[9];
int dataOutput[9];
int visit[10001];

void go(int idx, int cnt) {
	if (cnt == m) {
		for (int j = 0; j < m; ++j)
			cout << dataOutput[j] << ' ';
		cout << '\n';
		return;
	}
	for (int j = idx; j < n; ++j) {
		if (dataOutput[cnt] <= dataInput[j]&&
			visit[dataInput[j]]>0) {
		
			dataOutput[cnt] = dataInput[j];
			--visit[dataInput[j]];
			go(j, cnt + 1);
			++visit[dataInput[j]];
			dataOutput[cnt] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> dataInput[i];
		visit[dataInput[i]]++;
	}

	sort(dataInput, dataInput + n);

	for (int i = 0; i < n; ++i) {
		if (visit[dataInput[i]]==0)
			continue;
		--visit[dataInput[i]];
		dataOutput[0] = dataInput[i];
		go(i,1);
		dataOutput[0] = dataInput[i];
		++visit[dataInput[i]];
	}

	return 0;
}