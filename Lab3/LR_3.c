#include "LR_3.h"

void ValidationInt(int *x)
{
	while(!scanf("%d", x))
	{
		printf("\nIncorrect input. Try again.\n");
		fflush(stdin);
	}
}
void ValidationLong(long *x)
{
	while(!scanf("%li", x))
	{
		printf("\nIncorrect input. Try again.\n");
		fflush(stdin);
	}
}
long **MatrixIn(int Rows, int Columns)
{
	int  i, j;
	long **Matrix = (long**)malloc(Rows * sizeof(long*));

	if (!Matrix)
	{
		printf("Error");
		exit(1);
	}
	for (i= 0; i < Rows; i++)
	{
		Matrix[i] = (long*)malloc(Columns * sizeof(long));
		if (!Matrix[i])
		{
			printf("Error");
			exit(2);
		}
	}
	for (i = 0; i < Rows; i++)
	{
		for(j = 0; j < Columns; j++)
		{
			printf("Enter Matrix[%d][%d]: ", i, j);
			ValidationLong(&Matrix[i][j]);
		}
	}
	return(Matrix);
}
long **MatrixCreate (int Rows, int Columns)
{
	int  i, j;
	long **Matrix = (long**)malloc(Rows * sizeof(long*));

	if (!Matrix)
	{
		printf("Error");
		exit(1);
	}
	for (i= 0; i < Rows; i++)
	{
		Matrix[i] = (long*)malloc(Columns * sizeof(long));
		if (!Matrix[i])
		{
			printf("Error");
			exit(2);
		}
	}
	return(Matrix);
}
int *ArrayCreate (int Rows)
{
	int  i;
	int *Array = (int*)malloc(Rows * sizeof(int));

	if (!Array)
	{
		printf("Error");
		exit(1);
	}
	return(Array);
}
void Sort(long **Matrix, int Rows, int Columns)
{
	int i, j, t, Counter;
	long **MatrixHelp;
	int *Array;
	Array = ArrayCreate(Rows);
	for (i = 0; i < Rows; i++)
	{
		Array[i] = -1;
	}
	for (i = 0; i < Rows; i++)
	{
		for(j = 0; j < Columns; j++)
		{
			if(Matrix[i][j] == 0 && Array[i] == -1)
			{
				Array[i] = j;
			}
		}
		if(Array[i] == -1)
		{
			Array[i] = Columns - 1;
		}
	}
	MatrixHelp = MatrixCreate(Rows, Columns);
	Counter = 0;
	for (t = Columns - 1; t >= 0; t--)
	{
		for (i = 0; i < Rows; i++)
		{
			if(Array[i] == t)
			{
				for(j = 0; j < Columns; j++)
				{
					MatrixHelp[Counter][j] = Matrix[i][j];
				}
				Counter++;
			}
		}
	}

	for (i = 0; i < Rows; i++)
	{
		for(j = 0; j < Columns; j++)
		{
			Matrix[i][j] = MatrixHelp[i][j];
		}
	}
	for (i = 0; i < Rows; i++)
		{

			free(MatrixHelp[i]);
		}
	free(MatrixHelp);
	free(Array);
}
long **MatrixTranspose(long **Matrix, int *Rows, int *Columns)
{
	long **MatrixHelp;
	int i, j;
	if (*Rows > *Columns)
	{
		int x;
		MatrixHelp = MatrixIn(*Rows, *Columns);
		Matrix = MatrixCreate(*Columns, *Rows);
		for (i = 0; i < *Rows; i++)
		{
			for(j = 0; j < *Columns; j++)
			{
				Matrix[j][i] = MatrixHelp[i][j];
			}
		}
		x = *Rows;
		*Rows = *Columns;
		*Columns = x;
		for (i = 0; i < *Rows; i++)
		{
			free(MatrixHelp[i]);
		}
		free(MatrixHelp);
	}
	else
	{
		Matrix = MatrixIn(*Rows, *Columns);
	}
	return(Matrix);	
}
int Task(long **Matrix, int Rows, int Columns)
{
	int i, j, t, CounterRows, CounterColumns, Rang;
	bool NotZero;
	CounterRows = 0;
	CounterColumns = 0;
	while (CounterColumns < Columns && CounterRows < Rows)
	{   int x;
		if(Matrix[CounterRows][CounterColumns] != 0)
		{
			for (i = CounterRows + 1; i < Rows; i++)
			{
				x = Matrix[i][CounterColumns];
				Matrix[i][CounterColumns] = 0;
				for(j = CounterColumns + 1; j < Columns; j++)
				{
					Matrix[i][j] = Matrix[i][j] * Matrix[CounterRows][CounterColumns] - (Matrix[CounterRows][j]  * x);
				}
			}
			CounterRows++;
		}
		else
		{
			CounterColumns++;
		}
	}
	Rang = Rows;;
	for (i = 0; i < Rows; i++)
	{
		NotZero = true;
		for(j = 0; j < Columns; j++)
		{
			if(Matrix[i][j] != 0)
			{
				NotZero = false;
			}
		}
		if (NotZero)
		{
			Rang--;
		}
	}
	return(Rang);
}
int main()
{
	int Rows, Columns;
	long **Matrix;
	int *Array;
	printf("Enter the number of rows of the matrix: ");
	ValidationInt(&Rows);
	printf("Enter the number of columns of the matrix: ");
	ValidationInt(&Columns);
	Matrix = MatrixTranspose(Matrix, &Rows, &Columns);
	Sort(Matrix, Rows, Columns);
	printf("The rank of the matrix is %d", Task(Matrix, Rows, Columns));
	return 0;
}
