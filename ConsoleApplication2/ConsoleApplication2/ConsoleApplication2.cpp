// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once

#include "pch.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "PageForm.h"
#include "UserinProg.h"
#include "Logic.h"
#include "LogicOfInerface.h"
#include "Conteiner.h"
#include <ctime>
#include <map>
#include "OutputRazdels.h" 
#include "WorkwithTime.h"
#include "Data.h"

using namespace std;
using namespace data_a;
using namespace data_d;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	User user;


skip:
	bool point = true;
	while (point)
	{
		cout << "\tМЕНЮ" << endl;

		cout << "0 - Войти с учентой записи гостя \n1 - Авторизироваться \n2 - Зарегистрироваться" << endl;

		int i1;
			//= Test_int();
		cin >> i1;
		switch (i1)
		{

		case 0: {
			User guest(0, " ", " ", " ", 0);
			cout << "Вы вошли под учетной записью гостя." << endl;
			point = false;
			break;
		}
		case 1:
		{
			User client = InAccaunt("Users3.txt");
			user = client;
			point = false;
			break;
		}
		case 2:
		{
			User client = Registration("Users3.txt");
			user = client;
			point = false;
			break;
		}
		default: {
			cout << "Введены некорректные данные!" << endl;
		}
		}
	}

	ifstream list("Talons.txt");
	int size_con = HowMuchString("Talons.txt") / 10;
	ConteinerTalons list2(size_con);
	list >> list2;
	time_t t = time(NULL);
	//tm *start_data = localtime(&t);
	tm start_data;
	start_data.tm_year = 2019;
	start_data.tm_mon = 5;
	start_data.tm_mday = 27;
	///////////////////

	Doctor d1("Терапевт ", "Масюкин", 100, 500, 10, 100);
	Doctor d2("Терапевт ", "Грыжин", 100, 500, 10, 100);
	Analiz a1(string("Анализ"), string("крови"), 111, 444, 15, 100);
	Analiz a2(string("Анализ"), string("желез"), 123, 345, 30, 100);

	Analiz arr_a2[2] = { a1, a2 };
	Doctor arr_d2[2] = { d1, d2 };
	//ConteinerTalons list2 = createTalons(arr_a2, 2, arr_d2, 2, start_data, 1);

	////////////////////////////

		//ConteinerTalons list2 = createTalons(arr_a, arr_a_size, arr_d  , arr_d_size, start_data, 11);
	//ConteinerTalons list2;
	//list >> list2;
	
	while (true)
	{
		cout << "\tМЕНЮ" << endl;

		cout << "0 - Вернуться в меню авторизации/регистрации \n1- Просмотреть доступные разделы медицины" << endl
			<< "2 - Просмотреть все имеющиеся талоны \n3 - Просмотреть контакнтные данные \n";
		if(user.number_cart != -858993460){

			cout << "4 - Просмотр личных данный\n" <<
				"5 - Забронировать талон\n" <<
				"6 - Просмотр забронированных талонов\n ";
		}
			cout << "9 - Выйти из программы" << endl;
			int i2;
			//= Test_int();
		cin >> i2;
		switch (i2)
		{

		case 0:
		{
			goto skip;
		}
		case 1:
		{
			cout << "Список доступных разделов анализов:" << endl;
			readDepartment_a(arr_a, arr_a_size, false);
			cout << "Список доступных спецификаций докторов:" << endl;
			readDepartment_d(arr_d, arr_d_size, false);

			cout << "Вернуться в главное меню - 0 \n" <<
				"Просмотреть разделы конкретного анализа - 1\n" <<
				"Просмотреть фамилии докторов конретной спецификации - 2" << endl;


			while (1)
			{
				try
				{
					int point_2;
					cin >> point_2;
					if ((point_2 < 0) && (point_2 > 2))throw un_data;
					if (point_2 == 1)
					{
						//string word_spec_1;
						//cin >> word_spec_1;
						readDepartment_a(arr_a, arr_a_size, true);
					}
					else if (point_2 == 2)
					{
						//string word_spec;
						//cin >> word_spec;
						readDepartment_d(arr_d, arr_d_size, true);
					}
					else if (point_2 == 0)
					{
						system("cls");
						goto skip;
					}

					break;
				}
				catch (Uncorrect_data) {
					cout << un_data.what() << endl;
				}
			}
			system("pause");
			break;
		}
		case 2:
		{
			cout << list2;
			system("pause");
			break;
		}
		case 3:
		{
			Contacts();
			system("pause");
			break;

		}
		case 4:
		{
			cout << user;
			system("pause");
			break;
		}
		case 5:
		{
			watchTalons(user.number_cart);
			system("pause");
			break;
		}
		case 6:
		{
			zakazTalona(user.number_cart);
			system("pause");

		}
		case 9:
		{
			break;
		}
		default: {
			cout << "Вы ввели некорректные данные!";
			system("pause");
		}
			 
		}
		system("cls");
	}
	return 0;
	system("pause");
}
