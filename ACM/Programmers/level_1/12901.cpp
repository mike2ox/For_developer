// 2016년 (30m)
// 시뮬레이션
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b)
{
	a--;
	b--;
	vector<string> answer = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
	vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

	int day = 0;
	for (int i = 0; i < a; ++i)
		day += month[i];
	day += b;

	return answer[day % 7];
}
