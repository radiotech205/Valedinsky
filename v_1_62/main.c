#include <stdio.h>
#include <stdlib.h>
int mullCnt;
int PowerComputer(int xValue, int nValue, int arrBitSize);

int Binary(int n, int *arrBit, int arrBitSize)
{
    int mask = 1;
    int i = 0;
    for(i = 0; i < arrBitSize; i++)
    {
        if(n & mask)
            arrBit[i] = 1;
        else
            arrBit[i] = 0;

        mask <<= 1;
    }
    return i;
}

int Power(int base, int power)
{
    int result = 1;
    for(int i = 1; i <= power; i++)
    {
        result *= base;
        mullCnt++;
    }
    return result;
}


int main(int argc, char *argv[])
{
    int xValue = (argc >= 2) ? atoi(argv[1]) : 0;
    int nValue = (argc >= 3) ? atoi(argv[2]) : 0;
    int arrBitSize = (argc >= 4) ? atoi(argv[3]) : 16;

    int result = PowerComputer(xValue, nValue, arrBitSize);

    printf("xValue = %i, nValue = %i, result = %i\n", xValue, nValue, result);
    printf("mullCnt = %i\n", mullCnt);


    printf("Hello World!\n");
    return 0;
}

int PowerComputer(int xValue, int nValue, int arrBitSize)
{

    int *arrBit = (int*)malloc(sizeof(int) * arrBitSize);
    int result = 1;

    Binary(nValue, arrBit, arrBitSize);

    for(int i = arrBitSize; i >= 0; i--)
    {
        //printf("%i ", arrBit[i]);
        if(arrBit[i])
        {
            int index = Power(2, i);
            result *= Power(xValue, index);
            mullCnt++;
        }
    }


    Binary(result, arrBit, arrBitSize);
//    for(int i = arrBitSize; i >= 0; i--)
//    {
//        printf("%i ", arrBit[i]);
//    }

//    printf("\n");
//    printf("mullCnt = %i\n", mullCnt);

    free(arrBit);

    return result;
}
