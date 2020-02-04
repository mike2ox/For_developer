// BJO no.1991 mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;
int n;
class Tree {
	public:
		Tree() { data = ""; left = NULL; right = NULL;};
		void setData(string data) { this->data = data }
		void setLeft(Tree* L) { this->left = L };
		void setRight(Tree* R) { this->right = R };
		void static preOrder(Tree * root) {
			
		}
		void static inOrder(Tree * root) {

		}
		void static postOrder(Tree * root) {

		}

	private:
		string data;
		Tree* left, *right;
};

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	Tree value[26];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		char data, left, right;
		cin >> data >> left >> right;

	}

	for (int i = 0; i < 3; ++i) {
		value.preOrder(&value);
		value.inOrder(&value);
		value.postOrder(&value);
	}

	return 0;
}