#include "LR_5_3.h"
#include <assert.h>
void del_leading_zeroTest()
{
    T_num_s a = "007";
    del_leading_zero(a);
    assert(a == "7");
    printf("\ndel_leading_zero test completed");
}
void less_for_big_intTest()
{
    T_num_s a = "7";
    T_num_s b = "87";
    assert(less_for_big_int(a,b) == true);
    a = "7";
    b = "8";
    assert(less_for_big_int(a,b) == true);
    a = "007";
    b = "08";
    assert(less_for_big_int(a,b) == true);
    printf("\nless_for_big_int test completed");
}
void inc_big_intTest()
{
    T_num_s a = "7";
    inc_big_int(a);
    assert(a == "8");
    printf("\ninc_big_int test completed");
}
void reduce_big_intTest()
{
    T_num_s a = "7";
    T_num_s b = "2";
    reduce_big_int(a, b);
    assert(a == "5");
    printf("\nreduce_big_int test completed");
}
void div_big_intTest()
{
    T_num_s a = "8";
    T_num_s b = "2";
    T_num_s c;
    c = div_big_int(a,b);
    assert(c == "4");
    printf("\ndiv_big_int test completed"); 
}
void IntToStringTest()
{
    int x = 4;
    string c = IntToString(x);
    assert(c == "4");
    printf("\nIntToString test completed");

}
#undef main

int main()
{
    del_leading_zeroTest();
    less_for_big_intTest();
    inc_big_intTest();
    reduce_big_intTest();
    div_big_intTest();
    IntToStringTest();
    return 0;
}