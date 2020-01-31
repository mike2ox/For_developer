// BOJ no. 16947, mike2ox(2020)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, point;
vector<int> subway[3001];
vector<int> route;
bool visit[3001];
bool flag;
struct node{
	int preStation, station;
	vector<int> v;
};

void dfs(node info) {
	if (visit[info.station]) {
		point = info.station;
		route.clear();
		
		for (int i = 0; i < info.v.size(); ++i) {
			if (info.v[i] == point) {
				for (int j = i; j < info.v.size() - 1; ++j)
					route.push_back(info.v[j]);
			}
		}

		flag = true;	//순환 방지
		return;
	}

	visit[info.station] = true;
	// preStation = station;

	for (int i = 0; i < subway[info.station].size(); ++i) {
		int nextStation = subway[info.station][i];

		if (nextStation == info.preStation)
			continue;
		if (flag)
			return;
		info.v.push_back(nextStation);
		dfs({ info.station, nextStation, info.v});
	}
}
void dfs2() {
	// route : 싸이클
	// point : 교착점
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int startV, endV;
		cin >> startV >> endV;

		subway[startV].push_back(endV);
		subway[endV].push_back(startV);
	}
	route.push_back(1);
	dfs({ 1,1,route});
	// 초기화
	for (int i = 0; i < n; ++i)
		visit[i] = false;

	dfs2();

	return 0;
}