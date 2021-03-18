#include "LR_2_2.h"
#include <stdio.h>
#include <assert.h>
#include <float.h>

void DegreesToRadiansTest()
{
    double x = 12.0;
    assert( (DegreesToRadians(x) - 12.0 * PI / 180) < 0.000001);
    printf("\nDegreesToRadians test completed");    
}
void NormalDegreesTest()
{
    double x = -361.0;
    assert(NormalDegrees(x) - 359.0 < 0.0001);
    printf("\nNormalDegrees test completed");
}
void FactIterTest()
{
    assert(FactIter(5) == 120);
    printf("\nFactIter test completed");
}
void FactRecTest()
{
    assert(FactRec(5) == 120);
    printf("\nFactRec test completed");
}
#undef main

int main()
{
    DegreesToRadiansTest();
    NormalDegreesTest();
    FactIterTest();
    FactRecTest();
    return 0;
}