def solution(dna1, dna2):
    m, n = len(dna1), len(dna2)
    max_val = 998244353
    f = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                f[i][j] = i + j
            elif dna1[i - 1] == dna2[j - 1]:
                f[i][j] = f[i - 1][j - 1]
            else:
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1)

    return f[m][n]

if __name__ == "__main__":
    # You can add more test cases here
    print(solution("AGCTTAGC", "AGCTAGCT") == 2)
    print(solution("AGCCGAGC", "GCTAGCT") == 4)