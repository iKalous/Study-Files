
def solution(plates, n):
    # Since the problem statement indicates that the plates are already sorted in ascending order,
    # we can skip the sorting step. The 'n' parameter is not needed as the length of 'plates' can be used directly.

    # Initialize the result list
    result = []

    # Initialize the current stack
    i = 0
    while i < n:
        start = i
        # Find the next sequence that has at least 3 plates
        while i < n - 1 and plates[i] + 1 == plates[i + 1]:
            i += 1
        # Check if the sequence has at least 3 plates
        if i - start >= 2:
            result.append(f"{plates[start]}-{plates[i]}")
        else:
            for j in range(start, i + 1):
                result.append(str(plates[j]))
        i += 1

    # Join the result list into a string separated by commas
    return ",".join(result)

# Test cases
if __name__ == "__main__":
    print(solution([-3, -2, -1, 2, 10, 15, 16, 18, 19, 20], 10) == "-3--1,2,10,15,16,18-20")
    print(solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20], 20) == "-6,-3-1,3-5,7-11,14,15,17-20")
    print(solution([1, 2, 7, 8, 9, 10, 11, 19], 8) == "1,2,7-11,19")