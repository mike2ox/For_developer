// 더 맵게(스코빌 지수, 14m)
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pq;

	for (auto s : scoville)
		pq.push(s);

	while (pq.top() < K)
	{
		if (pq.empty() || pq.size() == 1)
			return -1;
		unsigned int first_min = pq.top();
		pq.pop();
		unsigned int second_min = pq.top();
		pq.pop();
		pq.push(first_min + 2 * second_min);
		answer++;
	}

	return answer;
}
