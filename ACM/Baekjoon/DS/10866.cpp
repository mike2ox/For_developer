/*
*	author : mike2ox
*	BOJ : 10866
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
using namespace std;

int node_value;		//Á¤¼ö
int n_func;			//number of functions

string command;
struct node {
	int value;
	node* pre;
	node* next;
};


struct deque {
	node* head;
	node* tail;
	int cnt;
};

void size(deque *dq);
void front(deque *dq);
void back(deque *dq);
void empty(deque *dq);
void push_front(deque *dq);
void push_back(deque *dq);
void pop_front(deque *dq);
void pop_back(deque *dq);

int main() {
	deque DQ;
	DQ.head = NULL;
	DQ.tail = NULL;
	DQ.cnt = 0;

	cin >> n_func;

	for (int a = 0; a < n_func; a++) {
		cin >> command;

		if (command == "push_front") {
			push_front(&DQ);
		}
		else if (command == "push_back") {
			push_back(&DQ);
		}
		else if (command == "pop_front") {
			pop_front(&DQ);
		}
		else if (command == "pop_back") {
			pop_back(&DQ);
		}
		else if (command == "size") {
			size(&DQ);
		}
		else if (command == "empty") {
			empty(&DQ);
		}
		else if (command == "front") {
			front(&DQ);
		}
		else if (command == "back") {
			back(&DQ);
		}
	}

	return 0;
}
void push_front(deque *dq) {
	node* temp = new node;
	cin >> temp->value;

	if (dq->cnt == 0) {
		dq->head = temp;
		dq->tail = temp;
		(dq->cnt)++;
	}
	else {
		temp->next = dq->head;
		dq->head->pre = temp;
		temp->pre = NULL;
		dq->head = temp;
		(dq->cnt)++;
	}

}
void push_back(deque *dq) {
	node* temp = new node;
	cin >> temp->value;

	if (dq->cnt == 0) {
		dq->head = temp;
		dq->tail = temp;
		(dq->cnt)++;
	}
	else {
		temp->pre = dq->tail;
		dq->tail->next = temp;
		temp->next = NULL;
		dq->tail = temp;
		(dq->cnt)++;
	}
}
void pop_front(deque *dq) {
	if (dq->cnt == 0)
		cout << "-1" << '\n';
	else if (dq->cnt == 1) {
		node* temp = new node;
		cout << dq->head->value << '\n';
		(dq->cnt)--;
		delete dq->head;
	}
	else {
		node* temp = new node;
		cout << dq->head->value << '\n';
		temp = dq->head;
		dq->head = dq->head->next;
		dq->head->pre = NULL;
		(dq->cnt)--;
		delete temp;
	}
}
void pop_back(deque *dq) {
	if (dq->cnt == 0)
		cout << "-1" << '\n';

	else if (dq->cnt == 1) {
		node* temp = new node;
		cout << dq->tail->value << '\n';
		(dq->cnt)--;
		delete dq->tail;
	}
	else {
		node* temp = new node;
		cout << dq->tail->value << '\n';
		temp = dq->tail;
		dq->tail = dq->tail->pre;
		dq->tail->next = NULL;
		(dq->cnt)--;
		delete temp;
	}
}
void size(deque *dq) {
	cout << dq->cnt << '\n';
}
void front(deque *dq) {
	if (dq->cnt == 0)
		cout << "-1" << '\n';
	else
		cout << dq->head->value << '\n';
}
void back(deque *dq) {
	if (dq->cnt == 0)
		cout << "-1" << '\n';
	else
		cout << dq->tail->value << '\n';
}
void empty(deque *dq) {
	if (dq->cnt == 0)
		cout << "1" << '\n';
	else
		cout << "0" << '\n';
}
