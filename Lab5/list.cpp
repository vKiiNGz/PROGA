//---------------------------------------------------------------------------

#pragma hdrstop

#include "list.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
List::~List()
{
	while(Head)
	{
		Tail=Head->Next;
		delete Head;
		Head=Tail;
	}
}


void List::Add(int data)
{
   Node *temp = new Node;
   temp->Next = temp->Prev = NULL;
   temp->data = data;
   if (Head!=NULL)
   {
	temp->Prev = Tail;
	Tail->Next = temp;
	Tail = temp;
   }
   else
   {
	temp->Prev = NULL;
	Head=Tail=temp;
   }
}
long long List::Show()
{
	long long x = 0;
	Node *temp = Head;
	while(temp!=NULL)
	{
	x *= 10;
	x += temp->data;
	temp = temp->Next;
	}
	return(x);
}
void List::Clear()
{
    while(Head)
	{
		Tail=Head->Next;
		delete Head;
		Head=Tail;
	}
}
