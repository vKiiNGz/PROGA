#include "LR_3.H"
#include <assert.h>

void MatrixCreateTest ()
{   
    int Rows = 1, Columns = 1;
    long **M;
    M = MatrixCreate(Rows, Columns);
    assert(M != NULL);
    printf("\nMatrixCreate test completed");
}
void ArrayCreateTest()
{
    int Rows = 1;
    int *A;
    A = ArrayCreate(Rows);
    assert(A != NULL);  
    printf("\nArrayCreate test completed");  
}
void SortTest()
{
    int Rows = 2, Columns = 2;
    long **Matrix;
    Matrix = MatrixCreate(Rows, Columns);
    Matrix[0][0] = 0;
    Matrix[0][1] = 1;
    Matrix[1][0] = 1;
    Matrix[1][1] = 1;
    Sort(Matrix, Rows, Columns);
    assert((Matrix[0][0] == 1)&&(Matrix[0][1] == 1)&&(Matrix[1][0] == 0)&&(Matrix[1][1] == 1));
    printf("\nSort test completed");
}
void TaskTest()
{
    int Rows = 3, Columns = 3;
    long **Matrix;
    Matrix = MatrixCreate(Rows, Columns);
    Matrix[0][0] = 9;
    Matrix[0][1] = 8;
    Matrix[0][2] = 7;
    Matrix[1][0] = 6;
    Matrix[1][1] = 5;
    Matrix[1][2] = 4;
    Matrix[2][0] = 3;
    Matrix[2][1] = 2;
    Matrix[2][2] = 1;
    assert(Task(Matrix, Rows, Columns) == 2);
    printf("\nTask test completed");
}
#undef main

int main()
{
    MatrixCreateTest();
    ArrayCreateTest();
    SortTest();
    TaskTest();
    return 0;
}