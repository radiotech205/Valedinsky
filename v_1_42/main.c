/*1.42. Требуется сгруппировать положительные элементы массива в
его начале, а отрицательные — в конце с сохранением их порядка.*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

void NumbersGroupper(int *arrX, int arrXCnt, int *arrY);

int main()
{
    int *arrX = (int*)malloc(sizeof(int) * NUM_MEMB);
    int arrXCnt = NUM_MEMB;

    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        arrX[i] = (rand() - RAND_MAX/2)%10;
        printf("%i ", arrX[i]);
    }
    printf("\n");

    int *arrY = (int*)malloc(sizeof(int) * NUM_MEMB);

    NumbersGroupper(arrX, arrXCnt, arrY);

    printf("_____\n");
    printf("arrY:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        printf("%i ", arrY[i]);
    }
    printf("\n");

    printf("Hello World!\n");
    return 0;
}

void NumbersGroupper(int *arrX, int arrXCnt, int *arrY)
{
    int posCnt = 0;
    int negCnt = 0;

    for(int i = 0; i < arrXCnt; i++)
    {
        if(arrX[i] >= 0)
        {
            arrY[posCnt] = arrX[i];
            posCnt++;
        }
    }

    for(int i = 0; i < arrXCnt; i++)
    {
        if(arrX[i] < 0)
        {
            arrY[posCnt + negCnt] = arrX[i];
            negCnt++;
        }
    }
}
