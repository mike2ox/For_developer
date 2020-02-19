// BJO no. 11723, mike2ox(2020)
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string command,str;
	int value;
	int n=0, m;
	cin >> m;

	while (m--) {
		cin >> command;
		
		switch (command[0])
		{
		case 'a':
			if (command[1] == 'd') { // add
				cin >> value;
				n |= (1 << value);
				//cout << n << '\n';
			}
			else if (command[1] == 'l') {	//all
				n = (1 << 21) - 1;
			}
			break;
		case 'r': // remove
			cin >> value;
			n &= ~(1 << value);
			break;
		case 'c':
			cin >> value;
			cout << ((n & (1 << value)) == 0 ? 0 : 1) << '\n';
			break;
		case 't':
			cin >> value;
			n ^= (1 << value);
			break;
		case 'e':
			n = 0;
			break;
		}
	}

	return 0;
}