#include<iostream>
#include<math.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int w = 0; int h = 0;
	double min_v = 1e+13;
	int n;
	cin >> n;

	//for (int i = 1; i < 10000000; i++) {
//		for (int j = 1; j < 10000000; j++) {
	//
//		}
	//}

	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			h = n / i;
			if (min_v > abs(i - h)) {
				min_v = abs(i - h);
			}
				
		}
	}

	cout << min_v;

	system("pause");
	return 0;

}

//���̰� N�� ���簢�� �� ���� ���� w, h�� �Ѵ�
//�̶� ������ w, h �� | w - h | �� �ּڰ��� ���Ͻÿ�.

//����
//�簢���� ���� N(1 <= N <= 10 ^ 13), ���� ���� w, h�� ��� �ڿ����̴�.

//�Է� ����
//�簢�� ���� N�� ǥ�� �Է¿��� �д´�.

//��� ����
//| w - h | �� �ּڰ��� ǥ�� ��¿� ����.