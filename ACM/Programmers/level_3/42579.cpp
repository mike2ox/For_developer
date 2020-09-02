#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int> pre, pair<string, int> next)
{
	return pre.second > next.second;
}

bool compare2(pair<int, int> pre, pair<int, int> next)
{
	if (pre.first == next.first)
		return pre.second < next.second;
	return pre.first > next.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	// 장르, 재생수
	map<string, int> cnt_plays;

	// 장르 , 재생수, 고유번호
	unordered_map<string, vector<pair<int, int>>> album;

	for (int i = 0; i < (int)genres.size(); i++)
	{
		if (cnt_plays.find(genres[i]) != cnt_plays.end())
			cnt_plays[genres[i]] += plays[i];
		else
			cnt_plays[genres[i]] = plays[i];
		album[genres[i]].push_back({plays[i], i});
	}

	// 장르수에 따른 정렬용 vector
	vector<pair<string, int>> v_cnt_palys(cnt_plays.begin(), cnt_plays.end());
	sort(v_cnt_palys.begin(), v_cnt_palys.end(), compare);

	vector<int> answer;

	for (auto a : v_cnt_palys)
	{
		int cnt = 0;
		sort(album[a.first].begin(), album[a.first].end(), compare2);

		for (int i = 0; i < album[a.first].size() && i < 2; i++)
			answer.push_back(album[a.first][i].second);
	}

	return answer;
}
