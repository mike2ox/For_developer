// BJO no. 14226 mike2ox(2020)
#include<iostream>
#include<queue>
using namespace std;

int n;
int value, y, x;
node tree[10001];
 class node {
 public:
	 void setLeft(int L) { this->Left = L; };
	 void setRight(int R) { this->Right = R; };
	 int getLeft() { return this->Left; };
	 int getRight() { return this->Right; };
	 void setLevel() {};

 private:
	int Level;
	int Left;
	int Right;
};

void dfs(int position, int level) {
	if (tree[position].getLeft() == -1 && tree[position].getRight() == -1) {
		tree[position].setLevel(level);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >>value>> y >> x;
		tree[value].setLeft(y);
		tree[value].setRight(x);
	}

	dfs(1,1);


	return 0;
}