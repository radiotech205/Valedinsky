/*1.37. Определите симметричны ли значения элементов массива?*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

int IsSymmetry(int *arrX, int arrXCnt);

int main()
{
    int *arrX = (int*)malloc(sizeof(int) * NUM_MEMB);
    int arrXCnt = NUM_MEMB;

    for(int i = 0; i < arrXCnt/*/2*/; i++)
    {
        arrX[i] = rand()%10;
//        arrX[arrXCnt - 1 - i] = arrX[i];
    }

    int isSym = IsSymmetry(arrX, arrXCnt);
    printf("isSym = %i\n", isSym);

    printf("Hello World!\n");
    return 0;
}

int IsSymmetry(int *arrX, int arrXCnt)
{
    int result = 0;
    int cnt = 0;
    for(int i = 0; i < arrXCnt/2; i++)
    {
        if(arrX[i] == arrX[arrXCnt - 1 - i])
            cnt++;
    }

    if(cnt == arrXCnt/2)
        result = 1;

    return result;
}
