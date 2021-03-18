#include "LR_2_1.h"
#include <stdio.h>
#include <float.h>

void StarLine()
{   
    int i;
    for(i = 0; i < 100; i++)
        {
            printf("*");
        }
        printf("\n");    
}
double MoneyIn()
{
    double x;
    printf("\nEnter the amount of money in Belarusian rubles: ");
    while(!scanf("%lf", &x) || (x < 0))
    {
        printf("\nIncorrect input. Try again.\n");
        fflush(stdin);
    }
    StarLine();
    return x;
}
double ConvertUSDB(double *Money)
{
    return(*Money * USDB);
}
double ConvertEURB(double *Money)
{
    return(*Money * EURB);
}
double ConvertRUBB(double *Money)
{
    return(*Money * RUBB);
}
double ConvertUSDS(double *Money)
{
    return(*Money * USDS);
}
double ConvertEURS(double *Money)
{
    return(*Money * EURS);
}
double ConvertRUBS(double *Money)
{
    return(*Money * RUBS);
}

double ConvertUSDN(double *Money)
{
    return(*Money/ USDN);
}
double ConvertEURN(double *Money)
{
    return(*Money/ EURN);
}
double ConvertRUBN(double *Money)
{
    return(*Money / RUBN);
}
void Convert(double *Money)
{
    printf("%lf BYR is %lf USD \n"
           "%lf BYR is %lf EUR \n" 
           "%lf BYR is %lf RYB \n",
           *Money, ConvertUSDS(Money), *Money, ConvertEURS(Money), *Money, ConvertRUBS(Money));
    StarLine();   
}
void SpreaDsheet()
{
    printf("Bank buys: \n"
           "%lf USD \n"
           "%lf EUR \n" 
           "%lf RYB \n"
           "Bank salls: \n"
           "%lf USD \n"
           "%lf EUR \n" 
           "%lf RYB \n",
           USDB, EURB, RUBB, USDS, EURS, RUBS);
    StarLine();    
}
void Profit()
{   
    double x = 1.0, U, E, R;
    U = ConvertUSDB(&x)-ConvertUSDS(&x);
    E = ConvertEURB(&x)-ConvertEURS(&x);
    R = ConvertRUBB(&x)-ConvertRUBS(&x);
    printf("%lf \n", R);
    printf("Profit will be: \n"
           "profit from 1 BYR through USD will be: %lf BYR \n"
           "profit from 1 BYR through EUR will be: %lf BYR \n"
           "profit from 1 BYR through RUB will be: %lf BYR \n",
           ConvertUSDN(&U), ConvertEURN(&E), ConvertRUBN(&R));
    if( ( ConvertUSDN(&U) > ConvertEURN(&E) ) && ( ConvertUSDN(&U) > ConvertRUBN(&R) ) )
    {
        printf("The maximum profit will be when converting through USD\n");
    }
    if( ( ConvertEURN(&E) > ConvertUSDN(&U) ) && ( ConvertEURN(&E) > ConvertRUBN(&R) ) )
    {
        printf("The maximum profit will be when converting through EUR\n");
    }
    if( ( ConvertRUBN(&R) > ConvertEURN(&E) ) && ( ConvertRUBN(&R) > ConvertUSDN(&U) ) )
    {
        printf("The maximum profit will be when converting through RUB\n");
    }
    StarLine();
} 
void SomeInformation()
{
    printf("The address: Ave. Dzerzhinsky, 18\n"
           "Contacts: \n"
           "Telephone: +375 17 218-84-31 \n"
           "Website: belarusbank.by \n");
    StarLine();
}
int Validation(short *x)
{
    while(!scanf("%hi", x))
    {
        printf("\nIncorrect input. Try again.\n");
        fflush(stdin);
    }
    return 0;
}
void Info()
{   
    printf("1 - Entry of the Monetary Amount in Belarusian Rubles.\n"
            "2 - Withdrawal Similar Amounts In US Dollars, Euro, Russian Rubles. \n"
            "3 - Conclusion of the Table of Currency Rates.\n"
            "4 - Calculation of profit from operations for each currency. Determination of the most advantageous currency for the bank for the transaction. \n"
            "5 - Some information about our bank. \n"
            "6 - Exit. \n");
    StarLine();
}

int main()
{
    short Action = -1, i;
    double Money;
    StarLine();
    while(Action != 0)
    {
        Info();
        printf("Enter yuor Action: ");
        Validation(&Action);
        printf("\n");
        StarLine();
        switch (Action)
        {
        case 1:
            Money = MoneyIn();
            break;
        case 2:
            Convert(&Money);
            break;   
        case 3:
            SpreaDsheet(&Money);
            break; 
        case 4:
            Profit();
            break;
        case 5:
            SomeInformation();
            break;
        
        default:
            break;
        }
    }
    getchar();
    return 0;
}