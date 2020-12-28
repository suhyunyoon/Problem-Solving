input_ = list(map(int, input().split()))
n, k = input_[0], input_[1]

def f(s, d, cnt, t):
    pass


ans, trace = f(k, n, 0, [])
print(ans)
for i, v in enumerate(trace):
    print(v, end=' ')
    if v == trace[-1]:
        break

    if trace[i+1] / v != 2.0:
        