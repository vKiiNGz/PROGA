//---------------------------------------------------------------------------

#ifndef personH
#define personH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <iostream>
#include "list.h"
class Person
{
	string name, surname, patronymic, placeOfWork, dateOfBirth;

	public:

    listP Contacts;
	listE Events;

	string GetName()
	{
		return this->name;
	}

	void SetName(string x)
	{
		this->name = x;
	}

	string GetSurname()
	{
		return this->surname;
	}

	void SetSurname(string x)
	{
		this->surname = x;
	}

	string GetPatronymic()
	{
		return this->patronymic;
	}

	void SetPatronymic(string x)
	{
		this->patronymic = x;
	}

	string GetPlaceOfWork()
	{
		return this->placeOfWork;
	}

	void SetPlaceOfWork(string x)
	{
		this->placeOfWork = x;
	}

	string GetDateOfBirth()
	{
		return this->dateOfBirth;
	}

	void SetDateOfBirth(string x)
	{
		this->dateOfBirth = x;
	}
};
#endif
