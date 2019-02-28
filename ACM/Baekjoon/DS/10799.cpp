/*
*	author : mike2ox
*	BOJ : 10779
*	descript : https://www.acmicpc.net/problem/
*	type : DS
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string pipe;
stack<char> stck;

int main() {

	// cin, cout �ӵ� ���
	ios_base::sync_with_stdio(false);
	cin >> pipe;

	int count = 0;

	for (int i = 0; i < pipe.length(); i++) {
		if (pipe[i] == '(')
			stck.push(pipe[i]);
		else {
			stck.pop();

			if (pipe[i - 1] == '(') //�������� ���
				count += stck.size();    //�߷������� ����� ������ ��

			else
				count++;    //������ 1���� �����Ƿ� 1�� �߰�
		}
	}

	cout << count << '\n';
	return 0;
}

/*
	������ �κ� ����, stack���� �ֿ� ��ɸ� ������ �� ��.
*/