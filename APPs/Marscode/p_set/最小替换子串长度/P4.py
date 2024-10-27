def solution(input):
    n = len(input)
    target_count = n // 4
    
    # 计算每个字符的频率
    count = {'A': 0, 'S': 0, 'D': 0, 'F': 0}
    for char in input:
        count[char] += 1
    
    # 计算超出目标频率的字符数量
    excess = {char: max(0, count[char] - target_count) for char in count}
    
    # 如果所有字符的频率都已经满足要求，返回 0
    if sum(excess.values()) == 0:
        return 0
    
    # 找到最小替换子串长度
    min_length = n  # 初始设为字符串长度
    left = 0  # 滑动窗口的左边界
    
    for right in range(n):
        # 处理当前字符
        count[input[right]] -= 1
        
        # 检查当前窗口是否有效
        while all(count[char] <= target_count for char in count):
            min_length = min(min_length, right - left + 1)
            count[input[left]] += 1  # 收缩左边界
            left += 1
            
    return min_length

if __name__ == "__main__":
    # 添加测试用例
    print(solution("ADDF") == 1)  # 输出：1
    print(solution("ASAFASAFADDD") == 3)  # 输出：3
    print(solution("SSDDFFFFAAAS") == 1)  # 输出：1
    print(solution("AAAASSSSDDDDFFFF") == 0)  # 输出：0
    print(solution("AAAADDDDAAAASSSS") == 4)  # 输出：4