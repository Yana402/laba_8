#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <Windows.h>
int isalpha(char symb)
{
	if (symb >= 'a' && 'z' <= symb || symb >= 'A' && 'Z' <= symb)
		return 1;
	else
		return 0;
}
void strmaxword(char* str, int symb)
{
	int counter = 0; // в этой переменной мы будем считать длинну слова
	int max = 0; // в этой переменной мы будем сохранять максимальное значение длинны слова
	int id = 0; // в этой переменной мы будем сохранять индекс первой буквы слова, чтобы потом вывести
	int i;
	for (i = 0; i < symb; i++) // проходимся по строке
	{
		if (isalpha(str[i])) // если встречаем букву
			counter++; // то увеличиваем длинну слова
		else // в противном случае мы вышли за пределы слова
		{
			// и тогда начинаем сравнивать
			if (counter > max) // если длинна слова больше максимальной длинны
			{
				max = counter; // макисмальному значению присваиваем длинну текущего слова
				id = i - counter; // вычисляем индекс начала слова: от текущего значения i отнимаем длинну слова и получаем его начало
			}
			counter = 0; // при переходе к следующему слову обнуляем переменную длинны слова
		}
	}
	// для того, чтобы проверить еще и последнее слово, является ли оно самым длинным
	if (counter > max)
	{
		max = counter;
		id = i - counter;
	}
	max += id;
	for (i = id; i < max; i++)
		printf("%c", str[i]);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char** txt;
	int sent, symb;
	// ввод размерностей текста
	printf("Введите количетсов предложений в тексте: ");
	scanf_s("%d", &sent);
	printf("\nВведите количество символов в предложении: ");
	scanf_s("%d", &symb);
	// выделение памяти
	if (!(txt = (char**)malloc(sent * sizeof(char))))
		return 0;
	for (int i = 0; i < sent; i++)
		txt[i] = (char*)malloc(symb * sizeof(char));
	// ввод текста
	printf("\nВведите текст. Точки в конце каждого предложения будут установлены автоматически: ");
	for (int i = 0; i < sent; i++)
		for (int j = 0; j < symb; j++)
			txt[i][j] = getchar();
	// установка точек в конце каждого предложения
	for (int i = 0; i < sent; i++)
		txt[i][symb - 1] = '.';
	system("CLS");
	// вывод текста. Каждое предложение с новой строки
	for (int i = 0; i < sent; i++, putchar('\n'))
		for (int j = 0; j < symb; j++)
			printf("%c", txt[i][j]);
	// вызываем функцию в цикле по строкам для каждой строки и выводим максимальное в ней слово
	for (int i = 0; i < sent; i++, putchar('\n'))
	{
		printf("В предложении номер %d максимальное слово: ", i + 1);
		strmaxword(txt[i], symb);
	}
	// освобождение памяти
	for (int i = 0; i < sent; i++)
		free(txt[i]);
	free(txt);
	return 0;
}