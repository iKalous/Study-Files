
def solution(x_position, y_position):
    # 特殊情况，如果x和y相等，则不需要移动
    if x_position == y_position:
        return 0
    
    # 计算x和y的差值
    n = abs(y_position - x_position)
    
    # 计算累积和
    sum_values = [0] * (n + 1)
    for i in range(1, n + 1):
        sum_values[i] = sum_values[i - 1] + i
    
    # 初始化答案
    ans = 0
    
    # 遍历寻找答案
    for i in range(1, n + 1):
        if sum_values[i] + sum_values[i - 1] == n:
            ans = i + i - 1
            break
        elif sum_values[i] + sum_values[i - 1] < n and 2 * sum_values[i] >= n:
            ans = 2 * i
            break
        elif 2 * sum_values[i] < n and 2 * sum_values[i] + i >= n:
            ans = 2 * i + 1
            break
    
    return ans

# 测试样例
if __name__ == "__main__":
    # 测试样例
    print(solution(12, 6) == 4)
    print(solution(34, 45) == 6)
    print(solution(50, 30) == 8)
    print(solution(0, 0) == 0)