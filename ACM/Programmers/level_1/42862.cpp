// 체육복(1h)
// 접근방향 : hash? -> greedy
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = n;
	// 전체 배열의 양 끝을 하나씩 연장
	vector<int> stud(n + 2, 1);

	for (int i : reserve)
		stud[i]++;

	for (int i : lost)
		stud[i]--;

	for (int i : lost)
	{
		if (stud[i] != 0)
			continue;
		if (stud[i - 1] == 2)
		{
			stud[i]++;
			stud[i - 1]--;
		}
		else if (stud[i + 1] == 2)
		{
			stud[i]++;
			stud[i + 1]--;
		}
	}

	for (int i : stud)
	{
		if (i == 0)
			answer--;
	}

	return answer;
}
