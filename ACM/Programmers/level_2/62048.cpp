// 멀쩡한 사각형(20m)
// w, h < 1억 --> 공통되는 부분 * 최대공약수
#include <vector>
#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{
	if (num1 < num2)
		swap(num2, num1);
	int rest = 0;

	while (num2)
	{
		rest = num1 % num2;
		num1 = num2;
		num2 = rest;
	}
	return num1;
}

long long solution(int w, int h)
{
	long long answer = (long long)w * (long long)h;
	int value_gcd = gcd(w, h);

	w /= value_gcd;
	h /= value_gcd;

	// 대각선이 지나는 사각형의 갯수만큼 빼기
	answer -= (long)((w + h - 1) * value_gcd);

	return answer;
}
