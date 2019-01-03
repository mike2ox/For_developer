# 프로그래밍 대회에서 사용하는 C, C++, STL 정리(2)

## STL
- 알고리즘, 컨테이너, 함수, iterator로 구성  

#### pair
- ```#include <utility>```에 포함
  ex) 생성
```cpp
    pair<int, int> a;
    pair<int, int> a(0, 1);
    a = make_pair(1, 2);
    a = pair<int, int>(3, 4)
```

#### tuple
- pair보다 더 많은 정보를 묶을 수 있음
- ```get<index>(tuple name)```을 이용한 인덱스 접근 가능
- ```#include<tuple>```에 포함

#### tie
- 변수를 묶어서 tuple에 있는 여러 인수로 접근할 수 있음

  ex) pair, ignore 사용 예제
```cpp
    // a,b를 서로 바꾸는 방법
    tie(a,b) = make_pair(b, a);
    
    // t에서 사용하지 않을 부분에 ignore로 대신 메꿈
    auto t = make_tuple(1,2,3);
    int x, y;
    tie(x, y, ignore) = t;
```

#### vector
- 가장 코딩테스트에서 많이 사용
- 2차원 배열 선언도 가능 --> ```vector<vector<int>> v;```

  ex) vector내 자주 사용하는 함수
```cpp
    // 제일 마지막에 3 추가
    a.push_back(3);
    // 제일 마지막 pop up
    a.pop_back();
    // 전체 vector 비우기
    a.clear();
    // 크기가 4인 vector list로 변경
    a.resize(4)
    // vector의 크기 출력
    a.size()
    // vector가 비어있는지 확인
    a.empty();
```
- iterator는 point로 생각하면 편함(begin은 첫번째 요소, end는 마지막 요소의 다음 부분을 가리킴)

#### deque
- queue가 양쪽으로 붙어있는 구조 --> push, pop이 양쪽에서 발생

#### list
- 이중 연결 리스트를 말하나, ACM 대회에선 잘 사용하지 않음.
- 삽입, 삭제에 용이한 자료구조

#### set
- 순서가 없는 연관 컨테이너 --> 접근할 때 ++, --를 사용해야함.
- BST로 구성 --> 집합을 나타낼 때 용이
- 기본적으로 오름차순으로 정렬해서 저장.
- *중복된 값을 저장하지 않음*
- O(logN)

  ex) set 사용
```cpp
    set<int> a = {1,2,3};
    pair<set<int>::iterator, bool> r = a.insert(4);
    //{1,2,3,4}
    // 4, 1 출력
    cout << *r.first << r.second;

    auto f = a.find(1); //f의 타입은 set<int>::iterator임
    cout << f
```
#### map
- (key, value) 로 구성된 컨테이너
- 