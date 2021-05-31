#include "File1.h"
#include <assert.h>

/*string DateIn(bool ff);
string TimeIn();
void AddContact(Person &user);
void AddEvent(Person &user);*/
void SearchContacntTest()
{
    fstream baze;
	baze.open("Data.txt");
	Person user;
	In(user, baze);
    string answ, _name = "Ilya", _surname = "Lazyk";  
    answ = SearchContacnt(user, _name, _surname);
    assert(answ == "Ilya Lazyk Sergeevich BSUIR 03.07.2002 ");
    cout << "SearchContacnt test completed" << endl; 
}
void ScheduleTest()
{
    string _name = "Sementsov_Birthday", _data = "23.05.2002", _start = "18:00", _place = "Prime_Hall";
	int _time = 240;
	bool _period = true;
    user.Events.push_back(_name, _data, _place, _start, _time, _period);
    string answ;
    answ = Schedule(user, "23.05.2002");
    assert(answ == "Sementsov_Birthday 23.05.2002 Prime_Hall 18:00 240 period");
    cout << "Schedule test completed" << endl;
    
}
void InTest()
{
    fstream baze;
	baze.open("Data.txt");
	Person user;
	In(user, baze);
    cout << "In test completed" << endl;
}
void OutTest()
{
    fstream baze;
	baze.open("Data.txt");
	Person user;
	In(user, baze);
    Out(user, baze);
    cout << "Out test completed" << endl;
}
void ShowAllEventsTest()
{
    Person user;
    string* answ = new string[1];
    string _name = "Sementsov_Birthday", _data = "23.05.2002", _start = "18:00", _place = "Prime_Hall";
	int _time = 240;
	bool _period = true;
    user.Events.push_back(_name, _data, _place, _start, _time, _period);
    answ = ShowAllEvents(user);	
    assert(answ[0] == "Sementsov_Birthday 23.05.2002 Prime_Hall 18:00 240 period");
    cout << "ShowAllEvents test completed" << endl;
}
#undef main

int main()
{
    ShowAllEventsTest();  
    //SearchContacntTest();
    ScheduleTest();
    InTest();
    //OutTest();  
}
