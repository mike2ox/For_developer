# 프로그래밍 대회에서 사용하는 C, C++, STL 정리(1)

## C

#### 포맷 문자열
- %d : 정수(*)
- %f : float(*)
- %lf : double
- %Lf : long double
- %lld : long long(*)
- %s : 문자열(*)
- %c : 문자(*) --> *공백(' '), 줄바꿈('\n')도 문자라서 제대로 동작 안될 수 있음*
- %x : 16진수
- %o : 8진수

- %[] : 대괄호 안의 값만 들어가도록 함.([^]가 있다면 반대로 그 값들만 빼고 나머지만 가져옴)
  ex) 그대로 출력하기(11718)
  ```cpp
    scanf("%[^\n]\n", s);
  ```

#### 테스트 케이스
 - a. T가 주어진 경우, b. 파일의 끝까지(EOF)  
 - a는 for문으로 clear, b는 scanf의 리턴값으로 clear


## C++

- getline(cin, s); : 한줄을 다 입력 받음  
- getprecision(num) : 총 num자리까지의 숫자를 출력함

- endl 보다 '/n'가 더 빠름
- ios_base::Sync_with_stdio(false) ; : cin, cout의 속도 향상 (단, printf, scanf 사용 불가)

#### auto
 - 컴파일러가 타입을 추론해서 결정.(명확한 타입 설정)
 - iterator사용시 편리함
  : ex) auto it = d.begin()으로 iterator code를 간소화 가능

#### range-based for
```cpp
    vector<pair<int, int>> a = {{1,2}, {3,4},{5,7}}
    // a의 항목들 전부를 P로 참조 복사하는 것
    // 속도가 매우 빠르며 코드가 간소화됨
    for(auto &p :a){
        cout << p.first << p.second;
    }
```

※ 주의 : c문자열을 적용할 경우 마지막에 NULL이 포함되 있길래 string보다 1만큼 더 크다

#### 초기화 리스트
- 형식만 맞다면 struct로도 리스트 형식으로 초기화가 가능

#### Lamda function
- 이름이 없는 함수를 의미
- [캡쳐] (함수 인자) {함수 내용}
- 캡쳐
 : & - 함수밖의 값을 참조형식으로 함수 안으로 가져와 사용 가능, = - 값 복사
 : &x - 특정값만 가져옴, 복수 사용시 (,)를 사용

```cpp
    auto sum2 = [](int x, int y){
        return x+y;
    };
    cout << sum2(1,2) << '\n';
```
