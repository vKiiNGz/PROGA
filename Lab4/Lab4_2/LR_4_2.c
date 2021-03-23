#include "LR_4_2.h"
void ValidationInt(int *x)
{
	while(!scanf("%d", x))
	{
		printf("\nIncorrect input. Try again.\n");
		fflush(stdin);
	}
}
char *StringCreate (int SymbolCounter)
{
	int  i;
	char *String = (char*)malloc((SymbolCounter + 1) * sizeof(char));

	if (!String)
	{
		printf("Error");
		exit(1);
	}
	return(String);
}
int StringLength(char *String)
{
	int  i = 0;
	while(String[i] != '\0')
	{
		i++;
	}
	return(i);
}
char *StringIn(char *String, int *SymbolCounter, FILE *File)
{
	int i;
	char *StringHelp;
	bool Flag;
	*SymbolCounter = 0;
	StringHelp = StringCreate(150);
	fgets(StringHelp, 150, File);
	*SymbolCounter = StringLength(StringHelp);
	String = StringCreate(*SymbolCounter);
	for (i = 0; i < *SymbolCounter; i++)
	{
		String[i] = StringHelp[i];
	}
	String[*SymbolCounter + 1] = '\0';
	free(StringHelp);
	return String;
}
void *StringOut(char *String, int SymbolCounter)
{
	int i;
	for(i = 0; i < SymbolCounter; i++)
	{
		printf("%c", String[i]);
	}
	printf("\n");
}
int ValidationTask(char *String, int SymbolCounter)
{
    int i, CountClosePar = 0, CountOpenPar = 0;
    for(i = 0; i < SymbolCounter; i++)
	{
		if(String[i] == '(' || String[i] == '{' || String[i] == '[')
        {
            CountOpenPar++;
        }
        if(String[i] == ')' || String[i] == '}' || String[i] == ']')
        {
            CountClosePar++;
        }
        if (CountClosePar > CountOpenPar)
        {
            printf("Incorrect input\n");
            return 3;    
        }
	}
    if (CountOpenPar != CountClosePar)
    {
        printf("The balance of the parentheses is not met");
        return 2;    
    }
    return 0;
}
char *Task(char *String, int SymbolCounter)
{
    int i, CountClosePar = 0, CountOpenPar = 0;
    for(i = 0; i < SymbolCounter; i++)
    {
		if((String[i] == '(' || String[i] == '{' || String[i] == '[') && (CountOpenPar - CountClosePar) == 0)
        {
            CountOpenPar++;
        }
        else
        {
            if((String[i] == '(' || String[i] == '{' || String[i] == '[') && (CountOpenPar - CountClosePar) == 1)
            {
                String[i] = '[';
                CountOpenPar++;
            }
            else
            {
                if((String[i] == '(' || String[i] == '{' || String[i] == '[') && (CountOpenPar - CountClosePar) > 1)
                {
                    String[i] = '{';
                    CountOpenPar++;
                }
                else
                {
                    if((String[i] == ')' || String[i] == '}' || String[i] == ']') && (CountOpenPar - CountClosePar) == 1)
                     {
                        CountClosePar++;
                     }
                    else
                    {
                        if((String[i] == ')' || String[i] == '}' || String[i] == ']') && (CountOpenPar - CountClosePar) == 2)
                        {
                            String[i] = ']';
                            CountClosePar++;
                        }
                        else
                        {
                            if((String[i] == ')' || String[i] == '}' || String[i] == ']') && (CountOpenPar - CountClosePar) > 1)
                            {
                                String[i] = '}';
                                CountClosePar++;
                            }
                        }
                    }
                }
            }
        }
	}
    return String;
}
int main()
{
    int SymbolCounter, i; 
    char *String;
    FILE *File;
    char Name[] = "input.txt";
    if((File = fopen(Name, "r")) == NULL)
    {
        printf("Could not open file");
        return 1;
    }
    else
    {
        String = StringIn(String, &SymbolCounter, File);
    }
    if(ValidationTask(String, SymbolCounter) == 0)
    {
    String = Task(String, SymbolCounter);    
    StringOut(String, SymbolCounter);
    }
    fclose(File);
    return 0;
}