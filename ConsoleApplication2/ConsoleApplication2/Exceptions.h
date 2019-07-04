#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;


static class Zero_Negative_except : public exception
{
public:
	virtual const char * what() const throw()
	{
		return "You enter zero or negative value, rewrite!";
	}
}value_1;

static class Char_except : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "You enter too long word, rewrite!";
	}

}value_2;

static class withoutChar_except : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "You enter number!";
	}

}value_2_2;

static class All_except : public exception
{
public:
	virtual const char * what() const throw()
	{
		return "Entered uncorrect data";
	}
}value_3;


static class  Over_Hagrid_except : public exception
{
public:
	virtual const char * what() const throw()
	{
		return "Entered so long data, rewrite";
	}
}value_4;
static class Char_number_except : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "You enter number without word, rewrite!";
	}

}value_5;

static class Uncorrect_data : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "Вы ввели инвалидные данные, Повторите ввод!";
	}

}un_data;
