// BJO no. 14888 ¿¬»êÀÚ ³¢¿ö³Ö±â, mike2ox(2020)
#include<iostream>
#include<vector>
using namespace std;

int n;
int oper[4];	//µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À
int values[100];
vector<int> v;
int maximum=-1000000000, minimum = 1000000000;
int cntOper;
void go2() {
	int tmpValue=values[0];

	for (int idx = 0;idx<v.size();++idx) {
		if (tmpValue > 1000000000 || tmpValue < -1000000000)
			return;
		switch (v[idx])
		{
		case 0:
			tmpValue += values[idx + 1];
			break;
		case 1:
			tmpValue -= values[idx + 1];
			break;
		case 2:
			tmpValue *= values[idx + 1];
			break;
		case 3:
			tmpValue /= values[idx + 1];
			break;
		}
	}

	if (maximum < tmpValue)
		maximum = tmpValue;
	if (minimum > tmpValue)
		minimum = tmpValue;
	return;
}
void go(int cnt) {
	if (cnt == cntOper) {
		go2();
		return;
	}
	for (int i = 0; i < 4;++i) {
		if (oper[i] == 0)
			continue;
		oper[i]--;
		v.push_back(i);
		go(cnt+1);
		v.pop_back();
		oper[i]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> values[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> oper[i];
		cntOper += oper[i];
	}
	
	for (int i = 0; i < 4; ++i) {
		if (oper[i] == 0)
			continue;
		oper[i]--;
		v.push_back(i);
		go(1);
		v.pop_back();
		oper[i]++;
	}

	cout << maximum << '\n' << minimum << '\n';
	
	return 0;
}