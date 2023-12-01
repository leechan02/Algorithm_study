N = int(input())

arr = set()

for _ in range(N):
	tmp = int(input())
	arr.add(tmp)

for num in sorted(arr):
	print(num)