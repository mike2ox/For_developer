/*
*	author : mike2ox
*	BOJ : 1934
*	descript : https://www.acmicpc.net/problem/
*	type : math 1
*	hint :
*/
#include <iostream>
using namespace std;

int A, B, T, gcd;

int GCD(int a, int b)
{
	if (b > a)
		return GCD(b, a);
	if (b == 0)
		return a;
	return GCD(b, a%b);
}
int main() {

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		gcd = GCD(A, B);
		if (GCD(A, B) == 1)
			cout << A * B << '\n';
		else

			cout << gcd * (A / gcd) * (B / gcd) << '\n';
	}
}


