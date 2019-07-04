#pragma once
#include "Logic.h"
#include <iostream>
#include "Conteiner.h"
using namespace std;

class ConteinerTalons
{
public:
	
	Talon * talons;
	int size;

	ConteinerTalons(int size)
	{
		this->size = size;
		talons = new Talon[size];
	}

	ConteinerTalons() {}

};

class InterfaceTalons : ConteinerTalons
{
public:
	
	void zakazTalona(int cart_num) {}
	void otkazTalona(int cart_num) {}

	
	void watchTalons(int cart_num) {}// ����������� ��� ������ ������������

	vector<Talon> find(Doctor doc) 
	{
		vector<Talon> result = vector<Talon>();
		for (int i = 0; i < size; i++)
		{
			if (talons[i].doctor == doc.Firstname)
			{
				result.push_back(talons[i]);
			}
		}
		return result;
	}//��������� �� ������� ���������� �������
	vector<Talon> find(Doctor doc, tm data_time)
	{
		vector<Talon> result = vector<Talon>();
		for (int i = 0; i < size; i++)
		{
			if (talons[i].doctor == doc.Firstname )
			{
				result.push_back(talons[i]);
			}
		}
		return result;

	}
	void sorting(Analiz obj) {}//��������� �� ������� ���������� �������
	void sorting(Analiz doc, int data, int time) {}

	friend bool operator ==(ConteinerTalons & , const Talon );
	friend bool operator !=(ConteinerTalons &, const Talon);
	friend inline ifstream& operator >> (ifstream &, ConteinerTalons &);//��� ������ �� ����� � ���������
	friend inline ofstream& operator << (ofstream &, ConteinerTalons &);//��� ���������� �� ���������� � ����
	friend inline  ostream & operator << (ofstream &,const Talon &);
	friend inline  ostream& operator << (ostream &, const ConteinerTalons &);
	friend inline  istream& operator >> (istream &, ConteinerTalons &);
	friend inline ConteinerTalons operator + (ConteinerTalons obj1, ConteinerTalons obj2);
};

bool operator ==(ConteinerTalons & obj1, const Talon obj2)
{
	for (int i = 0; i < obj1.size; i++)
	{
		if ((obj1.talons[i].department == obj2.department) && (obj1.talons[i].specify == obj2.specify) && (obj1.talons[i].doctor == obj2.doctor)
			&& (obj1.talons[i].data_time.tm_min == obj2.data_time.tm_min) && (obj1.talons[i].data_time.tm_hour == obj2.data_time.tm_hour) && (obj1.talons[i].data_time.tm_mday == obj2.data_time.tm_mday) &&
			(obj1.talons[i].data_time.tm_mon == obj2.data_time.tm_mon) && (obj1.talons[i].data_time.tm_year == obj2.data_time.tm_year) && (obj1.talons[i].room == obj2.room))
		{
			if (obj1.talons[i].number_card != 0)
			{
				cout << "����� ������������ ������ �������������" << endl;
				return false;
			}
			else
			{
				obj1.talons[i].number_card = obj2.number_card;
				return true;

			}
		}
	}
						
}

bool operator !=(ConteinerTalons & obj1, const Talon obj2)
{
	for (int i = 0; i < obj1.size; i++)
	{
		if ((obj1.talons[i].department == obj2.department) && (obj1.talons[i].specify == obj2.specify) && (obj1.talons[i].doctor == obj2.doctor)
			&& (obj1.talons[i].data_time.tm_min == obj2.data_time.tm_min) && (obj1.talons[i].data_time.tm_hour == obj2.data_time.tm_hour) && (obj1.talons[i].data_time.tm_mday == obj2.data_time.tm_mday) &&
			(obj1.talons[i].data_time.tm_mon == obj2.data_time.tm_mon) && (obj1.talons[i].data_time.tm_year == obj2.data_time.tm_year) && (obj1.talons[i].room == obj2.room))
		{
			if (obj1.talons[i].number_card == obj2.number_card)
			{
				obj1.talons[i].number_card = 0;
				cout << "������ ����� �������� ��� ������������!" << endl;
				return true;
			}
			else
			{
				cout << "������ ����� ���� �� ������������." << endl;
				return false;

			}
		}
	}

}

