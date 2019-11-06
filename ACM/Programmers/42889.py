def solution(N, stages):
    answer = []
    fail = {}
    n_user = len(stages)
    for i in range(1, N+1):
        if(stages.count(i)==0):
            fail[i] = 0.0
        else:
            fail[i] = stages.count(i)/n_user
            n_user -= stages.count(i)
    answer = sorted(fail, key=lambda x: fail[x],reverse=True)
    
    return answer

if __name__ == "__main__":
    print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
    print("=========================")
    print(solution(4, [4,4,4,4,4]))