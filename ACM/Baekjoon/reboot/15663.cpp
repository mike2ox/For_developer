// BJO no. 15663, mike2ox(2020)
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> v;
vector<int> v3;
vector<string> v2;
bool visit[10001];
void go(int result, int cnt) {
	if (cnt == m) {
		string str = "";
		for (auto au : v3) {
			str += to_string(au);
			str += " ";
		}
		v2.push_back(str);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (visit[i])
			continue;
		visit[i] = true;
		v3.push_back(v[i]);
		go(result*10 + v[i], cnt+1);
		v3.pop_back();
		visit[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int inputData;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> inputData;
		v.push_back(inputData);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		visit[i] = true;
		v3.push_back(v[i]);
		go(v[i],1);
		v3.pop_back();
		visit[i] = false;
	}
	sort(v2.begin(), v2.end());
	int v2Size = v2.size();

	for (int i = 0; i < v2Size; ++i) {
		if (i + 1 != v2Size) {
			if (v2[i] == v2[i + 1]) {
				continue;
			}
			else {
				cout << v2[i] << '\n';
			}
		}
		else {
			cout << v2[i] << '\n';
		}
	}

	return 0;
}