inline ifstream & operator >> (ifstream & out, ConteinerTalons & obj)
{
	const char * file_name = "Talons.txt";
	ifstream in(file_name);
	
	int sizeBuf = HowMuchString(file_name);//�� ������ ������� �������
	cout << sizeBuf;
	string * buf = new string[sizeBuf];//������������ ������������� ������ ���� ����, ������� ������ ���� ����
	int i = 0;
	while (getline(in, buf[i]))
	{
		i++;
	}
	int sizeTalons = sizeBuf / 10;
	ConteinerTalons obj2(sizeTalons);
	for (int j = 0, i = 0; j < sizeTalons; j++, i += 10)// �������� : �� ������� ���-�� ��������, ����� ��������� ������� ����
	{
		Talon talon;
		talon.department = buf[i];
		talon.specify = buf[i + 1];
		talon.doctor = buf[i + 2];
		talon.data_time.tm_min = atoi(buf[i + 3].c_str());
		talon.data_time.tm_hour = atoi(buf[i + 4].c_str());
		talon.data_time.tm_mday = atoi(buf[i + 5].c_str());
		talon.data_time.tm_mon = atoi(buf[i + 6].c_str());
		talon.data_time.tm_year = atoi(buf[i + 7].c_str());
		talon.room = atoi(buf[i + 8].c_str());
		talon.number_card = atoi(buf[i + 9].c_str());
		obj2.talons[j] = talon;
	}
	obj = obj2;
	return out;
}

inline ofstream& operator << (ofstream & inst, ConteinerTalons & obj)//��� ���������� �� ���������� � ����
{
	const char *file_name = "Talons.txt";
	ofstream ins(file_name);
	for (int i = 0; i < obj.size; i++)
	{
		ins << obj.talons[i].department << '\n' << obj.talons[i].specify << '\n'
			<< obj.talons[i].doctor << '\n' << obj.talons[i].data_time.tm_hour
			<< '\n' << obj.talons[i].data_time.tm_min << '\n' << obj.talons[i].data_time.tm_mday
			<< '\n' << obj.talons[i].data_time.tm_mon << '\n' << obj.talons[i].data_time.tm_year
			<< '\n' << obj.talons[i].room << '\n' << obj.talons[i].number_card << endl;
	}
	return ins;
}

inline ostream & operator << (ostream & out, const ConteinerTalons & obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		out << "�����������: ";
		out << obj.talons[i].department << endl;
		if (!(strlen(obj.talons[i].specify.c_str()) < 3))
		{
			out << "������������: ";
			out << obj.talons[i].specify << endl;
		}
		if (!(strlen(obj.talons[i].doctor.c_str()) < 3))
		{
			out << "������:";
			out << obj.talons[i].doctor << endl;
		}

		out_time(obj.talons[i].data_time);
		out << "�������: ";
		out << obj.talons[i].room << endl;
		out << "����� ������: ";
		out << obj.talons[i].number_card;
		out << '\n';
		cout << endl;
	}
	return out;
}
inline ostream & operator << (ostream & out, const Talon & obj)
{
		out << "�����������: ";
		out << obj.department << endl;
		if (!(strlen(obj.specify.c_str()) < 3))
		{
			out << "������������: ";
			out << obj.specify << endl;
		}
		if (!(strlen(obj.doctor.c_str()) < 3))
		{
			out << "������:";
			out << obj.doctor << endl;
		}

		out_time(obj.data_time);
		out << "�������: ";
		out << obj.room << endl;
		out << "����� ������: ";
		out << obj.number_card;
		out << '\n';
	
	return out;
}

inline istream& operator >> (istream & in_pop, ConteinerTalons & obj)
{
	cout << "������� ���������� ����������� �������: ";
	int size;
	cin >> size;
	ConteinerTalons input(size);
	for (int i = 0; i < input.size; i++)
	{
		cout << "����� �" << i + 1 << endl;
		cout << "������� ������ ����������� ������: ";
		cin >> input.talons[i].department;
		cout << "\n������� ������������ ����������� ������: ";
		cin >> input.talons[i].specify;
		cout << "\n������� ������� �������:";
		cin >> input.talons[i].doctor;
		cout << "\n������� ����(1- 24) � ������ ������(1 - 60): ";
		cin >> input.talons[i].data_time.tm_hour;
		cin >> input.talons[i].data_time.tm_min;
		cout << "\n������� ����(1 - 31), �����(1 - 12) � ��� ������(2019 - 2020): ";
		cin >> input.talons[i].data_time.tm_mday;
		cin >> input.talons[i].data_time.tm_mon;
		cin >> input.talons[i].data_time.tm_year;
		cout << "\n������� �������: ";
		cin >> input.talons[i].room;
		cout << "\n������� ����� �����: ";
		cin >> input.talons[i].number_card;
		cout << endl;

	}
	ofstream in("Talons.txt");
	in << input;
	in.close();
	return in_pop;
}

