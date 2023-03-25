/*1.48. Введите с клавиатуры число x и продублируйте каждый элемент
массива, превосходящий x (т.е. вставьте рядом такой же элемент).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_MEMB    (32*2)

void InsertAndMove(double *arrX, int arrXSize, double value, int valuePos);
void Computer(double *arrX, int *arrXSize, double xValue);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXSize = NUM_MEMB/2;

    double xValue = atof(argv[1]);

    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        arrX[i] = (double)(rand()%10);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");


    Computer(arrX, &arrXSize, xValue);

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

void Computer(double *arrX, int *arrXSize, double xValue)
{
    double temp = 0.0;
    for(int i = 0; i < *arrXSize; i++)
    {
        temp = arrX[i];
        if(temp > xValue)
        {
           InsertAndMove(&arrX[i], *arrXSize, arrX[i], 1);
           (*arrXSize)++;
           i++;
        }
    }
}
