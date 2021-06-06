'''p, n = list(map(int, input().split()))
a = list(map(int, input().split()))

s = 0
for i in a:
    s = (s * p) + i
    s %= 1000000007

print(s)
'''
import sys

data = []
total = 0
p, n = list(map(int, input().split()))
data = [int(d) for d in input().split()]

total += data[0]
for d in data[1:]:
        total *= p
        total += d
print(total % 1000000007)
