import sys

n = int(input())

raw_input_ = sys.stdin.read().split()

data = []
raw_data = list(map(int, raw_input_))

for i in range(0,n*2,2):
    data.append(raw_data[i:i+2])

data = sorted(data, key=lambda x : (x[1], x[0]))

last_time = data[0][1]
count = 1

for d in data[1:]:
    if last_time <= d[0]:
        count += 1
        last_time = d[1]

print(count)
