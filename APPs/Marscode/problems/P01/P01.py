def solution(distance, n, gas_stations):
    Max = 998244353
    a = [(0, 0)] + [(distance - gas_stations[i][0], gas_stations[i][1]) for i in range(n)] + [(0, 0), (distance + 200, 0)]
    a.sort()  # Sort based on the first element of each tuple

    ans = Max

    def dfs(x, now, tot):
        nonlocal ans
        if x == n + 2:
            ans = min(ans, tot)
            return
        
        j = x + 1
        k = Max
        fg = 0
        dd = 0

        for i in range(now + 1):
            while j <= n + 2 and a[x][0] + i >= a[j][0]:
                if a[j][1] <= k:
                    k = a[j][1]
                    dd = j
                    fg = 1
                j += 1

        if k <= a[x][1]:
            dfs(dd, now - (a[dd][0] - a[x][0]), tot + max(a[dd][0] - a[x][0] - now,0) * a[x][1])
        else:
            j = x + 1
            k = Max
            dd = 0
            mx = min(200,distance + 200 - a[x][0]) if x == 1 else min(400,distance + 200 - a[x][0])
            
            for i in range(mx + 1):
                while j <= n + 2 and a[x][0] + i >= a[j][0]:
                    if a[j][1] <= k:
                        k = a[j][1]
                        dd = j
                        fg = 1
                    j += 1
            
            if not fg:
                return -1  # Equivalent to end()
            
            if k <= a[x][1]:
                dfs(dd, 0, tot + max(a[dd][0] - now - a[x][0],0) * a[x][1])
            else:
                dfs(dd, 400 - (a[dd][0] - a[x][0]), tot + (min(400,distance + 200 - a[x][0]) - now) * a[x][1])

    dfs(0, 200, 0)

    return ans if ans != Max else -1

if __name__ == "__main__":
    gas_stations1 = [(100, 1), (200, 30), (400, 40), (300, 20)]
    gas_stations2 = [(100, 999), (150, 888), (200, 777), (300, 999), (400, 1009), (450, 1019), (500, 1399)]
    gas_stations3 = [(101, 0), (100, 100), (102, 1)]
    gas_stations4 = [(34, 1), (105, 9), (9, 10), (134, 66), (215, 90), (999, 1999), (49, 0), 
                     (10, 1999), (200, 2), (300, 500), (12, 34), (1, 23), (46, 20), (80, 12), 
                     (1, 1999), (90, 33), (101, 23), (34, 88), (103, 0), (1, 1)]

    print(solution(500, 4, gas_stations1))  # Example test case
    print(solution(500, 7, gas_stations2))
    print(solution(500, 3, gas_stations3))
    print(solution(100, 20, gas_stations4))
    print(solution(100, 0, []))
