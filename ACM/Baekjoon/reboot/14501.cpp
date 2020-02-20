// BJO no. 14501 Επ»η, mike2ox(2020)
// 
#include<iostream>
using namespace std;

int n, maxCost, maxMeet;
struct meeting {
	int time;
	int cost;
};
meeting meetingTable[16];
void go(int idx, int sum, int cntMeet) {
	if (idx+meetingTable[idx].time == n) {
		if (cntMeet+meetingTable[idx].time >= maxMeet
			&&sum-meetingTable[idx].cost>=maxCost) {
			maxMeet = cntMeet;
			maxCost = sum;
			return;
		}
	}
	else if (idx + meetingTable[idx].time > n) {
		if (cntMeet - meetingTable[idx].time >= maxMeet
			&& sum - meetingTable[idx].cost >= maxCost) {
			maxMeet = cntMeet;
			maxCost = sum;
			return;
		}
	}

	for (int j = idx + meetingTable[idx].time; j <= n; ++j) {
		go(j, sum + meetingTable[j].cost,cntMeet+meetingTable[j].time);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ti, pi;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> meetingTable[i].time >> meetingTable[i].cost;
	}

	for (int i = 1; i <= n; ++i) {
		if (i + meetingTable[i].time >= n)
			continue;
		go(i, meetingTable[i].cost ,meetingTable[i].time);
	}
	cout << maxCost << '\n';
	return 0;
}