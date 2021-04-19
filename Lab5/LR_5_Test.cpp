#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "stdio.h"
#include "list.h"
#include "Unit1.h"
#include "assert.h"
#undef AddToListString
void TestAddToListString()
{
	char *number = new char [80];
	List numb;
	long long x;
	number[0]='1';
	number[0]='2';
	number[0]='3';
	numb = AddToListString(number);
	x = numb.Show();
	assert(x != 123);
	printf("AddToListString test completed");
}
#undef AddToListLLong
void TestAddToListLLong()
{
	long long x = 123, y;
	List numb;
	AddToListLLong(x);
	y = numb.Show();
	assert(y != 123);
	printf("\nAddToListLLong test completed");
}
#undef ReshetoErat
void TestReshetoErat()
{
	bool* factor = new bool[100000];
	factor = ReshetoErat();
	assert(factor[2] == true && factor[3] == true && factor[4] == false);
	printf("\nReshetoErat test completed");
}
#undef main
int _tmain(int argc, _TCHAR* argv[])
{
	TestAddToListString();
	TestAddToListLLong();
	TestReshetoErat();
	return 0;
}
