// 큰 수 만들기(50m)
// 조합 + sort(시간초과) -> greedy
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string number, int k)
{
	string answer ="";
	int max_point = 0;

	while (number.length() > k)
	{
		char candi_max = '\0';
		for (int i = max_point; i <= k; i++)
		{
			if (number[i] > candi_max)
			{
				max_point = i;
				candi_max = number[i];
			}
		}
		answer += number[max_point];
		max_point++;
		k++;
	}

	return answer;
}

int main()
{
	cout << solution("4177252841", 4);
	return 0;
}
