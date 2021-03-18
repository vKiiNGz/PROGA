#include "LR_2_2.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
double DegreesToRadians(double Degrees) 
{
    return (Degrees * PI / 180);
}
double NormalDegrees(double Angle) 
{
    if(Angle > 0) 
    {
        while(Angle >= 360) 
        {
            Angle -= 360;
        }
    }
    else 
    {
        while(Angle <= -360) 
        {
            Angle += 360;
        }
    }
    return Angle;
}
int FactIter(int n)
{
    int i, x = 1;
    for(i = 2; i <= n; i++)
    {
        x *= i;
    }
    return x;
}
int FactRec(int n)
{
    if(n > 1) 
    {

        return(FactRec(n - 1) * n);
    }
    else 
    {
        return(1);
    }
}
double ValidationDouble() {
    
    double E;
    char goodCheck;

    while(!scanf("%lf", &E) ||
          !scanf("%c", &goodCheck) || goodCheck != '\n') {
        printf("\nIncorrect input. Try again.\n");
        fflush(stdin);
    }
    return E;
}
int Iterative(double x, double E)
{
    double sinX, MySin, Numerator, Denominator, MyE;
    int Sign, Step, i, Number;
    Sign = 1;
    Step = 1;
    Number = 0;
    MySin = 0.0;
    sinX = sin(x);
    do
    {
        Numerator = 1;
        Denominator = FactIter(Step);
        for(i = 1; i <=Step; i++)
        {
            Numerator *= x;
        }
        MySin += Sign * Numerator / Denominator;
        Sign *= -1;
        Step += 2;    
        MyE = fabs(MySin - sinX);
        printf("\nResult of sin(x) function:            %lf\n"
               "Result on %3d step of decomposition:  %lf\n"
               "Calculation accuracy:                 %lf\n\n",
                sinX, Number, MySin, MyE);
        Number++;
    } while (MyE > E);    
    return(Number);
}
int Recursion(double x, double E)
{
    double sinX, MySin, Numerator, Denominator, MyE;
    int Sign, Step, i, Number;
    Sign = 1;
    Step = 1;
    Number = 0;
    MySin = 0.0;
    sinX = sin(x);
    do
    {
        
        Numerator = 1;
        Denominator = FactRec(Step);
        for(i = 1; i <=Step; i++)
        {
            Numerator *= x;
        }
        MySin += Sign * Numerator / Denominator;
        Sign *= -1;
        Step += 2;    
        MyE = fabs(MySin - sinX);
        printf("\nResult of sin(x) function:            %lf\n"
               "Result on %3d step of decomposition:  %lf\n"
               "Calculation accuracy:                 %lf\n\n",
                sinX, Number, MySin, MyE);
        Number++;
    } while (MyE > E);    
    return(Number);
}
int main()
{
    double x, E;
    printf("\nEnter the angle (in degrees): ");
    x = ValidationDouble();
    printf("\nEnter calculation precision (must be less than 1): ");
    E = ValidationDouble();
    while(E >= 1) {
        printf("Wrong input. Precision must be less than 1: ");
        E = ValidationDouble();
    }
    x = NormalDegrees(x);
    x = DegreesToRadians(x);
    printf("\nIterative");
    Iterative(x, E);
    printf("\nRecursion");
    Recursion(x, E);
    getchar();
    return 0;

}
