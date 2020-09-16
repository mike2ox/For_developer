// BJO no. 13904 mike2ox(2020)
// 과제(45m)
// greedy
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

bool compare(vector<int> subject1, vector<int> subject2)
{
	return subject1[1] > subject2[1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d, w;

	cin >> n;
	vector<vector<int>> subjects;

	int day, score;

	for (int i = 0; i < n; i++)
	{
		cin >> day >> score;
		subjects.push_back({day, score});
	}

	sort(subjects.begin(), subjects.end(), compare);

	int days = subjects.size();
	map<int, int> possible_get_score;

	for (vector<int> subject : subjects)
	{
		for (int i = subject[0]; i > 0; i--)
		{
			if (possible_get_score[i])	// 과제 수행이 가능한 날짜 확인
				continue;
			else
			{
				possible_get_score[i] = subject[1];
				break;
			}
		}
	}

	int max_score = 0;

	for (auto score : possible_get_score)
	{
		max_score += score.second;
	}

	cout << max_score << '\n';
	return 0;
}
