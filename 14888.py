calc = [lambda a,b:a+b,lambda a,b: a-b,lambda a,b: a*b,
        lambda a,b: a//b if a>0 else -((-a)//b)]

def f(num, op, ans):
    if len(num) == 0:
        return ans, ans
    max_, min_ = -(100 ** 11), 100 ** 11

    for i in range(4):
        if op[i] > 0:
            op[i] -= 1
            max_f, min_f = f(num[1:], op, calc[i](ans, num[0]))
            op[i] += 1
            if max_ < max_f:
                max_ = max_f
            if min_ > min_f:
                min_ = min_f
    return max_, min_


n = int(input())
num = list(map(int, input().strip().split()))
op = list(map(int, input().strip().split()))

max_, min_ = f(num[1:], op, num[0])
print(max_)
print(min_)
