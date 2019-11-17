def solution(arrangement):
    answer = 0
    stack = []
    arrangement = arrangement.replace("()", "X")
    
    for pipe in arrangement:
        if pipe == '(':
            stack.append(pipe)
            answer += 1
        elif pipe == ')':
            stack.pop()
        else:
            answer += len(stack)
    
    return answer

