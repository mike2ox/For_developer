// BJO no. 10769 �ູ���� ������, mike2ox(2020)
#include<iostream>
#include<string>
using namespace std;
string emot;

void go() {
	// ���� - none, �ູ==���� : unsure
	// �ູ>���� happy
	int emotSize = emot.length();
	int happyCnt = 0;
	int sadCnt = 0;

	// for�� �������� ���̱� ����
	if (emotSize < 3) {
		cout << "none\n";
		return;
	}

	//����Ž��
	for (int rear = emotSize - 1; rear >= 2; --rear) {
		if (emot[rear] == ')') {
			if (emot[rear - 1] == '-' && emot[rear - 2] == ':')
				happyCnt++;
			else
				continue;
		}
		else if (emot[rear] == '(') {
			if (emot[rear - 1] == '-' && emot[rear - 2] == ':')
				sadCnt++;
			else
				continue;
		}
		else {
			continue;
		}
	}

	// �б�
	if (happyCnt == 0 && sadCnt == 0) {
		cout << "none\n";
		return;
	}

	if (happyCnt == sadCnt) {
		cout << "unsure\n";
		return;
	}
	else {
		cout << (happyCnt > sadCnt ? "happy\n" : "sad\n");
		return;
	}
}

int main() {

	getline(cin, emot);
	go();

	return 0;
}