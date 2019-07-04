#pragma once
#include "LogicOfInerface.h"
#include <ctime>

bool CheckHoliday(tm date_time)
{
	//начинаем отчет с 1 января 2019  - вторник  
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int months = date_time.tm_mon;
	int days = 0;
	for (int i = 1; i < months; i++)
	{
		days += month[i];
	}
	days += date_time.tm_mday;
	int rezult = days % 7;
	if (rezult == 5 || rezult == 6)return true;// шо то хуйня
	//if (rezult == 4 || rezult == 5)return true;// шо это хуйня
	else return false;
}

int to_minute(tm time)
{
	int i = time.tm_hour * 60;
	int k = i + time.tm_min;
	return k;
}

int size_arr_time(int start, int min, int between)
{
	int size = (min - start) / between;
	return size;
}
int * to_arr_time(int start, int min, int between)
{
	int size = (min - start) / between;
	int * arr_time = new int[size];
	arr_time[0] = start;
	for (int j = 1; j < size; j++)
	{
		start += between;
		arr_time[j] = start;
	}
	return arr_time;
}
tm to_time(int min)
{
	int hour;
	int minute;
	if (min >= 60)
	{
		hour = min / 60;
		minute = min % 60;
	}
	tm fun_t;
	fun_t.tm_hour = hour;
	fun_t.tm_min = minute;
	return fun_t;
}

ConteinerTalons createTalonsOnDay(Analiz * objs_a, int size_uslug_1, Doctor * objs_d, int size_uslug, tm start_data)
{

		int * arr_tal_t = new int[size_uslug_1];
		for (int i = 0; i < size_uslug_1; i++)
		{
			arr_tal_t[i] = size_arr_time(objs_a[i].time_in, objs_a[i].time_out, objs_a[i].time_between);
		}

		int size_cont = 0; // содержит общее колличество талонов
		for (int i = 0; i < size_uslug_1; i++)
		{
			size_cont += arr_tal_t[i];//складываем кол-во согласно всем имеющимся 
		}
		ConteinerTalons cont1(size_cont);

		for (int i = 0, j = 0; j < size_uslug_1; j++)
		{

			int * arr_t = to_arr_time(objs_a[j].time_in, objs_a[j].time_out, objs_a[j].time_between); ///////////////////////////////??????????????????????????????????????

			for (int k = 0; k < arr_tal_t[j]; k++, i++)
			{
				int hours = arr_t[k] / 60;
				int minute = arr_t[k] % 60;

				cont1.talons[i].department = objs_a[j].department;
				cont1.talons[i].specify = objs_a[j].specialty;
				cont1.talons[i].room = objs_a[j].room;
				cont1.talons[i].data_time.tm_min = minute;
				cont1.talons[i].data_time.tm_hour = hours;
				cont1.talons[i].data_time.tm_mday = start_data.tm_mday;
				cont1.talons[i].data_time.tm_mon = start_data.tm_mon;
				cont1.talons[i].data_time.tm_year = start_data.tm_year;
				cont1.talons[i].number_card = 0;

			}

		}

		int * arr_tal_t1 = new int[size_uslug];
		for (int i = 0; i < size_uslug; i++)
		{
			arr_tal_t1[i] = size_arr_time(objs_d[i].time_in, objs_d[i].time_out, objs_d[i].time_between);
		}

		int size_cont1 = 0; // содержит общее колличество талонов
		for (int i = 0; i < size_uslug; i++)
		{
			size_cont1 += arr_tal_t1[i];//складываем кол-во согласно всем имеющимся 
		}
		ConteinerTalons cont(size_cont1);

		for (int i = 0, j = 0; j < size_uslug; j++)
		{

			int * arr_t2 = to_arr_time(objs_d[j].time_in, objs_d[j].time_out, objs_d[j].time_between);/////////////////??????????????????????????

			for (int k = 0; k < arr_tal_t1[j]; k++, i++)
			{
				int hours = arr_t2[k] / 60;
				int minute = arr_t2[k] % 60;

				cont.talons[i].department = objs_d[j].specialization;
				cont.talons[i].doctor = objs_d[j].Firstname;
				cont.talons[i].room = objs_d[j].room;
				cont.talons[i].data_time.tm_min = minute;
				cont.talons[i].data_time.tm_hour = hours;
				cont.talons[i].data_time.tm_mday = start_data.tm_mday;
				cont.talons[i].data_time.tm_mon = start_data.tm_mon;
				cont.talons[i].data_time.tm_year = start_data.tm_year;
				cont.talons[i].number_card = 0;
			}

		}
		//ЗАПИСЬ В ФАЙЛ 1 ДНЯ (НО МЫ ТИПО ХОТИМ НЕСКОЛЬКО, ПОЭТОМУ ПОКА БЛОКИРУЕМ ЭТУ ФУНКЦИЮ)
		/*ofstream pop("Talons.txt", ios::app);
		pop << cont1 + cont;
		pop.close();*/
		return cont1 + cont;
}

