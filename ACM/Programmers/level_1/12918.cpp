// 문자열 다루기 기본(7m)(lv1)
// 아스키 코드 사용법
#include <string>
#include <vector>

using namespace std;

bool consistNbr(string str) {
    for (char nbr : str) {
        if (nbr < '0' || nbr > '9')
            return false;
    }
    return true;
}

bool solution(string str) {
    if ((str.length() == 4 || str.length() == 6) &&
        consistNbr(str))
        return true;
    else
        return false;
}
