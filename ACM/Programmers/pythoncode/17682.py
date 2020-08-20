def solution(dartResult):
    answer = 0
    idx = -1
    value = []
    
    for i in range(len(dartResult)):
        # 숫자일 경우
        if dartResult[i] >= '0' and dartResult[i] <= '9':
            if dartResult[i+1]=='0':
                value.append(10)
            elif dartResult[i-1] =='1':
                continue
            else:
                value.append((int)(dartResult[i]))
            idx+=1
        
        else:
            if dartResult[i] == 'S':
                value[idx]=value[idx]
                continue
            elif dartResult[i] == 'D':
                value[idx] = value[idx]*value[idx]
                continue
            elif dartResult[i] == 'T':
                value[idx] = value[idx]*value[idx]*value[idx]
                continue
                
            if dartResult[i] == '*':
                if(idx==0):
                    value[idx] = 2*value[idx]
                else:
                    value[idx-1] = 2*value[idx-1]
                    value[idx] = 2*value[idx]
            if dartResult[i] == '#':
                value[idx] = (-1)*value[idx]
                
    for i in value:
        answer += i
    return answer

if __name__ == "__main__":
    solution("1S*2T*3S")