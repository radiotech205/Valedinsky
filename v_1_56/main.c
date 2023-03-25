/*1.56. Даны два неубывающих массива. Реализуйте функцию, строя-
щую третий неубывающий массив, который является объединением пер-
вых двух (т.е. содержит все элементы двух исходных массивов).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Merge(double const *arrX1, double const *arrX2, double *arrX3, int arrX1Size, int arrX2Size);
int Search(double const *arrX, int arrXSize, double xValue, int *xPosition);
int Insert(double *arrX, int arrXSize, double xValue);


#define NUM_MEMB    32
int main()
{
    double *arrX1 = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrX1Size = NUM_MEMB;
    printf("arrX1:\n");
    for(int i = 0; i < arrX1Size; i++)
    {
        arrX1[i] = (double)(rand()%2 + i);
        printf("%4.1lf ", arrX1[i]);
    }
    printf("\n");

    double *arrX2 = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrX2Size = NUM_MEMB;
    printf("arrX2:\n");
    for(int i = 0; i < arrX2Size; i++)
    {
        arrX2[i] = (double)(rand()%2 + i);
        printf("%4.1lf ", arrX2[i]);
    }
    printf("\n");

    double *arrX3 = (double*)malloc(sizeof(double) * (arrX1Size + arrX2Size));

    int arrX3Size = Merge(arrX1, arrX2, arrX3, arrX1Size, arrX2Size);

    printf("arrX3:\n");
    for(int i = 0; i < arrX3Size; i++)
    {
        printf("%4.1lf ", arrX3[i]);
    }
    printf("\n");


    printf("Hello World!\n");
    return 0;
}

int Merge(double const *arrX1, double const *arrX2, double *arrX3, int arrX1Size, int arrX2Size)
{
    memcpy(arrX3, arrX1, sizeof(double) * arrX1Size);
    int arrX3Size = arrX1Size;
    for(int i = 0; i < arrX2Size; i++)
    {
        arrX3Size = Insert(arrX3, arrX3Size, arrX2[i]);
    }
    return arrX3Size;
}

int Search(double const *arrX, int arrXSize, double xValue, int *xPosition)
{
    int result = 0;
    int left, right, mid;

    if((xValue < arrX[0]))
    {
        *xPosition = 0;
        return 0;
    }
    if(xValue > arrX[arrXSize-1])
    {
        *xPosition = arrXSize;
        return 0;
    }

    left = 0;
    right = arrXSize-1;

    while((right-left) > 1)
    {
        mid = (left + right)/2;
        if(xValue == arrX[mid])
        {
            *xPosition = mid;
            return 1;
        }
        if(xValue > arrX[mid])
            left = mid;
        else
            right = mid;
    }

    //printf("l = %i, m = %i, r = %i\n", left, mid, right);
    if(xValue == arrX[right])
    {
        result = 1;
        *xPosition = right;
    }
    else
    {
        result = 0;
        *xPosition = right;
    }

    return result;
}

int Insert(double *arrX, int arrXSize, double xValue)
{
    int position = 0;
    Search(arrX, arrXSize, xValue, &position);


    for(int j = arrXSize; j > position; j--)
    {
        arrX[j] = arrX[j-1];
    }
    arrX[position] = xValue;
    return arrXSize + 1;

}
