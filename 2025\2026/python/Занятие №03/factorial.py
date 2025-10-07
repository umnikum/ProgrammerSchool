n = int(input())
factorial = 1
for i in range(1, n+1):
	factorial = factorial * i
	#Можно упростить, пользуясь сокращённым оператором: factorial *= i
print(factorial)
