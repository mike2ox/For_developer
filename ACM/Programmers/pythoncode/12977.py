from itertools import combinations

def solution(nums):
    answer = 0
    occasion = list(combinations(nums, 3))
    sum_occ = []
    print(occasion)
    for token in occasion:
         sum_occ.append(sum(token))
    
    # sum_occ = list(set(sum_occ))
    print(sum_occ)
    for num in sum_occ:
        flag = False
        for i in range(2, num):
            if num%i == 0:
                flag = True
                break
        if flag is False:
            answer += 1

    print(answer)
    return answer

if  __name__ == "__main__":
    solution([1,2,7,6,4])