#include<iostream>
#include<string>
#include<vector>
using namespace std;

//clear
string solution(string word) {
	string answer = "";
	int w_size = word.size();
	for (int i = 0; i < w_size; i++) {
		char temp;
		//소문자
		if (word[i] >=97 && word[i]<=122) {
			temp = (char)(219 - word[i]);
		}
		//대문자
		else if(word[i]>=65&&word[i]<=90){
			temp = (char)(155 - word[i]);
		}
		else {
			answer += word[i];
			continue;
		}			
		answer += temp;
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string cry;
	cin >> cry;


	string a = solution(cry);
	cout << a;
	system("pause");
	return 0;

}