ConteinerTalons createTalons(Analiz * objs_a, int size_uslug_1, Doctor * objs_d, int size_uslug,tm start_data, int num_days)
{
	//Реализация создания дней длдя талонов
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	tm *array_of_days = new tm[num_days];
	int max_days = month[start_data.tm_mon];//запоминаем максимальное кол-во дней в стартовом месяце
	int really_num_of_days = 0;
	
	tm test_day;
	test_day.tm_year = start_data.tm_year;
	test_day.tm_mon = start_data.tm_mon;
	test_day.tm_mday = start_data.tm_mday;
	if (!CheckHoliday(test_day)) {
		array_of_days[0] = test_day;
		really_num_of_days++;
	}

	if (start_data.tm_wday + num_days <= max_days)
	{
		for (int i = 1; i < num_days; i++)
		{
			tm test_day;
			test_day.tm_year = start_data.tm_year;
			test_day.tm_mon = start_data.tm_mon;
			if(max_days < array_of_days[i-1].tm_mday)
			test_day.tm_mday = array_of_days[i - 1].tm_mday++;
			else
			{
				test_day.tm_mon++;
				test_day.tm_mday = 1;
			}
			if (!CheckHoliday(test_day))
			{
				array_of_days[i] = test_day;
				really_num_of_days++;
			}
		}
	}
	else
	{
		max_days = 0;
		for (int i = 1; i < start_data.tm_mon; i++) { max_days += month[i];}
		max_days += start_data.tm_mday;
		if (max_days + num_days > 365)
		{
			num_days = 365 - max_days;
			cout << "Ваши запросы превысили кол-во доступных дней. Кол-во талонов сокращено." << endl;
		}
		for (int i = 1; i < num_days; i++)
		{
			tm test_day;
			test_day.tm_year = start_data.tm_year;
			test_day.tm_mon = start_data.tm_mon;
			if (max_days < array_of_days[i - 1].tm_mday)
				test_day.tm_mday = array_of_days[i - 1].tm_mday++;
			else
			{
				test_day.tm_mon++;
				test_day.tm_mday = 1;
			}
			if (!CheckHoliday(test_day))
			{
				array_of_days[i] = test_day;
				really_num_of_days++;
			}
		}
	}
	//
	//Реализация записи в контейнер и текстовый файл 
	int size_all = 0;
	ConteinerTalons * conteiners  = new ConteinerTalons[really_num_of_days];
	for (int i = 0; i < really_num_of_days; i++)
	{
		//ConteinerTalons num_point = createTalonsOnDay(objs_a, size_uslug_1, objs_d, size_uslug, start_data);
		conteiners[i] = createTalonsOnDay(objs_a, size_uslug_1, objs_d, size_uslug, array_of_days[i]);
		size_all += conteiners[i].size;
	}
	ConteinerTalons all_Cont(size_all);
	for (int i = 0, j = 0, k = 0; i < really_num_of_days;j++)
	{
		do {
			all_Cont.talons[i] = conteiners[j].talons[k];
			i++;
			k++;
		} while (k < conteiners[j].size);
		k = 0;
	}
	//Запись в файл
	ofstream pop("Talons.txt", ios::app);
	pop << all_Cont;
	pop.close();

	return all_Cont;
}

