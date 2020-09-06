// 예상 대진표(37m)(lv2)
// 시뮬레이션(?)
#include <iostream>

using namespace std;

bool isFightPlayers(int a, int b)
{
	return ((b - a == 1) && a & 1);
}

void updateRound(int &a, int &b, int &roundNbr)
{
	a = (a / 2) + (a % 2);
	b = (b / 2) + (b % 2);
	roundNbr++;
}

int solution(int n, int a, int b)
{
	int roundNbr = 1;

	if (a > b)
		swap(a, b);

	while (!isFightPlayers(a, b))
		updateRound(a, b, roundNbr);

	return roundNbr;
}
