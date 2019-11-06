from queue import PriorityQueue as pq

def solution(food_times, k):
    if sum(food_times) <=k:
        return -1
    
    answer =0
    sum_value =0
    pre_food = 0
    n_food = len(food_times)
    q=pq()
    
    for i in range(len(food_times)):
        q.put((food_times[i], i+1)) # (food_times, idx)

    while sum_value + ((q.queue[0][0] - pre_food)*n_food) <= k:
        now_food = q.get()[0]
        sum_value += (now_food - pre_food) * n_food
        n_food -= 1
        pre_food = now_food
    
    result = sorted(q.queue, key=lambda x:x[1])

    return result[(k-sum_value) % len(q.queue)][1]
if __name__ == "__main__":
    solution([3,1,2], 5)