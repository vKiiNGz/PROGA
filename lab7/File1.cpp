#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "File1.h"

void StarLine()
{
	for(int i = 0; i < 119; i++)
	{
		cout << '*';
	}
	cout << endl;
}

string DateIn(bool ff)
{
	string _dateofbirth;
	char buff[256];
	bool f = true;
	while (f)
	{
		while (f)
		{
			if(ff)
			{
				cout << "Enter date of birth: " << endl;
			}
			else
			{
				cout << "Enter date of event: " << endl;
            }
			int poin = 0, day = 0, mon = 0, year = 0;
			cin.getline(buff, sizeof(buff));
			_dateofbirth = buff;
			for(int i = 0; i < _dateofbirth.length(); i++)
			{
				if (!((_dateofbirth[i] >= '0' && _dateofbirth[i] <= '9') || _dateofbirth[i] == '.' ))
				{
					cout << "Incorect data. Try again" << endl;
					break;
				}
				if (poin == 0 && !(_dateofbirth[i] == '.'))
				{
					if (_dateofbirth[i] >= '0' && _dateofbirth[i] <= '9')
					{
						day = day * 10 + (_dateofbirth[i] - '0');
					}
					else
					{
						cout << "Incorect data. Try again" << endl;
						break;
					}
				}
				if (poin == 1 && !(_dateofbirth[i] == '.'))
				{
					if (_dateofbirth[i] >= '0' && _dateofbirth[i] <= '9')
					{
						mon = mon * 10 + (_dateofbirth[i] - '0');
					}
					else
					{
						cout << "Incorect data. Try again" << endl;
						break;
					}
				}
				if (poin == 2 && !(_dateofbirth[i] == '.'))
				{
					if (_dateofbirth[i] >= '0' && _dateofbirth[i] <= '9')
					{
						year = year * 10 + (_dateofbirth[i] - '0');
					}
					else
					{
						cout << "Incorect data. Try again" << endl;
						break;
					}
				}
				if (_dateofbirth[i] == '.')
				{
					poin++;
				}
			}

			if (poin == 2 && (day > 0 && day < 31) && (mon > 0 && mon < 13) && (year > 0 && year <= 2021))
			{
				f = false;
			}
			else
			{
				cout << "Incorect data. Try again" << endl;
				break;
			}
		}

	}
	return _dateofbirth;
}

string TimeIn()
{
	string time;
	char buff[256];
	bool f = true;
	while (f)
	{
		while (f)
		{
			cout << "Enter time of start: " << endl;
			int poin = 0, hour = 0, min = 0;
			cin.getline(buff, sizeof(buff));
			time = buff;
			for(int i = 0; i < time.length(); i++)
			{
				if (!((time[i] >= '0' && time[i] <= '9') || time[i] == ':' ))
				{
					cout << "Incorect time. Try again" << endl;
					break;
				}
				if (poin == 0 && !(time[i] == ':'))
				{
					if (time[i] >= '0' && time[i] <= '9')
					{
						hour = hour * 10 + (time[i] - '0');
					}
					else
					{
						cout << "Incorect time. Try again" << endl;
						break;
					}
				}
				if (poin == 1 && !(time[i] == ':'))
				{
					if (time[i] >= '0' && time[i] <= '9')
					{
						min = min * 10 + (time[i] - '0');
					}
					else
					{
						cout << "Incorect time. Try again" << endl;
						break;
					}
				}
				if (time[i] == ':')
				{
					poin++;
				}
			}

			if (poin == 1 && (hour >= 0 && hour < 24) && (min >= 0 && min < 60))
			{
				f = false;
			}
			else
			{
				cout << "Incorect time. Try again";
				break;
			}

		}
	}
	return(time);
}

void AddContact(Person &user)
{
	char buff[256];
	string _name, _surname, _patronymic, _placeofwork, _dateofbirth;
	cout << "Enter name: " << endl;
	cin.getline(buff, sizeof(buff));
	cin.getline(buff, sizeof(buff));
	_name = buff;
	cout << "Enter surname: " << endl;
	cin.getline(buff, sizeof(buff));
	_surname = buff;
	cout << "Enter patronymic: " << endl;
	cin.getline(buff, sizeof(buff));
	_patronymic = buff;
	cout << "Enter place of work: " << endl;
	cin.getline(buff, sizeof(buff));
	_placeofwork = buff;

	_dateofbirth = DateIn(true);
	user.Contacts.push_back(_name, _surname, _patronymic, _placeofwork, _dateofbirth);
	StarLine();
}

