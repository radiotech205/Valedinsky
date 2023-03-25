/*1.41. Каждый элемент массива (кроме первого и последнего) заме-
нить на полусумму соседних элементов.*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

void SemiSum(double *arrX, int arrXCnt, double *arrY);

int main()
{
    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXCnt = NUM_MEMB;

    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        arrX[i] = (double)(rand()%10);
        printf("%lf ", arrX[i]);
    }
    printf("\n");
    double *arrY = (double*)malloc(sizeof(double) * NUM_MEMB);

    SemiSum(arrX, arrXCnt, arrY);

    printf("_____\n");
    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        printf("%lf ", arrY[i]);
    }
    printf("\n");

    printf("Hello World!\n");
    return 0;
}

void SemiSum(double *arrX, int arrXCnt, double *arrY)
{
    for(int i = 1; i < arrXCnt-1; i++)
        arrY[i] = (arrX[i-1] + arrX[i+1])/2.0;

    arrY[0] = arrX[0];
    arrY[arrXCnt-1] = arrX[arrXCnt-1];
}
