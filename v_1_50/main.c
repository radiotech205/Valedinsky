/*1.50. Требуется вставить между каждыми двумя положительными
элементами исходного массива их среднее арифметическое.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_MEMB    (32*2)

void InsertAndMove(double *arrX, int arrXSize, double value, int valuePos);
void Computer(double *arrX, int *arrXSize);

int main(void)
{

    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXSize = NUM_MEMB/2;


    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        arrX[i] = (double)(rand()%10);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    Computer(arrX, &arrXSize);

    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    printf("Hello World!\n");
    return 0;
}

void InsertAndMove(double *arrX, int arrXSize, double value, int valuePos)
{

    for(int i = arrXSize; i > valuePos; i--)
    {
        arrX[i] = arrX[i-1];
    }
    arrX[valuePos] = value;
}

void Computer(double *arrX, int *arrXSize)
{
    double avg = 0.0;
    for(int i = 0; i < *arrXSize-1; i++)
    {
        if((arrX[i] > 0.0) && (arrX[i+1] > 0))
        {
            avg = (arrX[i] + arrX[i+1]) / 2.0;
            InsertAndMove(&arrX[i], *arrXSize, avg, 1);
            (*arrXSize)++;
            i++;
        }
    }
}
