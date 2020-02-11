// BJO no. 15661 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> a, b;
int score[21][21];
bool visit[21];
bool flag;
int minimun=1000000;
void go() {
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			b.push_back(i);
		}
	}
	// a,b ÁýÇÕ »ÌÈù »óÅÂ
	int sumA = 0, sumB = 0;

	for (auto y : a) {
		for (auto x : a) {
			sumA += score[y][x];
		}
	}
	for (auto y : b) {
		for (auto x : b) {
			sumB += score[y][x];
		}
	}
	if (minimun > abs(sumA - sumB)) {
		minimun = abs(sumA - sumB);
	}
	b.clear();
}
void dfs(int idx, int curCnt, const int cnt) {
	if (curCnt == cnt) {
		flag = true;
		go();	//ÇÕ»ê
		return;
	}

	for (int i = idx; i <= n; ++i) {
		if (visit[i])
			continue;
		visit[i] = true;
		a.push_back(i);
		dfs(i, curCnt+1, cnt);	//ÇöÀç »ÌÈù °¹¼ö, ÃÖÁ¾ »Ì¾Æ¾ßÇÒ °¹¼ö
		visit[i] = false;
		a.pop_back();
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> score[i][j];
		}
	}

	for (int cnt = 1; cnt <= n/2; ++cnt) {
		for (int i = 1; i <= n; ++i) {
			visit[i] = true;
			a.push_back(i);
			dfs(i,1,cnt);	//ÇöÀç »ÌÈù °¹¼ö, ÃÖÁ¾ »Ì¾Æ¾ßÇÒ °¹¼ö
			visit[i] = false;
			a.pop_back();
			flag = false;
		}
	}

	cout << minimun << '\n';
	return 0;
}