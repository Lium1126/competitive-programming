import math

A, B = map(int, input().split())

def f(x):
	return (A / math.sqrt(x + 1)) + (x * B)
	
def df(x):
	return -(A / (x + 1)) + B

if A <= b:
	print(A)
	return

# 勾配降下法に必要なパラメータ
eta = 0.5
max_iteration = 1000000
x0 = 0
x_pred = []

# 最大反復回数まで計算する
for i in range(max_iteration):
	if -0.1 <= df(x0) and df(x0) <= 0.1:
		break
	x0 = x0 - eta * df(x0)
	x_pred.append(x0)

print(x_pred[-1])
print(f(x_pred[-1]))