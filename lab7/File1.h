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
string SearchContacnt(Person &user, string _name, string _surname);
string Schedule(Person &user, string _date);
void In(Person &user, fstream &baze);
void Out(Person &user, fstream &baze);
string* ShowAllContacts(Person &user);
string* ShowAllEvents(Person &user);
void start(Person &user , fstream &baze, string &name, string &surname);
