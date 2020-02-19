// BJO no. 11723, mike2ox(2020)
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define DIFF 48

int m;
vector<int> v;
bool visit[21];
int check(int x) {
	if (visit[x]) {
		cout << "1\n";
		return 1;
	}
	else {
		cout << "0\n";
		return 0;
	}
}
void add(int x) {
	if (!visit[x]) {
		visit[x] = true;
		v.push_back(x);
	}
	else
		return;
}
void remove(int x){
	if (visit[x]) {
		for (int i = 0; i < v.size(); ++i){
			if (v[i] == x)
				v.erase(v.begin() + i);
		}
		visit[x] = false;
	}
	else
		return;
}
void toggle(int x) {
	if (visit[x])
		remove(x);
	else
		add(x);
}
void all() {
	v.clear();
	for (int i = 1; i <= 20; ++i) {
		v.push_back(i);
		visit[i] = true;
	}
}
void empty() {
	v.clear();
	for (int i = 1; i <= 20; ++i) {
		visit[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string command,str;
	int value;

	cin >> m;

	while (m--) {
		cin >> command;
		if (command == "all")
			all();
		else if (command == "empty")
			empty();
		else {
			cin >> value;
			if (command == "check")
				check(value);
			else if (command == "toggle")
				toggle(value);
			else if (command == "add")
				add(value);
			else if (command == "remove")
				remove(value);
		}
	}

	return 0;
}