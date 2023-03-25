/*1.40. Требуется циклически сдвинуть элементы массива на k позиций
вправо с затратой О(n) действий (n-длина массива).*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_MEMB    32

void ArrayInverter(int *arrX, int arrXCnt);
int move(int *mas, int n, int k);


int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }

    int kValue = atoi(argv[1]);

    int *arrX = (int*)malloc(sizeof(int) * NUM_MEMB);
    int arrXCnt = NUM_MEMB;

    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        arrX[i] = rand()%10;
        printf("%i ", arrX[i]);
    }
    printf("\n");

    move(arrX, arrXCnt, kValue);


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

int move(int *mas, int n, int k)
{
    k%=n;
    ArrayInverter (mas, n-k);
    ArrayInverter (mas+n-k, k);
    ArrayInverter (mas, n);
    return 1;
}
