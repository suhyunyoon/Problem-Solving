import sys

n = int(input())

# eof까지 입력 받은 후 두개씩 잘라서 새로운 배열에 넣음
data = []
raw_data = list(map(int, sys.stdin.read().split()))
for i in range(0,n*2,2):
    data.append(raw_data[i:i+2])

# 끝 시간 순으로(같으면 시작시작도 봄) 정렬
data = sorted(data, key=lambda x : (x[1], x[0]))

# 지금 끝 시간 뒤 바로 시작할 수 있는 회의가 나오면 count++
last_time = data[0][1]
count = 1
for d in data[1:]:
    if last_time <= d[0]:
        count += 1
        last_time = d[1]

print(count)
