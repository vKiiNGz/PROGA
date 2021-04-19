//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include <iostream>
#include "list.h"
#include "conio.h"
#include <string>
using namespace std;
//---------------------------------------------------------------------------
List AddToListString(char number[])
{
	List numb;
	for (int i = 0; i < strlen(number); i++)
	{
		switch (number[i])
		{
			case '0': numb.Add(0); break;
			case '1': numb.Add(1); break;
			case '2': numb.Add(2); break;
			case '3': numb.Add(3); break;
			case '4': numb.Add(4); break;
			case '5': numb.Add(5); break;
			case '6': numb.Add(6); break;
			case '7': numb.Add(7); break;
			case '8': numb.Add(8); break;
			case '9': numb.Add(9); break;
			default:
			cout << "Incorect input"; break;
		}
	}
	return numb;
}
List AddToListLLong(long long x)
{
	List numb;
	char *number = new char [80];
	char *helper = new char [80];
	while(x > 0)
	{
		switch (x % 10)
		{
			case 0: number[strlen(number)] ='0'; break;
			case 1: number[strlen(number)] ='1'; break;
			case 2: number[strlen(number)] ='2'; break;
			case 3: number[strlen(number)] ='3'; break;
			case 4:	number[strlen(number)] ='4'; break;
			case 5: number[strlen(number)] ='5'; break;
			case 6: number[strlen(number)] ='6'; break;
			case 7: number[strlen(number)] ='7'; break;
			case 8: number[strlen(number)] ='8'; break;
			case 9: number[strlen(number)] ='9'; break;
			default:
			cout << "Incorect input"; break;
		}
		x /= 10;
	}
	for (int i = 0; i < strlen(number); i++)
	{
		helper[i] = number[strlen(number) - i - 1];
	}
	numb = AddToListString(helper);
	return numb;
}
bool* ReshetoErat()
{
	bool* factor = new bool[100000];
	int i, n;
	for (i = 0; i < 100000; i++)
	{
		factor[i] = true;
	}
	for (i = 2; i < 100000; i++)
	{

		if (factor[i])
		{
			n = i;
			n += i;
			while (n < 100000)
			{
				factor[n] = false;
				n += i;
			}
		}
	}
	return(factor);
}
void Task(List numb, bool* factor)
{
	int i, n, last;
	long long help;
	last = 2;
	do
	{
		help = numb.Show();
		numb.Clear();
		bool answ = false;
		i = last;
		do
		{
			if (factor[i] && help % i == 0)
			{
				if (help / i != 1)
				{
					cout << i <<'*';
					help /= i;
					answ = true;
					last = i;
				}
				else
				{
					cout << i;
					help /= i;
					answ = true;
					last = i;
				}
			}
			if(answ)
			{
				numb = AddToListLLong(help);
			}
			else
			{
				i++;
			}
		}
		while(answ == false);

	}
	while(help > 1);
}
#endif
