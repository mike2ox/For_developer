/*
*	author : mike2ox
*	BOJ : 1406
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
#include<list>
using namespace std;

string editor;
list<char> edit;
int n_command;     //��� ��
char command;     // ������ ���
char c;     //�Է��� ����

int main() {

	ios_base::sync_with_stdio(false);
	cin >> editor;

	for (int i = 0; i < editor.length(); i++)
		edit.push_back(editor[i]);

	cin >> n_command;
	list<char>::iterator itr = edit.end();

	for (int i = 0; i < n_command; i++) {
		cin >> command;

		switch (command) {
		case 'P':
			cin >> c;
			edit.insert(itr, c);
			break;
		case 'D':
			if (itr != edit.end())
				itr++;
			break;
		case 'L':
			if (itr != edit.begin())
				itr--;
			break;
		case 'B':
			if (itr != edit.begin())
				itr--;
			else
				continue;
			itr = edit.erase(itr);
			break;
		}
	}

	for (list<char>::iterator it = edit.begin(); it != edit.end(); it++)
		cout << *it;
	cout << '\n';

	return 0;
}
/*
	iterator Ȱ�� �߿�, list��ſ� vector�� ������ ����
*/