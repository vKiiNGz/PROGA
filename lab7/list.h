//---------------------------------------------------------------------------

#ifndef listH
#define listH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct NodeP {

	string name, surname, patronymic, placeOfWork, dateOfBirth;
	NodeP* next;
	NodeP* prev;
	NodeP(string _name, string _surname, string _patronymic, string _placeOfWork, string _dateOfBirth)
	: name(_name), surname(_surname), patronymic(_patronymic), placeOfWork(_placeOfWork), dateOfBirth(_dateOfBirth), next(nullptr), prev(nullptr) {}
};

struct listP {
	NodeP* first;
	NodeP* last;
	int size;

	listP() : first(nullptr), last(nullptr), size(0) {}

	bool is_empty() {
		return first == NULL;
	}

	void push_back(string _name, string _surname, string _patronymic, string _placeOfWork, string _dateOfBirth) {
		NodeP* p = new NodeP(_name, _surname, _patronymic, _placeOfWork, _dateOfBirth);
		if (is_empty()) {
			first = p;
			last = p;
			first->next = last;
			last->prev = first;
			return;
		}
		last->next = p;
		p->prev = last;
		last = p;
		size++;
	}

	NodeP* operator[] (const int index) {
		if (is_empty()) return NULL;
		NodeP* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return NULL;
		}
		return p;
	}
};

struct NodeE {

	string name, data, start, place;
	int time;
	bool period;
	NodeE* next;
	NodeE* prev;
	NodeE(string _name, string _data, string _place, string _start, int _time, bool _period)
	: name(_name), data(_data), place(_place), start(_start), time(_time), period(_period),next(nullptr), prev(nullptr) {}
};

struct listE {
	NodeE* first;
	NodeE* last;
	int size;

	listE() : first(nullptr), last(nullptr), size(0) {}

	bool is_empty() {
		return first == NULL;
	}

	void push_back(string _name, string _data, string _place, string _start, int _time, bool _period) {
		NodeE* p = new NodeE(_name, _data, _place, _start, _time, _period);
		if (is_empty()) {
			first = p;
			last = p;
			first->next = last;
			last->prev = first;
			return;
		}
		last->next = p;
		p->prev = last;
		last = p;
		size++;
	}

	NodeE* operator[] (const int index) {
		if (is_empty()) return NULL;
		NodeE* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return NULL;
		}
		return p;
	}
};

#endif
