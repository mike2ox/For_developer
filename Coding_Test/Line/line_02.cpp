#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;

	int str_l = str.length();
	vector<char> v_str;

	//ascii code boundary
	if (str[str_l / 2 ] > 48 || str[str_l / 2 ] <57) {
		for (int i = 0; i < str_l; i++) {
			v_str.push_back(str[i]);

			i = i + str_l / 2;
			if (str[i] == '1') {
				if (i+1 >= str_l)
					break;
				i = i - str_l / 2;
				continue;
			}
			else
				v_str.push_back(str[i]);
			if (i+1 >= str_l)
				break;
			i = i - str_l / 2;
		}
	
	}
	else 
		cout << "error" << '\n';
	
	for (vector<char>::iterator itr = v_str.begin(); itr != v_str.end(); ++itr)
		cout << *itr;

	system("pause");
	return 0;

}
/*
ȭ�н��� ���� ��ȣ�� ���� ���� �������� ǥ���Ѵ�. (���� ���ڴ� �Ʒ� ÷�ڷ� ǥ��������, ���ǻ� �Ϲ����� ���� ǥ��� ��ü�Ѵ�.)

�ùٸ� ������ �ƴ� ȭ�н��� �Է¹޾�, �ùٸ� �������� �ٲپ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է��� ���� ��ȣ���� �տ� ���ְ� �ڿ� ���� �������� ���ִ� �����̸�, ���� ��Ģ�� �Ʒ��� ����.

���� ��ȣ�� �빮�� 1�� �Ǵ� �빮�� 1�� + �ҹ��� 1���̴�.
���� ���� N�� 1 <= N <= 10 �̴�.N = 1�� ��� ����� �� ���ڸ� �����Ѵ�.
�߸��� ������ ����(���ҿ� ���� ������ ¦�� ���� �ʴ� ���)�� ��쿡 error��� ����Ѵ�.
*/
