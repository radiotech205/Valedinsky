/*1.52. Пусть элементы массива не убывают. Требуется бинарным по-
иском (методом деления пополам) определить принадлежит ли массиву
заданный элемент x .*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_MEMB    32

int Search(double *arrX, int arrXSize, double xValue);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXSize = NUM_MEMB;

    double xValue = atof(argv[1]);

    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        arrX[i] = (double)(rand()%3 + i);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    int result = Search(arrX, arrXSize, xValue);
    printf("xValue = %lf, result = %i\n", xValue, result);

    printf("Hello World!\n");
    return 0;
}


int Search(double *arrX, int arrXSize, double xValue)
{
    int result = 0;
    int left, right, mid;

    if((xValue < arrX[0]) || (xValue > arrX[arrXSize-1]))
        return 0;

    left = 0;
    right = arrXSize-1;

    while((right-left) > 1)
    {
        mid = (left + right)/2;
        if(xValue == arrX[mid])
            return 1;
        if(xValue > arrX[mid])
            left = mid;
        else
            right = mid;
    }

    if(xValue == arrX[right])
        result = 1;
    else
        result = 0;

    return result;
}
