#pragma once
#include "Logic.h"
#include <fstream>
#include <string>

User Registration(const char* file_name)
{
	ifstream in(file_name);
	int i = 0;
	int size = HowMuchString(file_name);
	string * buf = new string[size];
	int j = 0;

	while (getline(in, buf[j]))
	{
		j++;
	}
	in.close();

	int cart_num = 0;
	string name1;
	string name2;
	string name3;
	int password;

	int buttom;
	bool povt = false;
	while (1)
	{
		while (1) {
			cout << "Введите номер карты :" << endl;
			cin >> cart_num;
			if (cart_num <= 0)
				cout << "Повторите ввод! " << endl;
			else break;
		}

		while (1)
		{
			cout << "и ФИО :" << endl;
			cin >> name1;
			cin >> name2;
			cin >> name3;
			if ((name1.c_str() == "0") || (name2.c_str() == "0") || (name3.c_str() == "0"))//возможно потребуется коррекция
				cout << "ВЫ не ввели данные, введите все поля!" << endl;
			else break;
		}

		for (int i = 0; i < size; i += 5)
		{
			if (atoi(buf[i].c_str()) == cart_num)
			{
				cout << "Данный номер карты уже существует!\n Перепишите данные для регистрации или войдите в гостевой аккаунт в разделе автризации!" << endl;
				povt = true;
				break;
			}
			if ((name1 == buf[i + 1]) && (name2 == buf[i + 2]) && (name3 == buf[i + 3]))
			{
				cout << "Данное ФИО уже существует!\n Перепишите данные для регистрации или войдите в гостевой аккаунт в разделе авторизации!" << endl;
				povt = true;
				break;
			}
		}

		if (povt == false)break;
		
	}

		cout << "Введите пароль: ";
		cin >> password;
		cout << "Вы успешно зарегистрировались!" << endl;
		//to_string(password);
		User user(cart_num, name1, name2, name3, password);
		ofstream out (file_name, ios::app);
		out << user;
		out.close();
		return user;
}

User InAccaunt( const char* file_name)
{
	string name1;
	string name2;
	string name3;

	int cart_num = 0;

	int buttom = 0;
	
	while (1) {
		cout << "Введите номер карты (если вам не известен номер карты введите 0):" << endl;
		cin >> cart_num;
		cout << "и ФИО(если вам не известно ваше точное ФИО введите 0 0 0 ):" << endl;
		cin >> name1;
		cin >> name2;
		cin >> name3;
		if ((name1.c_str() == "0") && (name2.c_str() == "0") && (name3.c_str() == "0") && (cart_num == 0))
			cout << "ВЫ не ввели данные, введите хотя бы одно из полей!" << endl;
		else break;
	}

	ifstream in(file_name);
	int i = 0;
	int size = HowMuchString(file_name);
	string * buf = new string[size];
	int j = 0;

	while (getline(in, buf[j]))
	{
		j++;
	}

	in.close();
	
	if (cart_num != 0){
		for (int i = 0; i < size; i+=5)
		{
			if (atoi(buf[i].c_str()) == cart_num)
			{
				cout << "Ваша учетная запись найдена!" << endl;
				int password;

				while (1)
				{
					cout << "Введите пароль: " ;
					cin >> password;
					if (atoi(buf[i + 4].c_str()) == password)
					{
						cout << "Вы успешно авторизировались!" << endl;
						name1 = buf[i + 1];
						name2 = buf[i + 2];
						name3 = buf[i + 3];
						User user(atoi(buf[i].c_str()), name1, name2, name3, atoi(buf[i + 4].c_str()));
						return user;
					}
					else
					{
						cout << "Введен неверный пароль!" << endl;
						cout << "для входа под аккаунтом гостя - 1" << endl;
						cin >> buttom;
						if (buttom == 1) break;

					}
				}
			}
			if (buttom == 1) break;
		}
		cout << "Учетной записи под данным номером карты не существует!" << endl;
	}
	else
	{
		for (int i = 0; i < size; i+=5)
		{
			if ((name1 == buf[i + 1]) && (name2 == buf[i + 2]) && (name3 == buf[i + 3]))
			{
				cout << "Ваша учетная запись найдена!" << endl;
				int password;

				while (1)
				{
					cout << "Введите пароль: ";
					cin >> password;
					if (atoi(buf[i + 4].c_str()) == password)
					{
						cout << "Вы успешно авторизировались!" << endl;
						name1 = buf[i + 1];
						name2 = buf[i + 2];
						name3 = buf[i + 3];
						User user(atoi(buf[i].c_str()), name1, name2, name3, atoi(buf[i + 4].c_str()));
						return user;
					}
					else
					{
						cout << "Введен неверный пароль!" << endl;
						cout << "для входа под аккаунтом гостя - 1" << endl;
						cin >> buttom;
						if (buttom == 1) break;
					}
				}
			}
			if (buttom == 1) break;
		}
	}
	string pop = "guest";
	string p = " ";

	cout << "Вы авторизировались под учетной записью гостя.\nВы не можете заказать талон и просмотреть личную информацию." << endl;
	
	return User(0, pop, p, p,0 );
}
