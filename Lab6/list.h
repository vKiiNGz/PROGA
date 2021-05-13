#ifndef listH
#define listH
#include <string>
using namespace std;
//---------------------------------------------------------------------------
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

struct Node {
	int number, val;
	Node* next;
	Node* prev;

	Node(int _number, int _val) : val(_val), number(_number), next(nullptr), prev(nullptr){}
};

struct list {
    Node* first;
    Node* last;

	list() : first(NULL), last(NULL) {}

	bool is_empty() {
		return first == NULL;
    }

	void push_back(int _number, int _val) {
		Node* p = new Node(_number, _val);
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
		while (p) {

			h += '(' + IntToString(p->number) + ", " +  IntToString(p->val) + ") ";
			p = p->next;
		}
		return h;
	}

    Node* operator[] (const int index) {
		if (is_empty()) return NULL;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
			if (!p) return NULL;
        }
        return p;
    }
};
#endif