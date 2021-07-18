
def dfs(arr, sum_):
    if len(arr) <= 2:
        return sum_

    max_, max_idx = 0, 1
    for i in range(1, len(arr)-1):
        t_arr = arr.copy()
        t_arr.pop(i)
        t = dfs(t_arr, sum_ + t_arr[i-1] * t_arr[i])
        if t > max_:
            max_, max_idx = t, i

    return max_

n = input()
arr = list(map(int, input().split()))

ans = dfs(arr, 0)
print(ans)