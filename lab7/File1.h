#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include "list.h"
#include "person.h"
using namespace std;

void StarLine();
string DateIn(bool ff);
string TimeIn();
void AddContact(Person &user);
void AddEvent(Person &user);
string SearchContacnt(Person &user, string _name, string _surname);
string Schedule(Person &user, string _date);
void In(Person &user, fstream &baze);
void Out(Person &user, fstream &baze);
string* ShowAllContacts(Person &user);
string* ShowAllEvents(Person &user);