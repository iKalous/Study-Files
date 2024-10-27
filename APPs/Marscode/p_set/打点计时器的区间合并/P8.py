
def solution(inputArray):
    class Interval:
        def __init__(self, start, end):
            self.st = start
            self.ed = end

    n = len(inputArray)
    ans = 0
    st = -(10**9 + 7)
    ed = -(10**9 + 7)

    # Convert list of lists to list of custom objects for easier access
    a = [Interval(start, end) for start, end in inputArray]

    # Sort the intervals based on the start time, and then by the end time if starts are equal
    a.sort(key=lambda x: (x.st, x.ed))

    for interval in a:
        if interval.st > ed:
            if a.index(interval) != 0:  # Check if it's not the first interval
                ans += ed - st + 1
            st = interval.st
            ed = interval.ed
        else:
            ed = max(ed, interval.ed)

    ans += ed - st + 1
    return ans

if __name__ == "__main__":
    testArray1 = [[1, 4], [7, 10], [3, 5]]
    testArray2 = [[1, 2], [6, 10], [11, 15]]

    print(solution(testArray1) == 7)
    print(solution(testArray2) == 9)