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
		list[0].specialization = "Проктолог";
		list[0].Firstname = "Попкин";
		list[1].specialization = "ЛОР";
		list[1].Firstname = "Носов";
		list[2].specialization = "Венеролог";
		list[2].Firstname = "Купидман";
		list[3].specialization = "Венеролог";
		list[3].Firstname = "Пипиркин";
		list[4].specialization = "Терапевт";
		list[4].Firstname = "Пипиркин";

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

