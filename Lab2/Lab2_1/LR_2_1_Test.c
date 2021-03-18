#include "LR_2_1.h"
#include <stdio.h>
#include <assert.h>
#include <float.h>

void ConvertUSDBTest()
{
    double x = 9.0;
    assert( (ConvertUSDB(&x) - 9.0 * 0.385653683) < 0.0001);
    printf("\nConvertUSDB test completed");
}
void ConvertEURBTest()
{
    double x = 9.0;
    assert( (ConvertEURB(&x) - 9.0 * 0.323834197) < 0.0001);
    printf("\nConvertEURB test completed");
}
void ConvertRUBBTest()
{
    double x = 9.0;
    assert( (ConvertRUBB(&x) - 9.0 * 29.06976744) < 0.0001);
    printf("\nConvertRUBB test completed");
}
void ConvertUSDSTest()
{
    double x = 9.0;
    assert( (ConvertUSDS(&x) - 9.0 * 0.384319754) < 0.0001);
    printf("\nConvertUSDS test completed");
}
void ConvertEURSTest()
{
    double x = 9.0;
    assert( (ConvertEURS(&x) - 9.0 * 0.321853878) < 0.0001);
    printf("\nConvertEURS test completed");
}
void ConvertRUBSTest()
{
    double x = 9.0;
    assert( (ConvertRUBS(&x) - 9.0 * 28.08988764) < 0.0001);
    printf("\nConvertRUBS test completed");
}
void ConvertUSDNTest()
{
    double x = 9.0;
    assert( (ConvertUSDN(&x) - 9.0 / 0.38583224) < 0.0001);
    printf("\nConvertUSDN test completed");
}
void ConvertEURNTest()
{
    double x = 9.0;
    assert( (ConvertEURN(&x) - 9.0 / 0.32364554) < 0.0001);
    printf("\nConvertEURN test completed");
}
void ConvertRUBNTest()
{
    double x = 9.0;
    assert( (ConvertRUBN(&x) - 9.0 / 28.137310) < 0.0001);
    printf("\nConvertRUBN test completed");
}
#undef main

int main()
{
    ConvertUSDBTest();
    ConvertEURBTest();
    ConvertRUBBTest();
    ConvertUSDSTest();
    ConvertEURSTest();
    ConvertRUBSTest();
    ConvertUSDNTest();
    ConvertEURNTest();
    ConvertRUBNTest();
    return 0;
}