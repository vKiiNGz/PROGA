#include "LR_4_2.h"
#include <assert.h>

void StringCreateTest()
{
    char *String;
    int SymbolCounter = 1;
    String = StringCreate(SymbolCounter);
    assert(String != NULL);
    printf("\nStringCreate test completed");
}
void StringLengthTest()
{
    char *String;
    int SymbolCounter = 3, x;
    String = StringCreate(SymbolCounter);
    String[0] = 'a';
    String[1] = 'b';
    String[2] = 'c';
    x = StringLength(String);
    assert(x == 3);
    printf("\nStringLength test completed");
}
void TaskTest()
{
    char *String;
    int SymbolCounter = 6;
    String = StringCreate(SymbolCounter);
    String[0] = '(';
    String[1] = '(';
    String[2] = '(';
    String[3] = ')';
    String[4] = ')';
    String[5] = ')';
    String = Task(String, SymbolCounter);
    assert(String[0] == '(' && String[1] == '[' && String[2] == '{' && String[3] == '}' && String[4] == ']' && String[5] == ')');
    printf("\nTask test completed"); 
}
#undef main
int main()
{
    StringCreateTest();
    StringLengthTest();
    TaskTest();
}
