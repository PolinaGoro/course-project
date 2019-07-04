// ParsingHTML.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

using namespace std;

int HowMuchString(const char * file_name)
{
	FILE* InputFile;
	if ((InputFile = fopen(file_name, "r")) == NULL)
	{
		//printf("Can not open file!\n");
		//getch();
		return 0;
	}
	char symbol;
	int ColWord = 0;
	while ((symbol = fgetc(InputFile)) != EOF)
	{
		if ((symbol == '\n') || (symbol == ' ') || (symbol == '\t'))
			ColWord++;
	}
	fclose(InputFile);
	return ColWord;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char * tfile = "textFile.txt";
	
	ifstream input2("Html_1.txt");
	string bufHTML1;
	int size = HowMuchString("Html_1.txt");
	string * buf = new string[size];
	int i = 0;
	while (input2 >> buf[i])
	{
		i++;
	}
	for (int i = 0; i < size; i++)
	{
		bufHTML1.insert(bufHTML1.size(), buf[i].c_str());
		bufHTML1.insert(bufHTML1.size(), "\n\t");
	}
	input2.close();
	char headInfo [50]= " You open file: ";
	strcat(headInfo, tfile);
	bufHTML1.insert(bufHTML1.size(), headInfo);
	////////////////////////////////////////////////////////////////
	ifstream input3("Html_2.txt");
	string bufHTML2;
	int size2 = HowMuchString("Html_2.txt");
	string * buf2 = new string[size2];
	int i2 = 0;
	while (input3 >> buf2[i2])//видимо выделяет недостаточно памяти 
	{
		i2++;
	}
	for (int i = 0; i < size2; i++)
	{
		bufHTML2.insert(bufHTML2.size(), buf2[i].c_str());
		bufHTML2.insert(bufHTML2.size(), "\n\t");
	}
	input3.close();
	///////////////////////////////////////////////////////////////////
	ifstream input(tfile);
	string buffer;
	getline(input, buffer);
	input.close();
	/////////////////////////////////////////////////////////////////
	ifstream input4("Html_3.txt");
	string bufHTML3;
	int size3 = HowMuchString("Html_3.txt");
	string * buf3 = new string[size];
	int i3 = 0;
	while (input4 >> buf3[i3])
	{
		i3++;
	}
	for (int i = 0; i < size3; i++)
	{
		bufHTML3.insert(bufHTML3.size(), buf3[i].c_str());
		bufHTML3.insert(bufHTML3.size(), "\n\t");
	}
	input4.close();
	////////////////////////////////////////////////////////////////////
	string allHTML;
	allHTML.insert(allHTML.size(), bufHTML1.c_str());
	allHTML.insert(allHTML.size(), bufHTML2.c_str());
	allHTML.insert(allHTML.size(), buffer.c_str());
	allHTML.insert(allHTML.size(), bufHTML3.c_str());
	//////////////////////////////////////////////////////////////////
	ofstream htmlfile("FileInHTML.html");
	htmlfile << allHTML;
	htmlfile.close();
	cout << "Конвертация файла прошла успешно!\nФайл FileInHTML(наша веб-страница) находится в папке ParsingHTML." << endl;
	//////////////////////////////////////////////////////////////////
	system("pause");
	return 0;
}
