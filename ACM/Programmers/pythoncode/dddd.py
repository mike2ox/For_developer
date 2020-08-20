def solution(stones, k):
    answer = 0
    zero = []
    stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1]
    while True:
        # 돌마다 -씩 감소 시키기
        for idx in range(len(stones)):
            if stones[idx]==0:
                if idx in zero:
                    continue
                else:
                    zero.append(idx)
            else:
                stones[idx] -= 1
                if(stones[idx] == 0):
                    zero.append(idx)
        # 0인 돌들의 idx만 추출
        zero.sort()
        
        # k보다 작으면 계속 감소 시키기
        if len(zero) < k:
            answer+=1
            continue
        else:   # k와 같거나 큰 경우
            gap = 1
            
            for tk in range(len(zero)):
                if(zero[tk+1] == zero[tk]+1):
                    gap += 1
                else:
                    gap = 1
                
                if(gap >= k):
                    return answer+1
                
                if(tk+1==(len(zero)-1)):# 다음 인자가 마지막이면 종료
                    break
            
        answer += 1

    