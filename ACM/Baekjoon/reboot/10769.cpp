// BJO no. 10769 행복한지 슬픈지, mike2ox(2020)
#include<iostream>
#include<string>
using namespace std;
string emot;

void go() {
	// 포함 - none, 행복==슬픔 : unsure
	// 행복>슬픔 happy
	int emotSize = emot.length();
	int happyCnt = 0;
	int sadCnt = 0;

	// for문 종료조건 줄이기 위해
	if (emotSize < 3) {
		cout << "none\n";
		return;
	}

	//역순탐색
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

	// 분기
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