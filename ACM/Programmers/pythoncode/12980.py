def solution(n):
    ans = 0

    while n != 0:
        if n%2 == 0:
            n /= 2
            continue
        else:
            n -=1
            ans +=1

    # print(ans)

    return ans

if __name__ == "__main__":
    solution(5000)