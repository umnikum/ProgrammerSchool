a,b,c = map(int, input().split())
'''
Проверяем по очереди на наименьшее a,b,c и выводим результат проверки
'''
if a<b and a<c:
	print(a)
elif b<c:
	print(b)
else:
	print(c)