void zakazTalona(int cart_num) {
	const char * file_name = "Talons.txt";
	ConteinerTalons tal;
	ifstream out(file_name);
	out >> tal;
	Talon talon;
	cout << "������� ������ ������ ������, ������� �� ������ �������������" << endl;
	cout << "������� ������ ����������� ������: ";
	cin >> talon.department;
	cout << "\n������� ������������ ����������� ������: ";
	cin >> talon.specify;
	cout << "\n������� ������� �������:";
	cin >> talon.doctor;
	cout << "\n������� ����(1- 24) � ������ ������(1 - 60): ";
	cin >> talon.data_time.tm_hour;
	cin >> talon.data_time.tm_min;
	cout << "\n������� ����(1 - 31), �����(1 - 12) � ��� ������(2019 - 2019): ";
	cin >> talon.data_time.tm_mday;
	cin >> talon.data_time.tm_mon;
	cin >> talon.data_time.tm_year;
	cout << "\n������� �������: ";
	cin >> talon.room;
	cout << "\n������� ����� �����: ";
	cin >> talon.number_card;
	cout << endl;
	bool buttom = tal == talon;
	if (buttom)
	{
		cout << "����� ������������!" << endl;
	}
}
void otkazTalona(int cart_num)
{
	const char * file_name = "Talons.txt";
	ConteinerTalons tal;
	ifstream out(file_name);
	out >> tal;
	Talon talon;
	cout << "������� ������ ������ ������, �� �������� �� ������ ����������: " << endl;
	cout << "������� ������ ����������� ������: ";
	cin >> talon.department;
	cout << "\n������� ������������ ����������� ������: ";
	cin >> talon.specify;
	cout << "\n������� ������� �������:";
	cin >> talon.doctor;
	cout << "\n������� ����(1- 24) � ������ ������(1 - 60): ";
	cin >> talon.data_time.tm_hour;
	cin >> talon.data_time.tm_min;
	cout << "\n������� ����(1 - 31), �����(1 - 12) � ��� ������(2019 - 2020): ";
	cin >> talon.data_time.tm_mday;
	cin >> talon.data_time.tm_mon;
	cin >> talon.data_time.tm_year;
	cout << "\n������� �������: ";
	cin >> talon.room;
	cout << "\n������� ����� �����: ";
	cin >> talon.number_card;
	cout << endl;
	
	bool buttom = tal != talon;
	if (buttom)
		cout << "�� ������� ���������� �� ������" << endl;
	
}


void watchTalons(int cart_num)
{
	if (cart_num == -858993460) { cout << "����� ����������� ������� ��������������� ������� ���������� ����� � ������� ������ ������������.\n ��������������� ��� �����������������!" << endl; return; }
	const char * file_name = "Talons.txt";
	ConteinerTalons tal;
	int j = 0;
	ifstream out(file_name);
	out >> tal;
	out.clear();
	cout << "������ ����� ��������������� �������." << endl;
	for (int i = 0; i < tal.size; i++)
	{
		if (tal.talons[i].number_card == cart_num)
		{
			cout << tal.talons[i] << endl;
			j++;
		}
	}
	if (j == 0)
	{
		cout << "���, ��� ������ ������� ���� ����. ����������� ������� ������� � ������������ ���� �����!" << endl;
	}
}

inline ConteinerTalons operator + (ConteinerTalons obj1, ConteinerTalons obj2)
{
	int size = obj1.size + obj2.size;
	ConteinerTalons obj3(size);
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i < obj1.size)
		{
			obj3.talons[i] = obj1.talons[i];
		}
		else
		{
			obj3.talons[i] = obj2.talons[j];
			j++;
		}
	}
	return obj3;
}
