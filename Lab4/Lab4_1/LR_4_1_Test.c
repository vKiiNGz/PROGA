#include "LR_4_1.h"
#include <assert.h>
void StringCreateTest()
{
    char *String;
    int SymbolCounter = 1;
    String = StringCreate(SymbolCounter);
    assert(String != NULL);
    printf("\nStringCreate test completed");
}
void StringAddTest()
{
    char *String;
    int SymbolCounter = 3;
    String = StringCreate(SymbolCounter);
    String[0] = 'a';
    String[1] = 'b';
    String[2] = 'c';
    String = StringAdd(String, &SymbolCounter, 'f', 0);
    assert(String[0] == 'f' && String[1] == 'a' && String[2] == 'b' && String[3] == 'c' && SymbolCounter == 4);
    printf("\nStringAdd test completed");
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
void CharUpCaseTest()
{
    char *String;
    int SymbolCounter = 3;
    String = StringCreate(SymbolCounter);
    String[0] = 'a';
    String[1] = 'b';
    String[2] = 'c';
    String = CharUpCase(String, SymbolCounter, 0);
    String = CharUpCase(String, SymbolCounter, 1);
    String = CharUpCase(String, SymbolCounter, 2);
    assert(String[0] == 'A' && String[1] == 'B' && String[2] == 'C');
    printf("\nCharUpCase test completed");
}
void TaskTest()
{
    char *String;
    int SymbolCounter = 5;
    String = StringCreate(SymbolCounter);
    String[0] = 'a';
    String[1] = ',';
    String[2] = 'b';
    String[3] = '.';
    String[4] = 'c';
    String = Task(String, &SymbolCounter);
    assert( (String[0] == 'a') && (String[1] == ',') && (String[2] == ' ') && (String[3] == 'b') && (String[4] == '.') && (String[5] == ' ') && (String[6] == 'C') );
    printf("\nTask test completed");    
}
#undef main

int main()
{
    StringCreateTest();
    StringAddTest();
    StringLengthTest();
    CharUpCaseTest();
    TaskTest();
}