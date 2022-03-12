n, x = map(int, input().split())
s = input()

for i in range(n):
	if s[i] == 'U':
		x = (int)(x / 2)
	elif s[i] == 'L':
		x = 2 * x
	else:
		x = 2 * x + 1

print(x)