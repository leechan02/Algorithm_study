import sys

for _ in range(3):
    n = int(sys.stdin.readline().strip())
    total = 0

    for _ in range(n):
        total += int(sys.stdin.readline().strip())

    if total == 0:
        print("0")
    elif total > 0:
        print("+")
    else:
        print("-")
