/*1.43. Определите значение и индекс минимального элемента массива.*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

int MinFounder(int *arrX, int arrXCnt, int *minValue);

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

    int minValue = 0;
    int minPos = MinFounder(arrX, arrXCnt, &minValue);


    printf("minPos = %i, minValue = %i\n", minPos, minValue);


    printf("Hello World!\n");
    return 0;
}
int MinFounder(int *arrX, int arrXCnt, int *minValue)
{
    int minPos = 0;
    *minValue = arrX[0];

    for(int i = 0; i < arrXCnt; i++)
    {
        if(*minValue > arrX[i])
        {
            *minValue = arrX[i];
            minPos = i;
        }
    }
    return minPos;
}
