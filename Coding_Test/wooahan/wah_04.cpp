#include<iostream>
#include<string>
#include<vector>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  
using namespace std;

//clear
int solution(vector<int> pobi, vector<int> crong) {
	int answer = 0;
	int page[4] = { pobi.front(), pobi.back(), crong.front() , crong.back() };
	int v_max[2][4];
	
	if (page[1] - page[0] != 1 || page[3] - page[2] != 1)
		return -1;

	if (page[0]%2 != 1 || page[1] % 2 != 0 || page[2] % 2 != 1|| page[3] % 2 != 0)
		return -1;

	//���ϱ�
	
	int val;
	for (int j = 0; j < 4; j++) {
		val = 0;
		string t = to_string(page[j]);
		for (int k = 0; k < t.length(); k++)
			val += (int)(t[k])-48;
		v_max[0][j] = val;
	}
	//���ϱ�
	for (int j = 0; j < 4; j++) {
		val = 1;
		string t = to_string(page[j]);
		for (int k = 0; k < t.length(); k++)
			val *= ((int)(t[k]) - 48);
		v_max[1][j] = val;
	}
	int m_p=0, m_c = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m_p= MAX(m_p, v_max[i][j]);
			m_c = MAX(m_c, v_max[i][j+2]);
		}
	}

	if (m_p > m_c)
		answer = 1;
	else if (m_p < m_c)
		answer = 2;
	else 
		answer = 0;

	return answer;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> a; vector<int> b;

	int t[4];
	for (int i = 0; i < 2; i++) {
		cin >> t[i];
		a.push_back(t[i]);
	}
	for (int i = 2; i <4; i++) {
		cin >> t[i];
		b.push_back(t[i]);
	}
	int c = solution(a,b);
	cout << c;
	system("pause");
	return 0;

}
/*
1. å�� ���Ƿ� ��Ĩ�ϴ�.
2. ���� ������ ��ȣ�� �� �ڸ� ���ڸ� ��� ���ϰų�, ��� ���� ���� ū ���� ���մϴ�.
3. ������ ������ ��ȣ�� �� �ڸ� ���ڸ� ��� ���ϰų�, ��� ���� ���� ū ���� ���մϴ�.
4. 2~3 �������� ���� ū ���� ������ ������ �մϴ�.
5. ������ ���� ���� ���� ����� ������ �����Դϴ�.
6. ���� ���̳� ������ ���� �������� å�� ��ġ�� �ʽ��ϴ�.
*/