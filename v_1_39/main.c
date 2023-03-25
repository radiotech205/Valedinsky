/*1.39. Требуется циклически сдвинуть элементы массива на одну по-
зицию вправо.*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

void ArrayShifterR(int *arrX, int arrXCnt);

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

    ArrayShifterR(arrX, arrXCnt);

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

void ArrayShifterR(int *arrX, int arrXCnt)
{
    int temp = arrX[arrXCnt - 1];
    for(int i = arrXCnt - 1; i >= 0; i--)
        arrX[i+1] = arrX[i];

    arrX[0] = temp;
}
