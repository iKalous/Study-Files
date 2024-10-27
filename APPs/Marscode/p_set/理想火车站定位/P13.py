def solution(n, m, citizens, locations):
    min_total_distance = float('inf')
    best_location = None

    for location in locations:
        total_distance = 0
        
        for citizen in citizens:
            # 计算曼哈顿距离
            total_distance += abs(location[0] - citizen[0]) + abs(location[1] - citizen[1])
        
        # 更新最小距离和最佳位置
        if total_distance < min_total_distance:
            min_total_distance = total_distance
            best_location = location

    return best_location

if __name__ == "__main__":
    # 添加测试用例
    citizens1 = [[-1, -1], [-1, 1], [1, -1], [1, 1]]
    locations1 = [[3, 2], [1, 0], [0, 0]]
    print(solution(4, 3, citizens1, locations1) == [1, 0])  # 输出：True

    citizens2 = [[0, 0], [0, 4]]
    locations2 = [[0, 2], [0, 3]]
    print(solution(2, 2, citizens2, locations2) == [0, 2])  # 输出：True

    citizens3 = [[10, 10], [20, 20], [30, 30]]
    locations3 = [[15, 15]]
    print(solution(3, 1, citizens3, locations3) == [15, 15])  # 输出：True

    citizens4 = [[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]]
    locations4 = [[4, 5], [6, 7], [8, 9]]
    print(solution(5, 3, citizens4, locations4) == [4, 5])  # 输出：True

    citizens5 = [[10, 10], [20, 20], [30, 30], [40, 40], [50, 50], [60, 60]]
    locations5 = [[35, 35], [45, 45]]
    print(solution(6, 2, citizens5, locations5) == [35, 35])  # 输出：True