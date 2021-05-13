#include <stdio.h>
#include "bintree.h"
#include "list.h"
#include "stack.h"

int main()
{
	int n, i, numb = 101, val;
	list myL;
	stack myS;
	n = rand() % 100 + 1;
	binary_tree** myArrT = new binary_tree* [n];

	for (i = 0; i < n; i++)
	{
		myArrT[i] = new binary_tree();
        numb = 101;
		while (numb >=  n)
		{
			numb = rand() % 100 + 1;
			val  = rand() % 10000 + 1;
		}
		cout << numb << " " << val << endl;
		myL.push_back(numb, val);
	}

	for (i = 0; i < n; i++)
	{
		myS.push_back(myL[i]->number, myL[i]->val);
	}
	while(!(myS.is_empty() == true) )
	{
		myS.pop(numb, val);
		(*myArrT[numb]).insert(val);
	}

	for (i = 0; i < n; i++)
	{
		tree_elem* x;
		x = (*myArrT[i]).getMaxNode((*myArrT[i]).m_root);
		cout << x->m_data << " ";
    }
	return 0;
}