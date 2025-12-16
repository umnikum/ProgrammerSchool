'''
В программировани часто ведётся работа с данными из отдельного файла
Чтобы прочитать информацию из файла пользуюся командой open()
'''
#Открываем файл input.txt в переменную infile
with open('input.txt', 'r')as infile:
	#Проходимся по каждой строке текстового файла
	for line in infile:
		#Чтобы не выводить лишний перенос строки выводим подстроку без последнего символа
		print(line[:-1])#Можно ьакже пользоваться line.strip()

#Открываем файл output.txt в переменную outfile
with open('output.txt', 'w')as outfile:
	#Записываем информацию методом write переменной outfile
	outfile.write('first line\n')
	outfile.write('second line\n')
	outfile.write('third line')
