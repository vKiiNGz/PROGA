#ifndef LR_4_1_H
#define LR_4_1_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ValidationChar(char *x);
void ValidationInt(int *x);
char *StringCreate (int SymbolCounter);
char *StringIn(char *String, int *SymbolCounter);
void *StringOut(char *String, int SymbolCounter);
char *StringAdd (char *String, int *SymbolCounter, char c, int Place);
int StringLength(char *String);
char *CharUpCase (char *String, int SymbolCounter, int Place);
char *Task(char *String, int *SymbolCounter);
#endif