#pragma once

#include "Exceptions.h"
#include <string>
#include <fstream>
#include <iostream>
#include "windows.h"

using namespace std;
bool NumInChar(char* text)
{
	int i;
	if (i = atoi(text)) return true;
	else return false;
}
char *readtxt()// ������� ��� ���������� �������� �� ������� � ������ � ���������� ���� char *
{
	char *text = (char *)malloc(255);
	char c;
	int numOfChars = 0;
	cin >> text;
	while ((c = getchar()) != '\n')
	{
		realloc(text, numOfChars + 1);
		text[numOfChars] = c;
		numOfChars++;
	}
	return text;
}

int Test_int()
{
	int pop_n;
	char* q;
	bool lol = true;
	while (lol)//���������� ������ ���-�� ����� � ���������� ���� char � ���������� ����������� � int (����� ��� �������� �� �������� ������� ������ �����)
	{
		q = readtxt();
		try
		{
			pop_n = atoi(q);
			if ((pop_n < 0) || !(NumInChar(q))) throw value_1;//NumInChar � ����� Tours.h
			if (pop_n == 2147483647) throw value_4;

			lol = false;
		}
		catch (Zero_Negative_except)// �������� �� ������������� ��� ������� ���-�� 
		{
			cout << value_1.what() << endl;
		}
		catch (Over_Hagrid_except)
		{
			cout << value_4.what() << endl;
			//cout << "Was entered too many number! Try again!" << endl;
		}
		catch (...)
		{
			cout << "ERROR!";
			system("pause");
			abort();
		}
	}
	return pop_n;
}


int HowMuchString(const char * file_name)//�� ������ ������� �������
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* InputFile;
	if ((InputFile = fopen(file_name, "r")) == NULL)
	{
//		printf("Can not open file!\n");
		return 0;
	}
	char symbol;
	int ColWord = 1;
	while ((symbol = fgetc(InputFile)) != EOF)
	{
		//if ((symbol == '\n') || (symbol == ' ') || (symbol == '\t'))
		if (symbol == '\n')ColWord++;
	}
	fclose(InputFile);
	return ColWord;
}


string * parser_string(const char * file_name)// �����, ������� �� ��������
{
	ifstream in(file_name);
	int i = 0;
	int size = HowMuchString(file_name);
	string * buf = new string[size];
	while (in >> buf[i])
	{
		i++;
	}
	in.close();
	return buf;
}

