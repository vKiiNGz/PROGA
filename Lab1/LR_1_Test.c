#include "LR_1.h"
#include <stdio.h>
#include <assert.h>
void TaskTest()
{   
    int x = 9;
    assert(Task(&x) == 2);
    printf("\nTask test completed");
}

#undef main

int main()
{
    TaskTest();
    return 0;
}