#pragma once
#include "Exceptions.h"
#include <string>
#include <fstream>
#include <iostream>
#include "windows.h"
#include "UserinProg.h"
#include "UUIDUtils.h"
#include "FunctionForString.h"

using namespace std;
class User
{
public:
	User(int n, string first, string second, string therd, int password)
	{
		number_cart = n;
		this->Firstname = first;
		this->Secondname = second;
		this->Therdname = therd;
		this->password = password;

	}
	User(string fio, int password)
	{

		if (fio == "Admin" && 12345 == password)
		{
			this->Firstname = fio;
			this->Secondname = ' ';
			this->Therdname = ' ';
			this->password = password;
			isAdmin = true;
		}
	}
	User() {};
	int number_cart;
	string Firstname;
	string Secondname;
	string Therdname;
	int password;
	bool isAdmin = false;

	friend inline ofstream& operator << (ofstream &, User &);
	friend ostream& operator << (ostream &, User &);
};

inline ofstream & operator<<(ofstream & out, User & obj)
{
	string i1 = to_string(obj.number_cart);
	string i2 = to_string(obj.password);
	out << i1.c_str() << endl;
	out << obj.Firstname.c_str() << endl;
	out << obj.Secondname.c_str() << endl;
	out << obj.Therdname.c_str() << endl;
	out << i2.c_str() << endl;
	return out;
}

ostream & operator << (ostream & out, User & obj)
{
	out << "Номер карты: " << obj.number_cart << endl;
	out << "Фамилия: "<< obj.Firstname << endl;
	out << "Имя: "<< obj.Secondname << endl;
	out << "Отчество: "<< obj.Therdname << endl;
	return out;
}
class Usluga
{
public:
	//const string id = UUIDUtils::generateUUID();
	int time_in;
	int time_out;
	int time_between;
	int room;

	Usluga() {};

	virtual ~Usluga() {}
};

class Doctor : public Usluga 
{
public:
	string specialization;
	string Firstname;
	string Secondname;
	string Therdname;
	Doctor(string a, string b)
	{
		specialization = a;
		Firstname = b;
	}
	Doctor(string sp, string f, string s, string t) 
	{
		specialization = sp;
		Firstname = f;
		Secondname = s;
		Therdname = t;
	}
	Doctor(string a, string b, int start, int end, int bitween, int r)
	{
		specialization = a;
		Firstname = b;
		time_in = start;
		time_out = end;
		time_between = bitween;
		room = r;
	}
	Doctor() {}
	
};

class Analiz : public Usluga
{
public:
	string department;
	string specialty;
	Analiz(string a, string b)
	{
		department = a;
		specialty = b;
	};
	Analiz(string a, string b, int start, int end, int bitween, int r)
	{
		department = a;
		specialty = b;
		time_in = start;
		time_out = end;
		time_between = bitween;
		room = r;
	}
};

class Talon
{
public:

	string department;
	string specify;
	string doctor;
	tm data_time;
	int room;
	int number_card;
};
void out_time(tm time)
{
	cout << "Время: " <<"Часы - "  << time.tm_hour << ':' << "Минуты - "<<time.tm_min << endl;
	cout << "Дата: " << time.tm_mday << '.' << time.tm_mon << '.' << time.tm_year << endl;
}