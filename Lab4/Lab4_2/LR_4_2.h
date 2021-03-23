#ifndef LR_4_2_H
#define LR_4_2_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ValidationInt(int *x);
char *StringCreate (int SymbolCounter);
int StringLength(char *String);
char *StringIn(char *String, int *SymbolCounter, FILE *File);
void *StringOut(char *String, int SymbolCounter);
int ValidationTask(char *String, int SymbolCounter);
char *Task(char *String, int SymbolCounter);

#endif