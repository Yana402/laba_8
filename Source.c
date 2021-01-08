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
	int counter = 0; // � ���� ���������� �� ����� ������� ������ �����
	int max = 0; // � ���� ���������� �� ����� ��������� ������������ �������� ������ �����
	int id = 0; // � ���� ���������� �� ����� ��������� ������ ������ ����� �����, ����� ����� �������
	int i;
	for (i = 0; i < symb; i++) // ���������� �� ������
	{
		if (isalpha(str[i])) // ���� ��������� �����
			counter++; // �� ����������� ������ �����
		else // � ��������� ������ �� ����� �� ������� �����
		{
			// � ����� �������� ����������
			if (counter > max) // ���� ������ ����� ������ ������������ ������
			{
				max = counter; // ������������� �������� ����������� ������ �������� �����
				id = i - counter; // ��������� ������ ������ �����: �� �������� �������� i �������� ������ ����� � �������� ��� ������
			}
			counter = 0; // ��� �������� � ���������� ����� �������� ���������� ������ �����
		}
	}
	// ��� ����, ����� ��������� ��� � ��������� �����, �������� �� ��� ����� �������
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
	// ���� ������������ ������
	printf("������� ���������� ����������� � ������: ");
	scanf_s("%d", &sent);
	printf("\n������� ���������� �������� � �����������: ");
	scanf_s("%d", &symb);
	// ��������� ������
	if (!(txt = (char**)malloc(sent * sizeof(char))))
		return 0;
	for (int i = 0; i < sent; i++)
		txt[i] = (char*)malloc(symb * sizeof(char));
	// ���� ������
	printf("\n������� �����. ����� � ����� ������� ����������� ����� ����������� �������������: ");
	for (int i = 0; i < sent; i++)
		for (int j = 0; j < symb; j++)
			txt[i][j] = getchar();
	// ��������� ����� � ����� ������� �����������
	for (int i = 0; i < sent; i++)
		txt[i][symb - 1] = '.';
	system("CLS");
	// ����� ������. ������ ����������� � ����� ������
	for (int i = 0; i < sent; i++, putchar('\n'))
		for (int j = 0; j < symb; j++)
			printf("%c", txt[i][j]);
	// �������� ������� � ����� �� ������� ��� ������ ������ � ������� ������������ � ��� �����
	for (int i = 0; i < sent; i++, putchar('\n'))
	{
		printf("� ����������� ����� %d ������������ �����: ", i + 1);
		strmaxword(txt[i], symb);
	}
	// ������������ ������
	for (int i = 0; i < sent; i++)
		free(txt[i]);
	free(txt);
	return 0;
}