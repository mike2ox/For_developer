def solution(skill, skill_trees):
    answer = 0

    for token in skill_trees:
        flag = 0
        
        for i in range(len(token)):
            if skill[flag] == token[i]:
                flag += 1
            elif token[i] in skill:
                break

            if i+1 == len(token) or flag == len(skill):
                answer +=1
                break
    return answer

if __name__ == "__main__":
    solution("CBD",["BACDE", "CBADF", "AECB", "BDA"])