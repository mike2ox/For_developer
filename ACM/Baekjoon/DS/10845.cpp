/*
*	author : mike2ox
*	BOJ : 10845
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/

#include<iostream>
#include<string>
using namespace std;

int N;      //명령 수
string command; //명령
int value;
int que[10001];		//큐 구현
int head, tail;			// 큐에서 head와 tail

void pushX(int _x) {

	head++;

	if (head > 10001)
		head = 0;
	if (head == tail) {
		cout << "full!\n";
		head--;
		return;
	}

	que[head] = _x;

}
int pop() {

	tail++;

	if (tail > 10001)
		tail = 0;

	if (tail > head) {
		tail--;
		return -1;
	}
	else
		return que[tail];

}
int size() {
	if (tail < head)
		return head - tail;
	else if (tail > head)
		return 10001 - (tail - head);
	else
		return 0;
}
int empty() {
	if (tail == head)
		return 1;
	else
		return 0;
}
void front() {
	if (empty())
		cout << -1 << '\n';
	else {
		if (tail < 10000)
			cout << que[tail + 1] << '\n';
		else
			cout << que[0] << '\n';
	}

}
void back() {
	if (empty())
		cout << -1 << '\n';
	else
		cout << que[head] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	head = tail = 0;		//init

	for (int i = 0; i < N; i++) {
		cin >> command;

		if (command == "push") {
			cin >> value;
			pushX(value);
		}
		else if (command == "front") {
			front();
		}
		else if (command == "back") {
			back();
		}
		else if (command == "size") {
			int val = size();
			cout << val << '\n';
		}
		else if (command == "empty") {
			int val = empty();
			cout << val << '\n';
		}
		else if (command == "pop") {
			int val = pop();
			cout << val << '\n';
		}
	}

	return 0;
}