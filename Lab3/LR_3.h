#ifndef LR_3_H
#define LR_3_H
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

void ValidationInt(int *x);
void ValidationLong(long *x);
long **MatrixIn(int Rows, int Columns);
long **MatrixCreate (int Rows, int Columns);
int *ArrayCreate (int Rows);
void Sort(long **Matrix, int Rows, int Columns);
long **MatrixTranspose(long **Matrix, int *Rows, int *Columns);
int Task(long **Matrix, int Rows, int Columns);
#endif