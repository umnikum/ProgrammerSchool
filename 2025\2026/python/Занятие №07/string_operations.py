line = input()
#Для определения длинны строки использую функцию len()
length = len(line)
print('line length:', length)

#Давайте найдём первый и последний индекс букв a
first, last = -1, length #Изначально значения некорректны, чтобы мы знали когда нашли нужный символ первый раз
for i in range(length):
	#Проверяем сивол строки под номером i
	if line[i] == 'a' and first<0:
		first = i
	#Проверяем i символ с конца строки
	if line[-i] == 'a' and last == length:
		last = length-i
	#Не обязательно, но когда мы нашли оба символа, то можно прерваться
	if first >= 0 and last < length:
		break
#Для проверки выведем найденные позиции и строку лежащую между ними
print(first, last, line[first:last+1])
#Не забываем что если символа в строке не было, программа бдет работать некорректно

#Теперь введём 2 строки
line1, line2 = input(), input()
#Проверим что вторая строка является частью(подстрокой) первой
if line2 in line1:
	print('substring')
else:
	print('independent')
