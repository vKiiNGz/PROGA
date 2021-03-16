#include "LR_1.h"
#include <stdio.h>

int Validation(int *x)
{
    while(!scanf("%d", x))
    {
        printf("\nIncorrect input. Try again.\n");
        fflush(stdin);
    }
    return 1;
}
int Task(int *x)
{
    int j;
    int i = 100;
    int counter = 1;

    while(i < 1000 && ((*x - counter) > 2))
    {    
        counter += 3;
        i++;
    }
    if(i == 1000)
    {
        printf("\nIntroduced to too large.\n");
        return -1;    
    }
    else
    {
        switch (*x - counter)
        {
        case 0:
            return(i / 100);
            break;
        case 1:
            return(i / 10 % 10);
            break;
        case 2:
            return(i % 10);
            break;
        default:
            break;
        } 
    } 
}
int main()
{
    int k, Answ;

    printf("Enter k: ");
    Validation(&k);
    Answ = Task(&k);
    if (Answ != -1)
    {
        printf("The digit under the number k in the given sequence is %d", Answ);
    }
    return 0;
}

