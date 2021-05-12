#ifndef LR_5_3_H
#define LR_5_3_H
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
typedef string T_num_s;

void del_leading_zero(T_num_s& a);
bool less_for_big_int(T_num_s a, T_num_s b);
void inc_big_int(T_num_s& a);
void reduce_big_int(T_num_s& minuend, const T_num_s& subtrahend);
T_num_s div_big_int(const T_num_s& a, const T_num_s& b);
bool* ReshetoErat();
string IntToString(int x);
#endif