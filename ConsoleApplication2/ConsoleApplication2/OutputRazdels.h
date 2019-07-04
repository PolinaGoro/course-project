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

using namespace std;



void OutputRazdels(map <string, string *> razdels)//ВЫВОД ВСЕХ КЛЮЧЕЙ
{
	map<string, string *> ::key_compare my_comp = razdels.key_comp();

	string highest = razdels.rbegin()->first;
	map <string, string *> ::iterator it = razdels.begin();
	do {
		cout << it->first << endl;
	} while (my_comp((*it++).first, highest));
}

void OutputSpecific(map <string, string *> razdels, string key_name)//ВЫВОД СОДЕРЖИМОГО КЛЮЧА
{
	map<string, string *> ::key_compare my_comp = razdels.key_comp();

	string highest = razdels.rbegin()->first;
	map <string, string *> ::iterator it = razdels.begin();
	do {

		if (it->first == key_name)
		{
			cout << it->first << endl;
			string * a = it->second;
			for (int i = 0; i < a->size(); i++)
			{
				cout << a[i] << endl;
			}
		}

	} while (my_comp((*it++).first, highest));
	cout << endl;
}

void readDepartment_a(Analiz * analizs, int size_a, bool point)
{
	string * keys = new string[50];
	int size_all = size_a;
	string spec[50][100];
	map <string, string *> razdels;
	int size_j = 0;
	bool pervii = true;

	for (int i = 0, j = 0, k = 0, blab = 0; k < size_a; k++)
	{
		if (keys[i] != analizs[k].department)
		{
			if (k == 0)
			{
				keys[i] = analizs[k].department;
			}
			else {
				i++;
				keys[i] = analizs[k].department;
			}
		}
		if (spec[i][j] != analizs[k].specialty)
		{
			if (blab != i) { j = 0; pervii = true; blab = i; }
			if ((pervii == true) && (j == 0))
			{
				spec[i][j] = analizs[k].specialty;
				pervii = false;
			}
			else
			{
				j++;
				size_j++;
				spec[i][j] = analizs[k].specialty;
			}
			razdels[keys[i]] = spec[i];
		}
	}
	size_j++;
	if (point == false)
	{
		OutputRazdels(razdels);
		cout << endl;
	}
	else if (point == true) {
		cout << "Введите спецификацию: ";
		string word_spec_1;
		cin >> word_spec_1;
		cout << endl;
		OutputSpecific(razdels, word_spec_1);
	}
	
}

//map <string, string *> readDepartment_d(Doctor * docs, int size_d)
void readDepartment_d(Doctor * docs, int size_d, bool point)
{
	string * keys = new string[50];
	string spec[50][100];
	map <string, string *> razdels;
	int size_j = 0;
	bool pervii = true;

	for (int i = 0, j = 0, k = 0, blab = 0; k < size_d; k++)
	{
		if (keys[i] != docs[k].specialization)
		{
			if (k == 0)
			{
				keys[i] = docs[k].specialization;
			}
			else {
				i++;
				keys[i] = docs[k].specialization;
			}
		}
		if (spec[i][j] != docs[k].Firstname)
		{
			if (blab != i) { j = 0; pervii = true; blab = i; }
			if ((pervii == true) && (j == 0))
			{
				spec[i][j] = docs[k].Firstname;
				pervii = false;
			}
			else
			{
				j++;
				size_j++;
				spec[i][j] = docs[k].Firstname;
			}
			razdels[keys[i]] = spec[i];
		}
	}
	size_j++;
	if (point == false)
	{
		OutputRazdels(razdels);
		cout << endl;
	}
	else if (point == true) {
		cout << "Введите спецификацию: ";
		string word_spec_1;
		cin >> word_spec_1;
		cout << endl;
		OutputSpecific(razdels, word_spec_1);
	}
}


void Contacts()
{
	cout << "Адрес Медицинского центра: Проспект Независимости д.2" <<
		" Лаборатория: ул.Ежевского д.24 \nНомер стола справок: (017) 245-87-46 (МТС) +375295743594 "
		<< endl << "Номер регистратуры: (017) 445-87-36 (Velcom) +375445653594" << endl;
}


/*
void readDepartment(Analiz * analizs, int size_a)
{
	string * keys = new string[50];
	string spec[50][100];
	map <string, string *> razdels;
	int size_j = 0;
	bool pervii = true;

	for (int i = 0, j = 0, k = 0, blab = 0; k < size_a; k++)
	{
		if (keys[i] != analizs[k].department)
		{
			if (k == 0)
			{
				keys[i] = analizs[k].department;
			}
			else {
				i++;
				keys[i] = analizs[k].department;
			}
		}
			 if (spec[i][j] != analizs[k].specialty)
			 {
				 if (blab != i) { j = 0; pervii = true; blab = i; }
				 if ((pervii == true)&&(j == 0))
				 {
					 spec[i][j] = analizs[k].specialty;
					 pervii = false;
				 }
				 else
				 {
					 j++;
					 size_j++;
					 spec[i][j] = analizs[k].specialty;
				 }
				 razdels[keys[i]] = spec[i];
			 }
	}
	size_j++;
	OutputRazdels(razdels);
/*	map<string, string *> ::key_compare my_comp = razdels.key_comp();

	string highest = razdels.rbegin()->first;
	map <string, string *> ::iterator it = razdels.begin();
	do {
		cout << it->first << " : ";
		string * a = it->second;
		for (int i = 0; i < size_j; i++)
		{
			cout << a[i] << " , ";
		}
		cout << endl;
	} while (my_comp((*it++).first, highest));
	cout << endl;
}
*/
/*map<string, string *> ::key_compare my_comp = razdels.key_comp();

	string highest = razdels.rbegin()->first;
	map <string, string *> ::iterator it = razdels.begin();
	do {
		cout << it->first << " : ";
		string * a = it->second;
		for (int i = 0; i < size_j; i++)
		{
			cout << a[i] << " , ";
		}
		cout << endl;
	} while (my_comp((*it++).first, highest));
	cout << endl;*/