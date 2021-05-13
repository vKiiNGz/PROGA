#ifndef stackH
#define stackH
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
string IntToStrings(int x)
{
	int sLong;
	string s = "";
	string h = s;
	while (x > 0)
	{
		s += x % 10 + '0';
		x /= 10;
	}
	sLong = s.length();
	for (int i = 0; i < sLong; i++)
	{
		h += s[s.length() - i - 1];
	}
	return h;
}

struct Nodes {
	int number, val;
	Nodes* next;
	Nodes* prev;

	Nodes(int _number, int _val) : val(_val), number(_number), next(nullptr), prev(nullptr){}
};


struct stack {
	Nodes* first;
	Nodes* last;

	stack() : first(NULL), last(NULL) {}

	bool is_empty() {
		return first == NULL;
	}

	void push_back(int _number, int _val) {
		Nodes* p = new Nodes(_number ,_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	string print() {
		string h;
		if (is_empty()) return "";
		Nodes* p = first;
		while (p) {

			h += '(' + IntToStrings(p->number) + ", " +  IntToStrings(p->val) + ") ";
			p = p->next;
		}
		return h;
	}

    void remove_first() {
		if (is_empty()) return;
		Nodes* p = first;
		first = p->next;
        delete p;
	}

	void pop(int& _number, int& _val)
	{
		Nodes *h;
		Nodes* p = first;
		if (is_empty()) return ;
		if (first == last) {
			h = last;
			remove_first();
			_number = h->number;
			_val = h->val;
			return;
		}
		while (p->next != last) p = p->next;
		h = p->next;
		p->next = NULL;
		delete last;
		last = p;
        _number = h->number;
		_val = h->val;
		return;
	}

};
#endif