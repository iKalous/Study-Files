
def solution(num, data):
    n = int(num)
    tot = 0
    ans = [0] * (n + 1)
    tag1 = [0] * (n + 1)
    
    # Parse the input data to set the tags
    for i, ch in enumerate(data):
        if ch == 'L':
            tag1[i + 1] = 1
        elif ch == 'R':
            tag1[i + 1] = -1

    L = 0
    R = 0
    for i in range(1, n + 1):
        L = 0
        R = 0
        for j in range(i - 1, 0, -1):
            if tag1[j] == 1:
                L = 0
                break
            elif tag1[j] == -1:
                L = j
                break

        for j in range(i + 1, n + 1):
            if tag1[j] == -1:
                R = 0
                break
            elif tag1[j] == 1:
                R = j
                break

        if tag1[i] == 1:
            L = i
        if tag1[i] == -1:
            R = i

        if (L == 0 and R == 0) or ((i - L) == (R - i) and L and R):
            ans[tot] = i
            tot += 1

    # Format the output
    if tot == 0:
        return "0"
    else:
        return "{}:{}".format(tot, ",".join(map(str, ans[:tot])))

if __name__ == "__main__":
    # You can add more test cases here
    print(solution(14, ".L.R...LR..L..") == "4:3,6,13,14")
    print(solution(5, "R....") == "0")
    print(solution(1, ".") == "1:1")