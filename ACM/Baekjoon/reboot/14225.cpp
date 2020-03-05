// BJO no.14225 부분집합의 합 , mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n, minsum=123456789;
int* s;
bool visit[2000001]; // 20 * 100000

void go(int nextIdx, int subSum) {
	if (!visit[subSum]) {
		visit[subSum] = true;
	}
	if (nextIdx == n)
		return;

	for (int i = nextIdx; i < n; ++i) {
		go(i + 1, subSum + s[i]);
	}

}
void checkMin() {
	for (int i = 1; i < 2000001; ++i) {
		if (!visit[i]) {
			cout << i << '\n';
			return;
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	s = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> s[i];
	
	// solution
	for(int i=0;i<n;++i)
		go(i+1, s[i]);

	checkMin();

	return 0;
}