void AddEvent(Person &user)
{
	char buff[256];
	string _name, _data, _start, _place;
	int _time;
	bool _period;
	cin.getline(buff, sizeof(buff));
	cout << "Enter name of event: " << endl;
	cin.getline(buff, sizeof(buff));
	_name = buff;
	_data = DateIn(false);
	cout << "Enter place: " << endl;
	cin.getline(buff, sizeof(buff));
	_place = buff;
	_start = TimeIn();
	bool f = true;
	while(f)
	{
		string h;
		cout << "Is it periodic? 1/0" << endl;
		cin.getline(buff, sizeof(buff));
		h = buff;
		if (h == "1")
		{
			_period = true;
			f = false;
		}
		else
		{
			if (h == "0")
			{
				_period = false;
				f = false;
			}
			else
			{
				cout << "Incorect input. Try again" << endl;
			}
		}
	}

	f = true;
	while (f)
	{
		while (f)
		{
			cout << "Enter timy taken by the event: " << endl;
			string h;
			cin.getline(buff, sizeof(buff));
			h = buff;
			int time = 0;
			for(int i = 0; i < h.length(); i++)
			{
				if (!(h[i] >= '0' && h[i] <= '9'))
				{
					cout << "Incorect time. Try again";
					break;
				}
				else
				{
					time = time * 10 + (h[i] - '0');
				}
			}
			if (time >= 0 && time < 1440)
			{
				f = false;
				_time = time;
			}
			else
			{
				cout << "Incorect time. Try again";
				break;
			}

		}
	}
	user.Events.push_back(_name, _data, _place, _start, _time, _period);
	StarLine();
}

string SearchContacnt(Person &user, string _name, string _surname)
{
	char buff[256];
	bool f = true;
	string viv;

	for (int i = 0; i <= user.Contacts.size; i++)
	{
		if(user.Contacts[i]->name == _name && user.Contacts[i]->surname == _surname)
		{
			viv = "";
			viv += user.Contacts[i]->name + " ";
			viv += user.Contacts[i]->surname + " ";
			viv += user.Contacts[i]->patronymic + " ";
			viv += user.Contacts[i]->placeOfWork + " ";
			viv += user.Contacts[i]->dateOfBirth + " ";
			return viv;
			f = false;
		}
	}
	if(f)
	{
		return "This contact does not exist. ";
	}
}

string Schedule(Person &user, string _date)
{
	string viv;
	for (int i = 0; i <= user.Events.size ; i++)
	{
		if (_date == user.Events[i]->data)
		{
			viv = "";
			viv += user.Events[i]->name + " ";
			viv += user.Events[i]->data + " ";
			viv += user.Events[i]->place + " ";
			viv += user.Events[i]->start + " ";
			viv += to_string(user.Events[i]->time) + " ";
			if (user.Events[i]->period)
			{
				viv += "period";
			}
			else
			{
				viv += "nonperiod";
			}
			return viv;
		}
	}
}

void In(Person &user, fstream &baze)
{
    char buff[256];
	string str;
    int help = 0;
	while (!baze.eof())
	{
		baze.getline(buff, sizeof(buff));
		str = buff;
		str += ' ';
		if (str == "Contacts: ")
		{
			help = 1;
		}
		if (str == "Events: ")
		{
			help = 2;
		}
		if (help == 0)
		{
			int spc = 0;
			string h;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					switch(spc)
					{
					case 0: user.SetName(h); h = ""; break;
					case 1: user.SetSurname(h); h = ""; break;
					case 2: user.SetPatronymic(h); h = ""; break;
					case 3: user.SetPlaceOfWork(h); h = ""; break;
					case 4: user.SetDateOfBirth(h); h = ""; break;
					default: break;
					}
					spc++;
				}
				else
				{
					h += str[i];
				}
			}
		}
		if (help == 1 && str != "Contacts: " && str != "Events: ")
		{
			int spc = 0;
			string h;
			string name, surname, patronymic, placeOfWork, dateOfBirth;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					switch(spc)
					{
					case 0: name = h; h = ""; break;
					case 1: surname = h; h = ""; break;
					case 2: patronymic = h; h = ""; break;
					case 3: placeOfWork = h; h = ""; break;
					case 4: dateOfBirth = h; h = ""; break;
					default: break;
					}
					spc++;
				}
				else
				{
					h += str[i];
				}
			}
			user.Contacts.push_back(name, surname, patronymic, placeOfWork, dateOfBirth);
		}

		if (help == 2 && str != "Contacts: " && str != "Events: ")
		{
			int spc = 0;
			string h;
			string name, data, start, place, times, periods;
			int time;
			bool period;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					switch(spc)
					{
					case 0: name = h; h = ""; break;
					case 1: data = h; h = ""; break;
					case 2: start = h; h = ""; break;
					case 3: place = h; h = ""; break;
					case 4: times = h; h = ""; break;
					case 5: periods = h; h = ""; break;
					default: break;
					}
					spc++;
				}
				else
				{
					h += str[i];
				}
			}
			if (periods == "period")
			{
				period = true;
			}
			else
			{
				period = false;
			}
			time = stoi(times);
			user.Events.push_back(name, data, start, place, time, period);
		}
	}
}

