#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node {
	string a,b,c;
	node(string t1, string t2, string t3) :
		a(t1), b(t2), c(t3){}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, r;

	cin >> c;
	vector<node> table;
	vector<node> table2;
	for (int i = 0; i < c; i++) {
		
		string r0, r1, r2;
		cin >> r0 >>r1 >> r2;

		if(i==0)
			table.push_back(node("id", r1, r2));
		else
			table.push_back(node(r0, r1, r2));
	}
	for (int i = 0; i < c; i++) {

		string r0, r1, r2;
		cin >> r0 >> r1 >> r2;

		if (i == 0)
			table2.push_back(node("id", r1, r2));
		else
			table2.push_back(node(r0, r1, r2));
	}




	system("pause");
	return 0;

}
/*
두 개의 테이블이 주어졌을 때, 두 테이블을 왼쪽 외부 조인(left outer join) 한 결과를 출력하시오.

테이블 1과 테이블 2에서 id 열은 기본 키(primary key) 이고, 일대일의 관계이다.
테이블 2의 id 열은 테이블 1 id 열의 외래 키(foreign key) 이다.

입력 형식
첫 줄에는 헤더를 포함한 행의 수를 입력한다.
다음 줄에는 헤더를 입력한다.
헤더의 첫번째 열은 id이다.
id를 포함해 최대 3개의 열을 공백(" ")으로 구분하여 입력한다.
모든 행은 헤더에서 지정한 수의 열을 갖고 있다.
id 값은 32비트 정수형, 나머지 값은 모두 문자열이다.
위와 같은 테이블을 2개 입력한다.
출력 형식
첫 줄에는 왼쪽 외부 조인 결과 테이블의 헤더를 출력한다.
헤더를 제외한 행은 id로 오름차순 정렬하여 한 줄에 한 행을 출력한다.
열들은 하나의 공백(" ")으로 분리한다.
빈 열은 대문자 NULL을 출력한다.
*/
