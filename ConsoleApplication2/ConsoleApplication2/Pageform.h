#pragma once
#include <iostream>
#include "Windows.h"
using namespace std;
//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
//наверно необходимы функции 2 
//одна для менюшки, ввтора для отрисовки таблицы данных

void PrintMenu(const char * pop[], int size)
{
	cout << "|------------------------------MENU-----------------------------------|" << endl;

	//cout << "---------------------------------------------------------------------" << endl;
	for (int i = 0, j = 1, k = 2, l = 0; i < size * 5 - 2; i++)
	{
		
		if (i == j) {
			cout << pop[l] <<endl;
			//cout  << "ZALUPA PUPA" << endl;
			j += 5;
			l++;
		}
		else if ((i == k)|| (i == size*5 - 3)) {
			cout << "|---------------------------------------------------------------------|" << endl;
			k += 5;
		}
		else cout << "|                                                                     |" << endl;
	}
		
}
