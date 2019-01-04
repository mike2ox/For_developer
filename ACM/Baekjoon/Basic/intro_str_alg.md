# 프로그래밍 대회에서 사용하는 String, 알고리즘 정리

#### string
- size(), length() 둘 다 사용가능하지만 length를 주로 씀
 ※ size()는 unsigned 이기에 -인 경우를 파악하고 있어야함.
- 문자열 크기 비교를 연산자로 할 수 있음.
- 문자열 -> 숫자 : stoi 함수를 사용(단, int 범위와 숫자표현이 안되는 문자로는 사용이 불가)
 ※ unsigned long : stoul(), float : stof(), double : stod()
- 숫자 -> 문자열 : to_string 함수를 사용

  ex) string 기본 생성 및 사용
  ```cpp
    string s1;      //C++스타일
    char s2[] = 'ssss';//C 스타일

     //c -> c++ 스타일 전환 가능
    string s3(s2); 
    string s3 = s2;
    // 만약 '/0' Null문자가 문장 내에 들어가면 null 기준으로 문자열이 split

    string s4(10, '!'); //길이가 10개인 !로 구성된 문자
    string s5 = "ssss";
  ```
