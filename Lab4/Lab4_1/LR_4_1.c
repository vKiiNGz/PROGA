#include "LR_4_1.h"

bool ValidationChar(char *x)
{
	if((*x - '0' >= 0) && (*x - '0' < 10))
	{
		return false;
	}
	else
	{
		return true;
	}
}
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
char *StringIn(char *String, int *SymbolCounter)
{
	int i;
	char *StringHelp;
	bool Flag;
	*SymbolCounter = 0;
	StringHelp = StringCreate(150);
	do
	{
		gets(StringHelp);
		*SymbolCounter = StringLength(StringHelp);
		for	(i = 0; i < *SymbolCounter; i++)
		{
			Flag = ValidationChar(&StringHelp[i]);
		}
		if(!Flag)
		{
			printf("\nIncorrect input. Try again.\n");
		}
	}
	while(!Flag);
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
char *StringAdd (char *String, int *SymbolCounter, char c, int Place)
{
	int  i;
	char *StringHelp;
	if(Place <= *SymbolCounter + 1)
	{
		StringHelp = StringCreate(*SymbolCounter + 1);
		for (i = 0; i < Place; i++)
		{
			StringHelp[i] = String[i];
		}
		StringHelp[Place] = c;
		for (i = Place + 1; i < *SymbolCounter + 1; i++)
		{
			StringHelp[i] = String[i-1];
		}
		(*SymbolCounter)++;
		return(StringHelp);
	}
	else
	{
		printf("Error");
	}
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
char *CharUpCase (char *String, int SymbolCounter, int Place)
{
	if(Place <= SymbolCounter)
	{
		String[Place] = String[Place] - 32;
		return(String);
	}
	else
	{
		printf("Error");
	}
}
char *Task(char *String, int *SymbolCounter)
{
	int i = 0;
	while(i < *SymbolCounter)
	{
		if( String[i] != ',' && String[i] != ':' && String[i] != ';' && String[i] != '.' && String[i] != '!' && String[i] != '?')
		{
			i++;
		}
		else
		{
			if(i+1 < *SymbolCounter)
			{
				if( (String[i] == ',' || String[i] == ':' || String[i] == ';') && (String[i+1] !=' ') )
				{
				String = StringAdd(String, SymbolCounter, ' ', i+1);
				i++;
				}
				if( (String[i] == ',' || String[i] == ':' || String[i] == ';') && (String[i+1] ==' ') )
				{
				i++;
				}
				if( (String[i] == '.' || String[i] == '?' || String[i] == '!') && (String[i+1] !=' ') )
				{
				String = StringAdd(String, SymbolCounter, ' ', i+1);
				}
			}
			if(i+2 < *SymbolCounter)
			{
				if( (String[i] == '.' || String[i] == '!' || String[i] == '?') && (String[i+1] ==' ') && ((String[i+2] >='a') && (String[i+2] <='z')) )
				{
				String = CharUpCase(String, *SymbolCounter, i+2);
				i++;
				}
				if( (String[i] == '.' || String[i] == '!' || String[i] == '?') && (String[i+1] ==' ') && !((String[i+2] >='a') && (String[i+2] <='z')) )
				{
				i++;
				}
			}
			if (i == *SymbolCounter)
			{
				if( String[i] == ',' || String[i] == ':' || String[i] == ';' || String[i] == '.' || String[i] == '!' || String[i] == '?')
				{
					String = StringAdd(String, SymbolCounter, ' ', i+1);
					i++;
				}
			}
			if (i+1 == *SymbolCounter)
			{
				if( (String[i] == ',' || String[i] == ':' || String[i] == ';' || String[i] == '.' || String[i] == '!' || String[i] == '?') && String[i+1] !=' ')
				{
					String = StringAdd(String, SymbolCounter, ' ', i+1);
					i++;
				}
			}

		}
	}
	return String;
}
int main()
{
	int SymbolCounter;
	char *String;
	String = StringIn(String, &SymbolCounter);
	String = Task(String, &SymbolCounter);
	StringOut(String, SymbolCounter);
    return 0;
}