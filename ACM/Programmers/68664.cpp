// 두개 뽑아 더하기(11분)
// 조합
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	unordered_set<int> numbers_sum;
	vector<int> visit(numbers.size(), 0);
	visit[0] = visit[1] = 1;

	do{
		int selected_num = -1;

		for (int i = 0; i < visit.size(); i++) {
			if (visit[i]) {
				if (selected_num == -1)
					selected_num = numbers[i];
				else {
					numbers_sum.insert(selected_num + numbers[i]);
					break;
				}
			}
		}
	} while (prev_permutation(visit.begin(), visit.end()));

	answer.assign(numbers_sum.begin(), numbers_sum.end());
	sort(answer.begin(), answer.end());

	return answer;
}

int main() {
	vector<int> a = solution({2, 1, 3, 4, 1});
	vector<int> b = solution({5, 0, 2, 7});
	return 0;
}
