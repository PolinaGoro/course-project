#pragma once

#include "Logic.h"
#include <vector>
using namespace std;

class ConteinerDoc
{
public:
	Doctor * list ;
	int size = 10;

	ConteinerDoc(int size): size(size) {
		list = new Doctor[size];
	}

	ConteinerDoc() : size(5)
	{
		list = new Doctor[size];
		list[0].specialization = "���������";
		list[0].Firstname = "������";
		list[1].specialization = "���";
		list[1].Firstname = "�����";
		list[2].specialization = "���������";
		list[2].Firstname = "��������";
		list[3].specialization = "���������";
		list[3].Firstname = "��������";
		list[4].specialization = "��������";
		list[4].Firstname = "��������";

	}

	/*vector<Doctor> find(string firstName) {
		vector<Doctor> resullt = vector<Doctor>();
		for (int i = 0; i < size; i++) {
			if (firstName == list[i].Firstname) {
				return list[i];
			}
		}
		return resullt;
	}*/
};

