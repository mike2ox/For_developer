// 크레인 인형뽑기게임 (20분)
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	vector<stack<int>> machine;
	stack<int> basket;

	for (int j = 0; j < board[0].size(); ++j)
	{
		stack<int> stk;

		for (int i = board.size() - 1; i >= 0; --i)
		{
			if (board[i][j])
				stk.push(board[i][j]);
		}

		machine.push_back(stk);
	}

	for (int i : moves)
	{
		if (machine[i - 1].empty())
			continue;

		int doll = machine[i - 1].top();
		machine[i - 1].pop();

		if (basket.empty() || basket.top() != doll)
			basket.push(doll);
		else
		{
			basket.pop();
			answer++;
		}
	}

	return answer * 2;
}
