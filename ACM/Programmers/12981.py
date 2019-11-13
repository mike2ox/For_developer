def solution(n, words):
    answer = []
    cp_words = []
    for idx in range(len(words)):

        if len(words[idx]) == 1:
            print(idx)
            answer.append((idx % n)+1)
            answer.append((int)(idx / n)+1)
            return answer
        elif idx >= 1:
            if words[idx][0] != words[idx-1][-1] or words[idx] in cp_words:   
                answer.append((idx % n)+1)
                answer.append((int)(idx / n)+1)
                return answer
        
        cp_words.append(words[idx])
        
    return [0,0]

if __name__ == "__main__":
      solution(5, ["hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"])      