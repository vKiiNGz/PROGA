#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "stdio.h"
#include <iostream>
#include "list.h"
#include <cstring>
#include "Unit1.h"
using namespace std;
#ifndef TESTING
int _tmain(int argc, _TCHAR* argv[])
{
	char *number = new char [80];
	List numb;
	cin.getline(number, 80);
	bool* factor = new bool[100000];
	numb = AddToListString(number);
	factor = ReshetoErat();
	Task(numb, factor);
	return 0;
}
#endif
