//---------------------------------------------------------------------------

#ifndef queueH
#define queueH
#include <vcl.h>
//---------------------------------------------------------------------------
template <class T>
struct Node {
	T val;
	Node* next;
	Node* prev;

	Node(T _val) : val(_val), next(NULL), prev(NULL) {}
};
template <class T>
struct Queue {

	Node<T>* first;
	Node<T>* last;

	Queue() : first(NULL), last(NULL) {}

	bool is_empty() {
		return first == NULL;
	}

	void push_back(T _val) {
		Node<T>* p = new Node<T>(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		p->prev = last;
		last = p;

	}

	UnicodeString print() {
		UnicodeString h;
		if (is_empty()) return "";
		Node<T>* p = first;
		while (p)
		{
			h += p->val;
			h += ' ';
			p = p->next;
		}
        return(h);
	}


	Node<T>* find(T _val) {
		Node<T>* p = first;
		while (p && (p->val !=_val)) p = p->next;
		return (p && (p->val !=_val)) ? p : NULL;
	}

	void remove_first() {
		if (is_empty()) return;
		Node<T>* p = first;
		first = p->next;
        delete p;
	}

	void remove_last() {
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}
		Node<T>* p = first;
		while (p->next != last) p = p->next;
		p->next = NULL;
		delete last;
		last = p;
	}

	void remove(T _val) {
		if (is_empty()) return;
		if (first->val == _val) {
			remove_first();
			return;
		}
		else if (last->val == _val) {
			remove_last();
			return;
		}
		Node<T>* slow = first;
		Node<T>* fast = first->next;
		while (fast && fast->val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			ShowMessage("This element does not exist");
			return;
		}
		slow->next = fast->next;
		delete fast;
	}
	T pop()
	{
		Node<T>* temp = first;
		T h = first->val;
		T c;
		if (is_empty()) return c;
		if (first == last)
		{
			remove_first();
			return h;
		}
		first = first->next;
        delete temp;
		first->prev = NULL;
		return h;
	}
	void loop()
	{
		if (is_empty()) return ;
		first->prev = last;
		last->next = first;
	}
	T out_first() {
		T c;
		if (is_empty()) return c;
		return first->val;
	}

};

#endif
