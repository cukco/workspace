from collections import deque

q = deque()   

while True:
    line = input().strip()
    if line == "#":
        break

    parts = line.split()

    if parts[0] == "PUSH":
        v = int(parts[1])
        q.append(v)        # thêm vào cuối hàng đợi
    elif parts[0] == "POP":
        if len(q) == 0:
            print("NULL")  # hàng đợi rỗng
        else:
            print(q.popleft())  # lấy và in phần tử đầu tiên
