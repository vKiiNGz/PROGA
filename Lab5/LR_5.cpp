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
#include <string>
#include "Unit1.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	char *number = new char [80];
	List numb;
	gets(number);
	bool* factor = new bool[100000];
	numb = AddToListString(number);
	factor = ReshetoErat();
	Task(numb, factor);
	return 0;
}
