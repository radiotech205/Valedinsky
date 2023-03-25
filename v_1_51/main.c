/*1.51. Требуется заменить каждый отрицательный элемент исходного
массива на три элемента, равных его абсолютной величине.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_MEMB    (32*3)

void InterchangeAndInsert(double *arrX, int *arrXSize, int insertPos, double insertVal, int times);
void DeleteAndMove(double *arr, int *arrSize, int deletePos);
void Computer(double *arrX, int *arrXSize);


int main()
{
    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXSize = NUM_MEMB/3;



    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        arrX[i] = (double)((rand() - RAND_MAX/2)%10);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    //InterchangeAndInsert(arrX, &arrXSize, 2, 10.0, 3);
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

void InterchangeAndInsert(double *arrX, int *arrXSize, int insertPos, double insertVal, int times)
{
    for(int j = 0; j < times; j++)
    {
        for(int i = *arrXSize; i > insertPos; i--)
        {
            arrX[i] = arrX[i-1];
        }
        arrX[insertPos] = insertVal;
        (*arrXSize)++;
    }
}

void DeleteAndMove(double *arr, int *arrSize, int deletePos)
{
    for(int i = deletePos; i < *arrSize-1; i++)
        arr[i] = arr[i + 1];
    (*arrSize)--;
}

void Computer(double *arrX, int *arrXSize)
{
    for(int i = 0; i < *arrXSize; i++)
    {
        if(arrX[i] < 0)
        {
            InterchangeAndInsert(&arrX[i], arrXSize, 1, fabs(arrX[i]), 3);
            DeleteAndMove(arrX, arrXSize, i);
            //i++;
            i = 0;
        }
    }
}
