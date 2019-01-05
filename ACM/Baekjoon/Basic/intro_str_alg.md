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

## Algorithm

#### count
- O(N)
- ```count(begin, end, value)``` : value의 개수를 찾음
- ```count_if(begin, end, p)``` : p에 해당하는 것의 개수를 찾음(lambda를 사용해 p를 만들면 편함)

#### find
- ```find(begin, end, value)``` : 해당 value의 이터레이터를 반환
- ```find_if(begin,end, p)``` : p의 이터레이터를 반환
- O(N)

#### fill
- ```fill(begin, end, value)``` : value로 [begin, end)까지 채움
   ※ cstring : memset에서 0, -1을 초기화 하는데 사용
- O(N)

#### reverse
- ```reverse(begin, end)``` : 전체 순서를 바꿔주는 함수
- O(N)

#### rotate
- ```rotate(begin, mid, end)``` : mid를 기준으로 왼쪽으로 회전시키는 함수

#### swap
- ```swap(a,b)``` : a,b의 값을 바꾸는 함수

#### unique
- ```unique(begin, end)``` : 좌표 압축에 많이 사용함. 해당 구간에서 연속되는 같은 값을 하나만 남기고 다 제거
  ※ 실제로는 지우지 않기에 erase함수를 사용해 중복된 값을 없애줘야 함
  ※ 붙어있는 기준으로 하나만 남기기에 떨어져있는 동일 값이 있을 경우 그대로 살아있게 됨. 
  --> 정렬을 먼저하면 동일 값들끼리 묶이기 때문에 의도한 형태로 값들을 줄일 수 있음.

#### sort
- ```sort(begin, end)``` : 오름차순으로 정렬하는 함수
- ```sort(begin, end, cmp)``` : cmp라는 비교함수로 정렬
  ex) cmp가 적용된 sort
  ```cpp
    // boolean 형태로 반환해야 sort함수의 입력파라미터 양식에 맞음
    bool cmp(const int &u, const int &v){
      return u>v;
    }

    vector<int> exam = {5,3,1,6,4};

    // 아래 sort 양식은 다 같은 기준으로 exam을 sort함
    sort(exam.begin(), exam.end(), greater<int>());
    sort(exam.begin(), exam.end(),cmp);
    sort(exam.begin(), exam.end(),[](int u, int v){
      return u > v;
    });
  ```

#### stable_sort(안전정렬)
- bubble, merge sort에 해당
- 순서 기준이 여러개이며 한가지 기준으로 정렬할 때, 해당 기준이 동일 할 경우 처음 입력된 순서로 정렬되도록 함. 
- ```stable_sort(begin, end)``` : '<'를 기준으로 정렬 
- ```stable_sort(begin, end, cmp)``` : cmp를 기준으로 정렬

#### binary_search
- ``` binary_search(begin, end, value)``` : (정렬된) 해당 범위에서 value가 있으면 T, 아니면 F 반환
- ``` binary_search(begin, end, value, cmp)``` : (정렬된) 해당 범위에서 value가 cmp 기준에서 있으면 T, 아니면 F 반환

#### lower_bound / upper_bound
- value 기준으로 작지 않은 / 큰 첫 번째 이터레이터를 반환
- ```lower_bound(begin, end, value)```
- ```upper_bound(begin, end, value)```
  ※ ```equal_range(begin, end, value)``` : lower + upper를 pair형태로 리턴.

#### min_element / max_element
- min / max 와 달리 이터레이터를 반환하는 함수

#### next_permutation / prev_permutation(얘는 많이 안씀)
- ```next_permutation(begin, end)``` : 순열일 때, 사전 순으로 다음에 오는 순열을 만듦.(마지막 순열이면 false)
  ※ 순서가 중요한 문제를 풀어야 할 경우에 많이 사용.