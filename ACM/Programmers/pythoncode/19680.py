def solution(cacheSize, cities):
    answer = 0
    cache = []

    if cacheSize == 0:
        return 5*len(cities)
        
    for city in cities:
        city_lower = city.lower()
        if city_lower in cache:
            answer += 1
            cache.remove(city_lower)
            cache.append(city_lower)
        else:
            if len(cache) == cacheSize:
                answer += 5
                cache.pop(0)
                cache.append(city_lower)
            else:
                answer += 5
                cache.append(city_lower)
    return answer

if __name__ == "__main__":
    solution(5, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"])