// 소수 찾기(40m)
//eratosthenes sieve
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

vector<bool> erasto(10000000, true);

void make_erasto()
{
	int bound = sqrt(10000000);
	erasto[0] = erasto[1] = false;

	for (int i = 2; i < bound; i++)
	{
		if (i > 2 && (i % 2 == 0))
			continue;
		for (int j = i + i; j < 10000000; j += i)
		{
			erasto[j] = false;
		}
	}
}

int solution(string numbers)
{
	int answer = 0;
	vector<int> visit;
	set<int> candi_prime;
	int check_cnt = 1;
	sort(numbers.begin(), numbers.end());

	while (check_cnt <= numbers.size())
	{
		visit.clear();
		visit.resize(numbers.size(), 0);

		for (int i = 0; i < check_cnt; i++)
			visit[i] = 1;

		do
		{
			string nbr = "";

			for (int i = 0; i < numbers.size(); i++)
			{
				if (visit[i])
					nbr += numbers[i];
			}
			do
			{
				candi_prime.insert(stoi(nbr));
			} while (next_permutation(nbr.begin(), nbr.end()));

		} while (prev_permutation(visit.begin(), visit.end()));
		check_cnt++;
	}

	make_erasto();

	for (int candi : candi_prime)
		if (erasto[candi])
			answer++;

	return answer;
}
