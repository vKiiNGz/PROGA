#include <assert.h>
#include "bintree.h"
#include "list.h"
#include "stack.h"

void push_backTest()
{
    list l;
    l.push_back(1, 1);
    assert( l.print() == "(1, 1) ");

    stack s;
    s.push_back(1, 1);
    assert( s.print() == "(1, 1) ");
    printf("\npush_back test completed");
}

void SquareBracketsTest()
{
    list l;
    l.push_back(1, 1);
    assert( l[0]->number == 1 && l[0]->val == 1);    
    printf("\nSquareBrackets test completed");
}

void TreeTest()
{
    binary_tree** myArrT = new binary_tree* [1];
    myArrT[0] = new binary_tree();
    (*myArrT[0]).insert(5);
    (*myArrT[0]).insert(4);
    (*myArrT[0]).insert(7);
    tree_elem* x;
    x = (*myArrT[0]).getMaxNode((*myArrT[0]).m_root);
    assert( x->m_data == 7);    
    printf("\nTree test completed");

}
#undef main

int main()
{
    push_backTest();
    SquareBracketsTest();
    TreeTest();
    return 0;
}