//---------------------------------------------------------------------------

#ifndef listH
#define listH
#include <iostream>
#include <stdio.h>
//---------------------------------------------------------------------------
struct Node
{
	int data;
	Node *Next, *Prev;
};
class List
{
	Node *Head, *Tail;

	public:
	List():Head(NULL),Tail(NULL){};
	~List();

	void Add(int data);
	long long Show();
	void Clear();
};
#endif
