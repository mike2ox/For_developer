def solution(record):
    answer = []
    result = {}
    
    for i in range(0, len(record)):
        subrecord = record[i].split()
        
        if subrecord[0] == "Enter":
            result[subrecord[1]] = subrecord[2]
        elif subrecord[0] == "Change":
            result[subrecord[1]] = subrecord[2]
        # elif subrecord[0] == 'Leave':
    for i in range(0, len(record)):
        subrecord = record[i].split()
        if subrecord[0] == "Enter":
            answer.append(result[subrecord[1]]+"님이 들어왔습니다.")
        elif subrecord[0] == "Leave":
            answer.append(result[subrecord[1]]+"님이 나갔습니다.")
        
    return answer
    
if __name__=="__main__":
    print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))