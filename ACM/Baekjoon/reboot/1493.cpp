// BJO no. 1493 mike2ox(2020)
// 박스 채우기(non-clear, ref)
// greedy, divide and conquer
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <math.h>
using namespace std;

int min_count_box;
bool possible_fill = true;
vector<vector<int>> v;

void go(int length, int width, int height)
{
	if (length == 0 || width == 0 || height == 0)
		return;
	if (!possible_fill)	// 공간보다 작은 큐브가 없는 경우
		return;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][1] > 0 && v[i][0] <= length && v[i][0] <= width && v[i][0] <= height)
		{
			v[i][1]--;
			min_count_box++;
			// 상자를 3구역으로 분할
			go(length, width, height - v[i][0]);
			go(length - v[i][0], width, v[i][0]);
			go(v[i][0], width - v[i][0], v[i][0]);
			return;
		}
	}

	possible_fill = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int length, width, height;
	int n;

	cin >> length >> width >> height;
	cin >> n;

	int box_size, box_count;

	for (int i = 0; i < n; i++)
	{
		cin >> box_size >> box_count;
		v.push_back({(int)pow(2, box_size), box_count});
	}

	sort(v.rbegin(), v.rend());

	go(length, width, height);

	if (possible_fill)
		cout << min_count_box << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
