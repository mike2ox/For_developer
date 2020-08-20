# bruteforce 같은데....
def solution(d, budget):
    answer = 0
    sum_d = 0
    if budget >= sum(d):
        return len(d)
    
    d.sort()

    for token in d:
        sum_d += token
        if sum_d<=budget:
            answer +=1
    print(answer)
    return answer

if __name__ == "__main__":
    solution([1,3,2,5,4],9)