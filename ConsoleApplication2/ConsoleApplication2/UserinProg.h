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
			cout << "������� ����� ����� :" << endl;
			cin >> cart_num;
			if (cart_num <= 0)
				cout << "��������� ����! " << endl;
			else break;
		}

		while (1)
		{
			cout << "� ��� :" << endl;
			cin >> name1;
			cin >> name2;
			cin >> name3;
			if ((name1.c_str() == "0") || (name2.c_str() == "0") || (name3.c_str() == "0"))//�������� ����������� ���������
				cout << "�� �� ����� ������, ������� ��� ����!" << endl;
			else break;
		}

		for (int i = 0; i < size; i += 5)
		{
			if (atoi(buf[i].c_str()) == cart_num)
			{
				cout << "������ ����� ����� ��� ����������!\n ���������� ������ ��� ����������� ��� ������� � �������� ������� � ������� ����������!" << endl;
				povt = true;
				break;
			}
			if ((name1 == buf[i + 1]) && (name2 == buf[i + 2]) && (name3 == buf[i + 3]))
			{
				cout << "������ ��� ��� ����������!\n ���������� ������ ��� ����������� ��� ������� � �������� ������� � ������� �����������!" << endl;
				povt = true;
				break;
			}
		}

		if (povt == false)break;
		
	}

		cout << "������� ������: ";
		cin >> password;
		cout << "�� ������� ������������������!" << endl;
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
		cout << "������� ����� ����� (���� ��� �� �������� ����� ����� ������� 0):" << endl;
		cin >> cart_num;
		cout << "� ���(���� ��� �� �������� ���� ������ ��� ������� 0 0 0 ):" << endl;
		cin >> name1;
		cin >> name2;
		cin >> name3;
		if ((name1.c_str() == "0") && (name2.c_str() == "0") && (name3.c_str() == "0") && (cart_num == 0))
			cout << "�� �� ����� ������, ������� ���� �� ���� �� �����!" << endl;
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
				cout << "���� ������� ������ �������!" << endl;
				int password;

				while (1)
				{
					cout << "������� ������: " ;
					cin >> password;
					if (atoi(buf[i + 4].c_str()) == password)
					{
						cout << "�� ������� ����������������!" << endl;
						name1 = buf[i + 1];
						name2 = buf[i + 2];
						name3 = buf[i + 3];
						User user(atoi(buf[i].c_str()), name1, name2, name3, atoi(buf[i + 4].c_str()));
						return user;
					}
					else
					{
						cout << "������ �������� ������!" << endl;
						cout << "��� ����� ��� ��������� ����� - 1" << endl;
						cin >> buttom;
						if (buttom == 1) break;

					}
				}
			}
			if (buttom == 1) break;
		}
		cout << "������� ������ ��� ������ ������� ����� �� ����������!" << endl;
	}
	else
	{
		for (int i = 0; i < size; i+=5)
		{
			if ((name1 == buf[i + 1]) && (name2 == buf[i + 2]) && (name3 == buf[i + 3]))
			{
				cout << "���� ������� ������ �������!" << endl;
				int password;

				while (1)
				{
					cout << "������� ������: ";
					cin >> password;
					if (atoi(buf[i + 4].c_str()) == password)
					{
						cout << "�� ������� ����������������!" << endl;
						name1 = buf[i + 1];
						name2 = buf[i + 2];
						name3 = buf[i + 3];
						User user(atoi(buf[i].c_str()), name1, name2, name3, atoi(buf[i + 4].c_str()));
						return user;
					}
					else
					{
						cout << "������ �������� ������!" << endl;
						cout << "��� ����� ��� ��������� ����� - 1" << endl;
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

	cout << "�� ���������������� ��� ������� ������� �����.\n�� �� ������ �������� ����� � ����������� ������ ����������." << endl;
	
	return User(0, pop, p, p,0 );
}
