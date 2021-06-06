a = []
for i in range(9):
    t = int(input())
    a.append(t)
b = sorted(a)

print(b[-1])
print(a.index(b[-1])+1)
