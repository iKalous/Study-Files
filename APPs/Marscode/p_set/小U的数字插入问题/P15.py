
def solution(a: int, b: int) -> int:
    a_str = str(a)
    b_str = str(b)
    max_result = ""

    # 找到合适的插入位置
    for i in range(len(a_str)):
        temp = a_str[:i] + str(b) + a_str[i:]
        if temp > max_result or max_result == "":
            max_result = temp

    # 检查将b添加到末尾的情况
    temp = a_str + str(b)
    if temp > max_result:
        max_result = temp

    return int(max_result)

if __name__ == '__main__':
    print(solution(76543, 4) == 765443)
    print(solution(1, 0) == 10)
    print(solution(44, 5) == 544)
    print(solution(666, 6) == 6666)