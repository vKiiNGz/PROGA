#ifndef bintreeH
#define bintreeH
#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class tree_elem
{
 public:
     int m_data;
	 tree_elem* m_left;
	 tree_elem* m_right;

	 tree_elem()
	 {
		 m_left = nullptr;
		 m_right = nullptr;
		 m_data = NULL;
	 }

	 tree_elem(int val)
	 {
		 m_left = nullptr;
		 m_right = nullptr;
		 m_data = val;
	 }
};

class binary_tree
{
 private:
	int m_size;

 public:
	tree_elem* m_root = NULL;

	binary_tree()
	{
		m_root = new tree_elem();
		m_size = 0;
	}

	binary_tree(int key)
	{
		m_root = new tree_elem(key);
		m_size = 1;
	}

	void delete_tree(tree_elem* curr)
	{
		if (curr)
		{
			delete_tree(curr->m_left);
			delete_tree(curr->m_right);
			delete curr;
		}
	}

	~binary_tree()
	{
		delete_tree(m_root);
	}

	void print_tree(tree_elem * curr)
{
	if (curr)
    {
        print_tree(curr->m_left);
		cout << curr->m_data << " ";
        print_tree(curr->m_right);
    }
}

	void print()
	{
		print_tree(m_root);
		cout << endl;
	}
	bool find(int key)
	{
		tree_elem * curr = m_root;
		while (curr && curr->m_data != key)
		{
			if (curr->m_data > key)
				curr = curr->m_left;
			else
				curr = curr->m_right;
		}
		return curr != NULL;
	}
	void insert(int key)
	{
		tree_elem * curr = m_root;
		while (curr && curr->m_data != key)
		{
			if (curr->m_data > key && curr->m_left == NULL)
			{
				curr->m_left = new tree_elem(key);
				++m_size;
				return;
			}
			if (curr->m_data < key && curr->m_right == NULL)
			{
				curr->m_right = new tree_elem(key);
				++m_size;
				return;
			}
			if (curr->m_data > key)
				curr = curr->m_left;
			else
				curr = curr->m_right;
		}
	}
    void erase(int key)
	{
		tree_elem * curr = m_root;
		tree_elem * parent = NULL;
		while (curr && curr->m_data != key)
		{
			parent = curr;
			if (curr->m_data > key)
			{
				curr = curr->m_left;
			}
			else
			{
				curr = curr->m_right;
			}
		}
		if (!curr)
			return;
		if (curr->m_left == NULL)
		{
			if (parent && parent->m_left == curr)
				parent->m_left = curr->m_right;
			if (parent && parent->m_right == curr)
				parent->m_right = curr->m_right;
			--m_size;
			delete curr;
			return;
		}
		if (curr->m_right == NULL)
		{
			if (parent && parent->m_left == curr)
				parent->m_left = curr->m_left;
			if (parent && parent->m_right == curr)
				parent->m_right = curr->m_left;
			--m_size;
			delete curr;
			return;
		}
		tree_elem * replace = curr->m_right;
		while (replace->m_left)
			replace = replace->m_left;
		int replace_value = replace->m_data;
		erase(replace_value);
		curr->m_data = replace_value;
	}

	tree_elem* getMaxNode(tree_elem *root)
	{
		while (root->m_right)
		{
			root = root->m_right;
		}
    return root;
	}
};
#endif