// 124나라의 숫자(35m)
// 진법 + stack
#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n)
{
	string answer = "";
	vector<char> base = {'1', '2', '4'};
	stack<char> stk;

	while (n)
	{
		n--;
		stk.push(base[n % 3]);
		n /= 3;
	}

	while (!stk.empty())
	{
		answer += stk.top();
		stk.pop();
	}

	return answer;
}

// 25분
string solution2(int n)
{
	string answer = "";

	while (n)
	{
		int rest = n % 3;
		n /= 3;

		if (rest == 0)
		{
			answer += '4';
			n--;
		}
		else if (rest == 1)
		{
			answer += '1';
		}
		else
		{
			answer += '2';
		}
	}

	reverse(answer.begin(), answer.end());

	return answer;
}
