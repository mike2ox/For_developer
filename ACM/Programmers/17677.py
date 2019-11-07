# 교집합 / 합집합 = J(a,b)
# 중복 허용
# 두글자씩 끊어서, 특수문자 숫자 -> 삭제
def solution(str1, str2):
    answer = 1
    cross =0
    str1_split =[]
    str2_split =[]
    
    for i in range(0,len(str1)-1):
        token = str1[i:i+2]
        if (token[0] >= 'a' and token[0] <= 'z' or token[0] >='A' and token[0] <= 'Z') and (token[1] >= 'a' and token[1] <= 'z' or token[1] >='A' and token[1] <= 'Z'):
            str1_split.append(token)
    for i in range(0,len(str2)-1):
        token = str2[i:i+2]
        if (token[0] >= 'a' and token[0] <= 'z' or token[0] >='A' and token[0] <= 'Z') and (token[1] >= 'a' and token[1] <= 'z' or token[1] >='A' and token[1] <= 'Z'):
            str2_split.append(token)
        
    # 둘다 공집합일 경우
    if(len(str2_split)==0 and len(str1_split)==0):
        answer *= 65536
        return answer
    
    print(str1_split)
    print(str2_split)
    str1_len = len(str1_split)
    str2_len = len(str2_split) 
    
    for i in range(str1_len):
        for j in range(str2_len):
            if (str1_split[i][0].upper() == str2_split[j][0] or str1_split[i][0] == str2_split[j][0] or str1_split[i][0] == str2_split[j][0].upper()) or \
            (str1_split[i][0].lower() == str2_split[j][0] or str1_split[i][0] == str2_split[j][0] or str1_split[i][0] == str2_split[j][0].lower()):
                if (str1_split[i][1].upper() == str2_split[j][1] or str1_split[i][1] == str2_split[j][1] or str1_split[i][1] == str2_split[j][1].upper()) or \
                    (str1_split[i][1].lower() == str2_split[j][1] or str1_split[i][1] == str2_split[j][1] or str1_split[i][1] == str2_split[j][1].lower()):
                    cross += 1
                    str2_split[j] = " "
                    break
                    
    answer = cross/(str1_len+str2_len-cross)
    answer *= 65536
    return (int)(answer)