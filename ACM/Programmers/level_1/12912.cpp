// 두 정수 사이의 합(5m -> x)
// 1. 직관적으로 풀기 2. 수학 공식 적용
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a > b) swap(a, b);

	// b - a + 1만큼의 연산이 발생
	// 등차 수열 합 코드 적용 가능(case 별)
    for (;a <= b; a++)
        answer += a;
    return answer;
}