void Out(Person &user, fstream &baze)
{
    baze.close();
	baze.open("D:\\programm\\053502\\sem_2\\C\\LR_7b\\Data.txt", std::fstream::out | std::fstream::trunc);

	baze.clear();
	string viv = "";
	viv += user.GetName() + " ";
	viv += user.GetSurname() + " ";
	viv += user.GetPatronymic() + " ";
	viv += user.GetPlaceOfWork() + " ";
	viv += user.GetDateOfBirth();
	baze << viv << endl;
	baze << "Contacts:" << endl;
	for (int i = 0; i <= user.Contacts.size; i++)
	{
		viv = "";
		viv += user.Contacts[i]->name + " ";
		viv += user.Contacts[i]->surname + " ";
		viv += user.Contacts[i]->patronymic + " ";
		viv += user.Contacts[i]->placeOfWork + " ";
		viv += user.Contacts[i]->dateOfBirth + " ";
		baze << viv << endl;
	}
	baze << "Events:" << endl;
	for (int i = 0; i <= user.Events.size ; i++)
	{
		viv = "";
		viv += user.Events[i]->name + " ";
		viv += user.Events[i]->data + " ";
        viv += user.Events[i]->place + " ";
		viv += user.Events[i]->start + " ";
		viv += to_string(user.Events[i]->time) + " ";
		if (user.Events[i]->period)
		{
			viv += "period";
		}
		else
		{
			viv += "nonperiod";
		}
		if (i == user.Events.size)
		{
			baze << viv;
		}
		else
		{
			baze << viv << endl;
		}
	}
}

string* ShowAllContacts(Person &user)
{
	string viv;
	string* arr = new string[user.Contacts.size];
	cout << "All your contacts: " << endl;;
	for (int j = 0; j <= user.Contacts.size; j++)
	{
		viv = "";
		viv += user.Contacts[j]->name + " ";
		viv += user.Contacts[j]->surname + " ";
		viv += user.Contacts[j]->patronymic + " ";
		viv += user.Contacts[j]->placeOfWork + " ";
		viv += user.Contacts[j]->dateOfBirth + " ";
		arr[j] = viv;
	}
	return(arr);
}

string* ShowAllEvents(Person &user)
{
	string viv;
	string* arr = new string[user.Events.size];
	cout << "All your events: " << endl;
	for (int i = 0; i <= user.Events.size ; i++)
	{
		viv = "";
		viv += user.Events[i]->name + " ";
		viv += user.Events[i]->data + " ";
		viv += user.Events[i]->place + " ";
		viv += user.Events[i]->start + " ";
		viv += to_string(user.Events[i]->time) + " ";
		if (user.Events[i]->period)
		{
		viv += "period";
		}
		else
		{
		viv += "nonperiod";
		}
		arr[i] = viv;
	}
	return(arr);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	fstream baze;
	baze.open("Data.txt");
	char buff[256];
	Person user;
	In(user, baze);
	StarLine();
	string name, surname;
	name = user.GetName();
	surname = user.GetSurname();
	cout << "Hello, dear " << name << ' ' << surname << endl;
	cout << "What you want to do?" << endl;
	while(i != 0)
	{
		cout << "Add new contact - 1" << endl;
		cout << "Add new event - 2" << endl;
		cout << "Search contact - 3" << endl;
		cout << "Show events for a specific date  - 4" << endl;
		cout << "Show all contacts - 5" << endl;
		cout << "Show all events - 6" << endl;
		cout << "Exit- 0" << endl;
		cin >> i;
		if(i >= 0 && i < 7)
		{
			StarLine();
			switch(i)
			{
				case 1: AddContact(user); break;
				case 2: AddEvent(user); break;
				case 3:
				{
					string _name, _surname;
					cin.getline(buff, sizeof(buff));
					cout << "Enter name: " << endl;
					cin.getline(buff, sizeof(buff));
					_name = buff;
					cout << "Enter surname: " << endl;
					cin.getline(buff, sizeof(buff));
					_surname = buff;
					cout << SearchContacnt(user, _name, _surname) << endl;
					StarLine();
					break;
				}
				case 4:
				{
					 string _date;
					 cin.getline(buff, sizeof(buff));
					 _date = DateIn(false);
					 cout << Schedule(user, _date) << endl;
					 StarLine();
					 break;
				}
				case 5:
				{
					string* arr = new string[user.Contacts.size];
					arr = ShowAllContacts(user);
					for (int j = 0; j < user.Contacts.size; j++)
					{
						cout << arr[j] << endl;
					}
					StarLine();
					break;
				}
				case 6:
				{
					string* arr = new string[user.Events.size];
					arr = ShowAllEvents(user);
					for (int j = 0; j < user.Events.size; j++)
					{
						cout << arr[j] << endl;
					}
					StarLine();
					break;
				}
				case 0:
				{
					Out(user, baze);
					baze.close();
					return 0;	
				}
				default: break;
			}
		}
		else
		{
			cout << "Incorect input. Try again" << endl;
			StarLine();
		}
	}
	Out(user, baze);
	baze.close();
	return 0;
}