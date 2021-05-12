
#include "LR_5_3.h"


struct Node {
	int val;
	Node* next;

	Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
	Node* first;
	Node* last;

	list() : first(NULL), last(NULL) {}

	bool is_empty() {
		return first == NULL;
	}

	void push_back(int _val) {
		Node* p = new Node(_val);
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
		Node* p = first;
		while (p)
		{
			h += p->val + '0';
			p = p->next;
		}
		return(h);
	}

	void clear()
	{
		while(!(is_empty()))
		{
			Node* p = first;
			first = p->next;
			delete p;
		}
	}

};

void del_leading_zero(T_num_s& a)
{
while (a.size() > 1 && a[0] == '0')
	{
		a.erase(0, 1);
	}
}

bool less_for_big_int(T_num_s a, T_num_s b)
{

	int aLong;
    del_leading_zero(a);
	del_leading_zero(b);
	if (a.size() > b.size())
	{
		return false;
	}
	else
	{
		if (a.size() < b.size())
		{
			return true;
		}
		else
		{
			bool f = true;
			int i = 0;
            aLong = a.length(); 
			while(f && i < aLong)
			{
				if (a[i] - '0' > b[i] - '0')
				{
					return false;
				}
				else
				{
					if (a[i] - '0' < b[i] - '0')
					{
						return true;
					}
					else
					{
						i++;
					}
				}
			}

		}
	}
    return false;
}


void inc_big_int(T_num_s& a)
{
	for (T_num_s::size_type cur_pos = a.size() - 1; ; --cur_pos)
	{
		if (a[cur_pos] < '9')
		{
			++a[cur_pos];
			return;
		}
		else
		{
			a[cur_pos] = '0';
			if (cur_pos == 0)
			{
				a.insert(0, "1");
				return;
			}
		}
	}
}

void reduce_big_int(T_num_s& minuend, const T_num_s& subtrahend)
{
	for (T_num_s::size_type cur_pos = 0; cur_pos < subtrahend.size(); ++cur_pos)
	{
		T_num_s::size_type minuend_cur_pos = minuend.size() - 1 - cur_pos;
		T_num_s::size_type subtrahend_cur_pos = subtrahend.size() - 1 - cur_pos;

		char& cur_minuend_dig_ref = minuend[minuend_cur_pos];
		const char& cur_subtrahend_dig_ref = subtrahend[subtrahend_cur_pos];

		if (cur_minuend_dig_ref >= cur_subtrahend_dig_ref)
		{
		cur_minuend_dig_ref -= cur_subtrahend_dig_ref - '0';
		}
		else
		{
			(cur_minuend_dig_ref -= cur_subtrahend_dig_ref - '0') += 10;
			for (int i = 1; ; ++i)
			{
				if (minuend[minuend_cur_pos - i] == '0')
				{
					minuend[minuend_cur_pos - i] = '9';
				}
				else
				{
					--minuend[minuend_cur_pos - i];
					break;
				}
			}
		}
		del_leading_zero(minuend);
	}
	del_leading_zero(minuend);
}


T_num_s div_big_int(const T_num_s& a, const T_num_s& b)
{
	if (b == "0")
	{
		return "division into zero";
	}

	T_num_s res = "0";
	T_num_s minuend = a;
	T_num_s subtrahend = b;

	while (subtrahend.size() < minuend.size())
	{
		subtrahend += '0';
	}

	for (;;)
	{

		while (!less_for_big_int(minuend, subtrahend))
		{
			reduce_big_int(minuend, subtrahend);
			inc_big_int(res);
		}
		if (subtrahend.size() <= b.size())
		{
			break;
		}

		subtrahend.erase(subtrahend.size() - 1);
		res += '0';
		del_leading_zero(res);
	}
	if(minuend != "0")
	{
		return "-1";
	}
	else
	{
		return res;
	}
}

bool* ReshetoErat()
{
	bool* factor = new bool[100000];
	int i, n;
	for (i = 0; i < 100000; i++)
	{
		factor[i] = true;
	}
	for (i = 2; i < 100000; i++)
	{

		if (factor[i])
		{
			n = i;
			n += i;
			while (n < 100000)
			{
				factor[n] = false;
				n += i;
			}
		}
	}
	return(factor);
}

string IntToString(int x)
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

int main() 
{
	list l1;
	string in, help2, help1, res;
    int inLoong, resLong;
	bool* factor = new bool[100000];
	factor = ReshetoErat();
	getline(cin, in);
    inLoong = in.length();
	for (int i = 0; i < inLoong; i++)
	{
		l1.push_back(in[i] - '0');
	}
	int b = 2;
	while ( !(l1.is_empty()) &&  b < 100000)
	{
		help1 = "";
        help2 = "";
		if(factor[b])
		{
            help2 = IntToString(b);
			help1 = l1.print();
			res = div_big_int(help1, help2);
			if (res == "-1")
			{
				b++;
			}
			else
			{
                l1.clear();
                resLong = res.length();
				for (int i = 0; i < resLong; i++)
				{
					l1.push_back(res[i] - '0');
				}
				cout << b << " ";
            }
		}
		else
		{
			b++;
        }
	}
	return 0;
}