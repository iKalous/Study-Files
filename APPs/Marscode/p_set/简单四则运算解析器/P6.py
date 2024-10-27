import math

def solution(expression):
    try:
        # 使用 eval 计算表达式的值
        result = eval(expression)
        return math.floor(result)  # 向下取整
    except ZeroDivisionError:
        return "Error: Division by zero"
    except Exception as e:
        return f"Error: {str(e)}"

if __name__ == "__main__":
    print(solution("1+1") == 2)
    print(solution("3+4*5/(3+2)") == 7)
    print(solution("4+2*5-2/1") == 12)
    print(solution("(1+(4+5+2)-3)+(6+8)") == 23)
    print(solution("2*(5+5*2)/3+(6+8*3)") == 40)