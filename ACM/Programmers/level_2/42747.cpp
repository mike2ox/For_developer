// H-index(40m)
// 정렬, 조건 파악 중요
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
	sort(citations.rbegin(), citations.rend());

	for (int h = 0; h < citations.size(); h++)
	{
		if (citations[h] < h + 1)
			return h;
	}

	return citations.size();
}
