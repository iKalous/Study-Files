def solution(binary1, binary2):
    # 将二进制字符串转换为十进制整数
    decimal1 = int(binary1, 2)
    decimal2 = int(binary2, 2)
    
    # 计算二进制数的和并返回字符串形式
    result = decimal1 + decimal2
    return str(result)

if __name__ == "__main__":
    # 你可以在这里添加更多测试用例
    print(solution("101", "110") == "11")
    print(solution("111111", "10100") == "83")
    print(solution("111010101001001011", "100010101001") == "242420")
    print(solution("111010101001011", "10010101001") == "31220")
    print(solution("11", "1") == "4")