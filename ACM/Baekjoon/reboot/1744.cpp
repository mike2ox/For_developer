// BJO no. 1744 수 묶기, mike2ox(2020)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<long long>v1,v2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	long long tmp, ret=0;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if(tmp <=0)
			v1.push_back(tmp);
		else {
			v2.push_back(tmp);
		}
	}
	tmp = 0;

	sort(v2.begin(), v2.end());
	sort(v1.begin(), v1.end());

	// 양수 벡터
	for (int i = v2.size() - 1; i >= 0; i-=2) {
		if (i == 0) {	//마지막 부분일 경우
			tmp += v2[i];
			break;
		}
		else if (v2[i]==1||v2[i-1]==1) {
			tmp += (v2[i] + v2[i - 1]);
		}
		else //부호가 같을 경우
			tmp += (v2[i] * v2[i - 1]);
	}
	ret = tmp;
	tmp = 0;
	// 음수 벡터
	for (int i = 0; i < v1.size() ; i += 2) {
		if (i == v1.size()-1) {	//마지막 부분일 경우
			tmp += v1[i];
			break;
		}
		else //마지막 단계 전까지 곱해줌
			tmp += (v1[i] * v1[i + 1]);
	}
	
	cout << ret + tmp << '\n';
	return 0;
}