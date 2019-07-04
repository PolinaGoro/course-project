#pragma once
#include <fstream>
#include  <iostream>
#include "Logic.h"
#include "UserInProg.h"

using namespace std;

class ConteinerUsers
{
	User * a;
	int size;
	ConteinerUsers() {}
	ConteinerUsers(int size) : size(size)
	{
		a = new User[size];
	}
	ConteinerUsers(const  char* file_name)
	{
		ifstream pop(file_name);
		int buf_size = HowMuchString(file_name);
		string * buf = new string[buf_size];
		int i = 0;
		while (getline(pop, buf[i]))
		{
			i++;
		}

	}
};