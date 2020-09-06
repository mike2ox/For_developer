// BJO no.15658 mike2ox(2020)
// 연산자 끼워넣기 2
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> numbers, vector<int> cnt_operator, int n) {
	vector<int> answer = {INT_MIN, INT_MAX };	//최대값, 최소값
	string operators = "";
	unordered_set<string> all_case_op;

	for (int i = 0; i < 4; i++) {
		while (cnt_operator[i]) {
			if (i == 0) operators += '+';
			else if (i == 1) operators += '-';
			else if (i == 2) operators += '*';
			else operators += '/';
			cnt_operator[i]--;
		}
	}
	vector<int> check(operators.length(), 0);
	for (int i = 0; i < n - 1; i++)
		check[i] = 1;

	while (true) {
		string case_op = "";
		for (int i = 0; i < check.size(); i++) {
			if (check[i])
				case_op += operators[i];
			if (case_op.size() == n - 1)
				break;
		}
		all_case_op.insert(case_op);
		if (!next_permutation(check.rbegin(), check.rend()))
			break;
	}

	for (string ops : all_case_op) {
		sort(ops.begin(), ops.end());

		while (true) {
			string tmp = ops;
			int ret = numbers.front();
			for (int i = 1; i < numbers.size() ; i++) {
				if (tmp[i - 1] == '+') ret += numbers[i];
				else if (tmp[i - 1] == '-') ret -= numbers[i];
				else if (tmp[i - 1] == '*') ret *= numbers[i];
				else ret /= numbers[i];
			}

			if (answer[0] < ret)
				answer[0] = ret;

			if (answer[1] > ret)
				answer[1] = ret;

			if (!next_permutation(ops.begin(), ops.end()))
				break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> numbers(n, 0);
	vector<int> cnt_operator(4, 0);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> cnt_operator[i];

	vector<int> answers = solution(numbers, cnt_operator, n);

	for (int answer : answers)
		cout << answer << '\n';

	return 0;
}
