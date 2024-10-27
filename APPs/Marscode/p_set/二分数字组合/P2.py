def solution(n, A, B, array_a):
    P = 10**9 + 7
    a = [x % 10 for x in array_a]
    sum_a = sum(a) % 10
    ans = 0
    
    if (sum_a + 10 - A) % 10 != B:
        if sum_a == A:
            ans += 1
        if sum_a == B:
            ans += 1
        return ans

    f = [[0] * 10 for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        f[i][a[i - 1]] += 1  # a[i-1] for zero-based index
        for j in range(10):
            f[i][j] += f[i - 1][j] + f[i - 1][(j + 10 - a[i - 1]) % 10]
            f[i][j] %= P

    ans = f[n][A]
    return ans

if __name__ == "__main__":
    # You can add more test cases here
    print(solution(3, 1, 2, [1, 1, 1]) == 3)
    print(solution(3, 3, 5, [1, 1, 1]) == 1)
    print(solution(2, 1, 1, [1, 1]) == 2)