/*
*	author : mike2ox
*	BOJ : 10828
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int T;
char str[5];

void pushX(vector<int>* t_s) {
	int input;
	cin >> input;
	t_s->push_back(input);
}
int pop(vector<int>* t_s) {
	if (t_s->empty())
		return -1;
	else {
		int popup = t_s->back();
		t_s->pop_back();
		return popup; 
	}
}
int size(vector<int>* t_s) {
	return t_s->size();
}
int empty(vector<int>* t_s) {
	if (t_s->empty())
		return 1;
	else
		return 0;
}
int top(vector<int>* t_s) {
	if (t_s->empty())
		return -1;
	else
		return t_s->back();
}
int main() {

	ios_base::sync_with_stdio("false");
	vector<int> stak;

	cin >> T;

	while(T--) {
		cin >> str;

		if (str[0] == 'p') {
			if (str[1] == 'u') {
				pushX(&stak);
			}
			else if (str[1] == 'o') {
				int tt = pop(&stak);
				cout << tt << '\n';
			}
		}
		else if (str[0]=='t') {
			int t =top(&stak);
			cout << t << '\n';
		}
		else if (str[0] == 'e') {
			int e = empty(&stak);
			cout << e << '\n';
		}
		else if (str[0] == 's') {
			int si = size(&stak);
			cout << si << '\n';
		}
		else {
			cout << "제대로 된 입력 필요" << '\n';
			T++;
		}
	}

	system("pause");
	return 0;
}