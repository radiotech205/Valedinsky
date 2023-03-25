/*1.38. Требуется переставить элементы массива в обратном порядке.*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

void ArrayInverter(int *arrX, int arrXCnt);

int main()
{
    int *arrX = (int*)malloc(sizeof(int) * NUM_MEMB);
    int arrXCnt = NUM_MEMB;

    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        arrX[i] = rand()%10;
        printf("%i ", arrX[i]);
    }
    printf("\n");

    ArrayInverter(arrX, arrXCnt);

    printf("_____\n");
    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        printf("%i ", arrX[i]);
    }
    printf("\n");

    printf("Hello World!\n");
    return 0;
}

void ArrayInverter(int *arrX, int arrXCnt)
{
    int temp = 0;
    for(int i = 0; i < arrXCnt/2; i++)
    {
        temp = arrX[i];
        arrX[i] = arrX[arrXCnt - 1 - i];
        arrX[arrXCnt - 1 - i] = temp;
    }
}
