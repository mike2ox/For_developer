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

//넓이가 N인 직사각형 두 변을 각각 w, h라 한다
//이때 가능한 w, h 중 | w - h | 의 최솟값을 구하시오.

//조건
//사각형의 넓이 N(1 <= N <= 10 ^ 13), 변의 길이 w, h는 모두 자연수이다.

//입력 형식
//사각형 넓이 N을 표준 입력에서 읽는다.

//출력 형식
//| w - h | 의 최솟값을 표준 출력에 쓴다.