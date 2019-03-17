#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node {
	string a,b,c;
	node(string t1, string t2, string t3) :
		a(t1), b(t2), c(t3){}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, r;

	cin >> c;
	vector<node> table;
	vector<node> table2;
	for (int i = 0; i < c; i++) {
		
		string r0, r1, r2;
		cin >> r0 >>r1 >> r2;

		if(i==0)
			table.push_back(node("id", r1, r2));
		else
			table.push_back(node(r0, r1, r2));
	}
	for (int i = 0; i < c; i++) {

		string r0, r1, r2;
		cin >> r0 >> r1 >> r2;

		if (i == 0)
			table2.push_back(node("id", r1, r2));
		else
			table2.push_back(node(r0, r1, r2));
	}




	system("pause");
	return 0;

}
/*
�� ���� ���̺��� �־����� ��, �� ���̺��� ���� �ܺ� ����(left outer join) �� ����� ����Ͻÿ�.

���̺� 1�� ���̺� 2���� id ���� �⺻ Ű(primary key) �̰�, �ϴ����� �����̴�.
���̺� 2�� id ���� ���̺� 1 id ���� �ܷ� Ű(foreign key) �̴�.

�Է� ����
ù �ٿ��� ����� ������ ���� ���� �Է��Ѵ�.
���� �ٿ��� ����� �Է��Ѵ�.
����� ù��° ���� id�̴�.
id�� ������ �ִ� 3���� ���� ����(" ")���� �����Ͽ� �Է��Ѵ�.
��� ���� ������� ������ ���� ���� ���� �ִ�.
id ���� 32��Ʈ ������, ������ ���� ��� ���ڿ��̴�.
���� ���� ���̺��� 2�� �Է��Ѵ�.
��� ����
ù �ٿ��� ���� �ܺ� ���� ��� ���̺��� ����� ����Ѵ�.
����� ������ ���� id�� �������� �����Ͽ� �� �ٿ� �� ���� ����Ѵ�.
������ �ϳ��� ����(" ")���� �и��Ѵ�.
�� ���� �빮�� NULL�� ����Ѵ�.
*/
